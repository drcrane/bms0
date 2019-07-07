#ifndef RELAYSM_H
#define RELAYSM_H

#include <stdint.h>

struct relay_context {
	void (* current_cb)();
	uint16_t state;
	uint16_t board_state;
	uint8_t port[2];
	uint8_t prech_port[2];
};

struct relay_context relay_ctx;

void relay_initialise();
void relay_process();

#endif // RELAYSM_H

