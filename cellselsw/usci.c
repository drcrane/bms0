#include <msp430.h>

#include "usci.h"

struct packet_context packet_ctx;
extern char * heap_buf;

int packet_send(size_t len) {
	packet_ctx.buf_end = heap_buf + len;
	packet_ctx.buf_ptr = heap_buf;
	packet_ctx.state = PACKET_STATE_SEND_SENDING;
	packet_ctx.checksum = 0;
	IE2 |= (UCA0TXIE);
	return 0;
}

int packet_receive() {
	packet_ctx.state = PACKET_STATE_RECEIVE_RECEIVING;
	packet_ctx.buf_start = heap_buf;
	packet_ctx.buf_end = heap_buf + PACKET_SIZE_MAX;
	packet_ctx.buf_ptr = heap_buf;
	packet_ctx.checksum = 0;
	IFG2 &= ~(UCA0RXIFG);
	IE2 |= (UCA0RXIE);
	return 0;
}

struct mcp23017_context mcp23017_ctx;

void mcp23017_write(uint8_t address, uint8_t byte1, uint8_t byte2, void (* callback)()) {
	UCB0I2CSA = MCP23017_ADDRESS;

	mcp23017_ctx.buf[0] = address;
	mcp23017_ctx.buf[1] = byte1;
	mcp23017_ctx.buf[2] = byte2;
	mcp23017_ctx.bufpos = 0;
	mcp23017_ctx.oper = MCP23017_OPER_WRITE;

	mcp23017_ctx.tmp[0] = byte1;
	mcp23017_ctx.tmp[1] = byte2;

	mcp23017_ctx.callback = callback;

	// start the interrupts going
	UCB0CTL1 |= UCTR | UCTXSTT;
}

struct i2c_context i2c_ctx;

void i2c_initialise() {
	UCB0CTL1 |= UCSWRST;
	UCB0CTL0 = UCMST | UCMODE_3 | UCSYNC;
	UCB0CTL1 |= UCSSEL_2;
	//UCB0CTL1 = UCSSEL_2 | UCSWRST;
	// This works, but is probably sub-optimal.
	UCB0BR0 = 80;
	UCB0BR1 = 0;
	UCB0I2CSA = 0x00;
	// GPIO already configured, does not change through the 
	// lifecycle of this firmware.
	//P1SEL |= BIT6 | BIT7;
	//P1SEL2 |= BIT6 | BIT7;
	UCB0CTL1 &= ~UCSWRST;

	UCB0STAT &= ~UCNACKIFG;
	IFG2 &= ~(UCB0TXIFG | UCB0RXIFG);

	UCB0I2CIE |= UCNACKIE;
	IE2 |= (UCB0TXIE | UCB0RXIE);
}

void i2c_write(uint8_t * addr, uint16_t count) {
	i2c_ctx.buf = addr;
	i2c_ctx.count = count;
	UCB0CTL1 |= UCTR | UCTXSTT;
}

void i2c_read(uint8_t * addr, uint16_t count) {
	i2c_ctx.buf = addr;
	i2c_ctx.count = count;
	UCB0CTL1 &= ~UCTR;
	UCB0CTL1 |= UCTXSTT;
	// Transmit Stop immediately after the first received byte
	// this may seem odd but setting UCTXSTP causes the stop to
	// occur at the next ACK. (Page 473 I2C master receiver mode
	// in MSP430 familty user guide).
	if (count == 1) {
		while (UCB0CTL1 & UCTXSTT) { __nop(); }
		UCB0CTL1 |= UCTXSTP;
	}
}

