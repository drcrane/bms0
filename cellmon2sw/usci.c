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
	}
}

