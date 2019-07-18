#include <msp430.h>
#include <stddef.h>
#include <stdint.h>

#include "usci.h"
#include "relaysm.h"
#include "timerfn.h"
#include "utilityfn.h"

struct relay_context relay_ctx;

void relay_initialise() {
	relay_ctx.state = 0;
}

#define RELAYFUSEDCHK_MAX_ZERO_VOLTS        0x10

#define RELAYFUSEDCHK_STATE_RELEASE_MCP23017   0
#define RELAYFUSEDCHK_STATE_RELEASE            1
#define RELAYFUSEDCHK_STATE_RELEASE_CHECK      2
#define RELAYFUSEDCHK_STATE_WAIT_A             3
#define RELAYFUSEDCHK_STATE_CHECK_CH1          4
#define RELAYFUSEDCHK_STATE_WAIT_B             5
#define RELAYFUSEDCHK_STATE_CHECK_CH2          6
#define RELAYFUSEDCHK_STATE_WAIT_C             7
#define RELAYFUSEDCHK_STATE_CHECK_CH1_AGAIN    8
#define RELAYFUSEDCHK_STATE_WAIT_D             9
#define RELAYFUSEDCHK_STATE_CHECK_CH2_AGAIN   10
#define RELAYFUSEDCHK_STATE_CHECK_VOLTAGES    11

#define RELAYFUSEDCHK_STATE_ERROR             12
#define RELAYFUSEDCHK_STATE_FINISHED          13

