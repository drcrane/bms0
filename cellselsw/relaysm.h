#ifndef RELAYSM_H
#define RELAYSM_H

#include <stdint.h>

struct relay_context {
	void (* current_cb)();
	uint16_t state;
	uint16_t board_state;
	uint8_t port[2];
	uint8_t prech_port[2];
	uint16_t voltages[4];
};

extern struct relay_context relay_ctx;

void relay_initialise();
void relay_fusedcheck_process();

#endif // RELAYSM_H