void USCI0TX_ISR(void) __attribute__ ( ( interrupt( USCIAB0TX_VECTOR ) ) );
void USCI0TX_ISR() {
	if (IFG2 & UCA0TXIFG) {
		// transmitting packet?
		int c;
		c = *packet_ctx.buf_ptr & 0xff;
		switch(packet_ctx.state) {
		case PACKET_STATE_SEND_SENDING:
			if (c == 0x1b || c == 0x1a) {
				packet_ctx.state = PACKET_STATE_SEND_ESCAPE;
				c = 0x1a;
				goto skip_end_checking;
			} else {
				packet_ctx.checksum += c;
			}
			break;
		case PACKET_STATE_SEND_ESCAPE:
			packet_ctx.checksum += c;
			c = c ^ 0x20;
			packet_ctx.state = PACKET_STATE_SEND_SENDING;
			break;
		case PACKET_STATE_SEND_CHECKSUM:
			c = packet_ctx.checksum & 0xff;
			packet_ctx.state = PACKET_STATE_SEND_END;
			if (c == 0x1a || c == 0x1b) {
				c = 0x1a;
				packet_ctx.state = PACKET_STATE_SEND_CHECKSUM_2;
			}
			goto skip_end_checking;
		case PACKET_STATE_SEND_CHECKSUM_2:
			c = packet_ctx.checksum & 0xff;
			c = c ^ 0x20;
			packet_ctx.state = PACKET_STATE_SEND_END;
			goto skip_end_checking;
		case PACKET_STATE_SEND_END:
			packet_ctx.state = PACKET_STATE_SEND_SUCCESS;
			IE2 &= ~(UCA0TXIE);
			c = 0x1b;
			goto skip_end_checking;
		}
		packet_ctx.buf_ptr++;
		if (packet_ctx.buf_ptr == packet_ctx.buf_end) {
			packet_ctx.state = PACKET_STATE_SEND_CHECKSUM;
		}
	skip_end_checking:
		UCA0TXBUF = c;
	} else
	if (IFG2 & UCB0TXIFG) {
		if (UCB0I2CSA == MCP23017_ADDRESS) {
			if (mcp23017_ctx.oper & MCP23017_OPER_WRITE) {
				if (mcp23017_ctx.bufpos == sizeof(mcp23017_ctx.buf)) {
					UCB0CTL1 |= UCTXSTP;
					IFG2 &= ~UCB0TXIFG;
					UCB0CTL1 |= UCTR | UCTXSTT;
					mcp23017_ctx.oper = MCP23017_OPER_VERFY_A;
				} else {
					UCB0TXBUF = mcp23017_ctx.buf[mcp23017_ctx.bufpos];
					mcp23017_ctx.bufpos++;
				}
			} else
			if (mcp23017_ctx.oper & MCP23017_OPER_VERFY_A) {
				UCB0TXBUF = mcp23017_ctx.buf[0];
				mcp23017_ctx.oper = MCP23017_OPER_VERFY_B;
			} else
			if (mcp23017_ctx.oper & MCP23017_OPER_VERFY_B) {
				UCB0CTL1 &= ~UCTR;
				UCB0CTL1 |= UCTXSTT;
				IFG2 &= ~UCB0TXIFG;
			}
		} else
		//if (UCB0CTL1 & UCTR) {
		{
			if (i2c_ctx.count == 0) {
				UCB0CTL1 |= UCTXSTP;
				IFG2 &= ~UCB0TXIFG;
				__bic_SR_register_on_exit(CPUOFF);
			} else {
				UCB0TXBUF = *i2c_ctx.buf;
				i2c_ctx.buf ++;
				i2c_ctx.count --;
			}
		}
		//}
	} else
	if (IFG2 & UCB0RXIFG) {
		if (UCB0I2CSA == MCP23017_ADDRESS) {
			if (mcp23017_ctx.oper & MCP23017_OPER_VERFY_B) {
				mcp23017_ctx.tmp[0] = UCB0RXBUF;
				UCB0CTL1 |= UCTXSTP;
				mcp23017_ctx.oper = MCP23017_OPER_VERFY_D;
			} else
			if (mcp23017_ctx.oper & MCP23017_OPER_VERFY_D) {
				mcp23017_ctx.tmp[1] = UCB0RXBUF;
				if (mcp23017_ctx.tmp[0] == mcp23017_ctx.buf[1] && mcp23017_ctx.tmp[1] == mcp23017_ctx.buf[2]) {
					mcp23017_ctx.oper = MCP23017_OPER_COMPLETE;
				} else {
					mcp23017_ctx.oper = MCP23017_OPER_ERROR;
					P3OUT &= ~BIT7;
				}
				__bic_SR_register_on_exit(CPUOFF);
			}
		} else {
			*i2c_ctx.buf = UCB0RXBUF;
			i2c_ctx.buf ++;
			i2c_ctx.count --;
			if (i2c_ctx.count == 1) {
				UCB0CTL1 |= UCTXSTP;
			} else
			if (i2c_ctx.count == 0) {
				__bic_SR_register_on_exit(CPUOFF);
			}
		}
	}
}

extern volatile int uart_data;

void USCI0RX_ISR(void) __attribute__ ( ( interrupt( USCIAB0RX_VECTOR ) ) );
void USCI0RX_ISR() {
	if (IFG2 & UCA0RXIFG) {
		int c;
		int b;
		c = UCA0RXBUF;
		if (c == 0x1b) {
			c = *(packet_ctx.buf_ptr - 1);
			b = packet_ctx.checksum - c;
			if ((c & 0xff) == (b & 0xff)) {
				packet_ctx.state = PACKET_STATE_RECEIVE_SUCCESS;
				IE2 &= ~(UCA0RXIE);
				goto valid_checksum_exit;
			} else {
				packet_ctx.state = PACKET_STATE_RECEIVE_RECEIVING;
		valid_checksum_exit:
				packet_ctx.checksum = 0;
				packet_ctx.buf_ptr = packet_ctx.buf_start;
				return;
			}
		} else
		switch(packet_ctx.state) {
		case PACKET_STATE_RECEIVE_RECEIVING:
			if (c == 0x1a) {
				packet_ctx.state = PACKET_STATE_RECEIVE_ESCAPE;
				return;
			}
			break;
		case PACKET_STATE_RECEIVE_ESCAPE:
			c = c ^ 0x20;
			packet_ctx.state = PACKET_STATE_RECEIVE_RECEIVING;
			break;
		}
		packet_ctx.checksum += c;
		*packet_ctx.buf_ptr = c;
		packet_ctx.buf_ptr++;
		if (packet_ctx.buf_ptr > packet_ctx.buf_end) {
			packet_ctx.buf_ptr = packet_ctx.buf_start;
		}
	} else
	if (UCB0STAT & UCNACKIFG) {
		if (UCB0I2CSA == MCP23017_ADDRESS) {
			mcp23017_ctx.oper = MCP23017_OPER_ERROR;
			// Put MCP23017 into reset!
			P3OUT &= ~(BIT7);
		}
		// Manual says that the master is expected to issue a stop condition in the case of a NACK
		// will not matter in the case of the MCP23017 as we have just, rather rudely, reset it.
		UCB0CTL1 |= UCTXSTP;
		UCB0STAT &= ~UCNACKIFG;
		__bic_SR_register_on_exit(CPUOFF);
	} 
}