void relay_fusedcheck_process() {
	switch (relay_ctx.state) {
	case RELAYFUSEDCHK_STATE_RELEASE_MCP23017:
		relay_ctx.port[0] = 0;
		relay_ctx.port[1] = 0;
		if (!(P3OUT & BIT7)) {
			P3OUT |= BIT7;
			relay_ctx.state = RELAYFUSEDCHK_STATE_RELEASE;
			timer_callback(10, &relay_fusedcheck_process);
			relay_ctx.current_cb = NULL;
			//relay_ctx.state = RELAYFUSEDCHK_STATE_WAIT_B;
			break;
		}
		// FALLTHROUGH
	case RELAYFUSEDCHK_STATE_RELEASE:
		if (!timer_is_present(&relay_fusedcheck_process)) {
			mcp23017_cleariodir();
			relay_ctx.state = RELAYFUSEDCHK_STATE_RELEASE_CHECK;
			relay_ctx.current_cb = &relay_fusedcheck_process;
		}
		break;
	case RELAYFUSEDCHK_STATE_RELEASE_CHECK:
		if (mcp23017_ctx.oper == MCP23017_OPER_IDLE) {
			if (UCB0CTL1 & UCTXSTP) return;
			if (UCB0STAT & UCBBUSY) return;
			// SET VOLTAGE TO VSS
			P3OUT &= ~BIT1;
			P3OUT |= BIT0;
			UCB0I2CSA = MCP3422_ADDRESS;
			i2c_ctx.internal_buffer[0] = 0x18;
			i2c_write((uint8_t *)i2c_ctx.internal_buffer, 1);
			relay_ctx.state = RELAYFUSEDCHK_STATE_WAIT_A;
			timer_callback(500, &relay_fusedcheck_process);
			relay_ctx.current_cb = NULL;
		} else
		if (mcp23017_ctx.oper == MCP23017_OPER_ERROR) {
			goto relay_fusedcheck_process_error;
		}
		break;
	case RELAYFUSEDCHK_STATE_WAIT_A:
		if (!timer_is_present(&relay_fusedcheck_process)) {
			relay_ctx.current_cb = &relay_fusedcheck_process;
			relay_ctx.state = RELAYFUSEDCHK_STATE_CHECK_CH1;
			i2c_read((uint8_t *)i2c_ctx.internal_buffer, 3);
		}
		break;
	case RELAYFUSEDCHK_STATE_CHECK_CH1:
		if (i2c_ctx.count) { return; }
		relay_ctx.voltages[0] = Utility_uint16_beToLe(i2c_ctx.internal_buffer);
		relay_ctx.state = RELAYFUSEDCHK_STATE_WAIT_B;
		timer_callback(250, &relay_fusedcheck_process);
		relay_ctx.current_cb = NULL;
		break;
	case RELAYFUSEDCHK_STATE_WAIT_B:
		if (!timer_is_present(&relay_fusedcheck_process)) {
			relay_ctx.current_cb = &relay_fusedcheck_process;
			relay_ctx.state = RELAYFUSEDCHK_STATE_CHECK_CH2;
			i2c_read((uint8_t *)i2c_ctx.internal_buffer, 3);
		}
		break;
	case RELAYFUSEDCHK_STATE_CHECK_CH2:
		if (i2c_ctx.count) { return; }
		relay_ctx.voltages[1] = Utility_uint16_beToLe(i2c_ctx.internal_buffer);
		relay_ctx.state = RELAYFUSEDCHK_STATE_WAIT_C;
		// SET VOLTAGE TO 5V
		P3OUT &= ~BIT0;
		P3OUT |= BIT1;
		timer_callback(250, &relay_fusedcheck_process);
		relay_ctx.current_cb = NULL;
		i2c_ctx.internal_buffer[0] = 0x18;
		i2c_write((uint8_t *)i2c_ctx.internal_buffer, 1);
		break;
	case RELAYFUSEDCHK_STATE_WAIT_C:
		if (!timer_is_present(&relay_fusedcheck_process)) {
			relay_ctx.current_cb = &relay_fusedcheck_process;
			relay_ctx.state = RELAYFUSEDCHK_STATE_CHECK_CH2_AGAIN;
			i2c_read((uint8_t *)i2c_ctx.internal_buffer, 3);
		}
		break;
	case RELAYFUSEDCHK_STATE_CHECK_CH1_AGAIN:
		if (i2c_ctx.count) { return; }
		relay_ctx.voltages[2] = Utility_uint16_beToLe(i2c_ctx.internal_buffer);
		relay_ctx.state = RELAYFUSEDCHK_STATE_WAIT_D;
		timer_callback(250, &relay_fusedcheck_process);
		relay_ctx.current_cb = NULL;
		i2c_ctx.internal_buffer[0] = 0x38;
		i2c_write((uint8_t *)i2c_ctx.internal_buffer, 1);
		break;
	case RELAYFUSEDCHK_STATE_WAIT_D:
		if (!timer_is_present(&relay_fusedcheck_process)) {
			relay_ctx.current_cb = &relay_fusedcheck_process;
			relay_ctx.state = RELAYFUSEDCHK_STATE_CHECK_CH2_AGAIN;
			i2c_read((uint8_t *)i2c_ctx.internal_buffer, 3);
		}
		break;
	case RELAYFUSEDCHK_STATE_CHECK_CH2_AGAIN:
		if (i2c_ctx.count) { return; }
		relay_ctx.voltages[3] = Utility_uint16_beToLe(i2c_ctx.internal_buffer);
		relay_ctx.state = RELAYFUSEDCHK_STATE_CHECK_VOLTAGES;
		i2c_ctx.internal_buffer[0] = 0x08;
		i2c_write((uint8_t *)i2c_ctx.internal_buffer, 1);
		break;
	case RELAYFUSEDCHK_STATE_CHECK_VOLTAGES:
		{
			uint16_t tmp;
			tmp = 4;
			while (tmp --) {
				if (relay_ctx.voltages[tmp] > RELAYFUSEDCHK_MAX_ZERO_VOLTS) {
					goto relay_fusedcheck_process_error;
				}
			}
		}
		// POPCOUNT
		break;
	case RELAYFUSEDCHK_STATE_FINISHED:
		relay_ctx.current_cb = NULL;
		break;
	relay_fusedcheck_process_error:
	case RELAYFUSEDCHK_STATE_ERROR:
		relay_ctx.current_cb = NULL;
		break;
	}
}


