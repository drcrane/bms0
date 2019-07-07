#ifndef USCI_H
#define USCI_H

#include <stddef.h>
#include <stdint.h>

#define PACKET_SIZE_MAX 32

struct packet_context {
	volatile int state;
	char * buf_ptr;
	char * buf_start;
	char * buf_end;
	//char buf[PACKET_SIZE_MAX];
	unsigned int checksum;
};

extern struct packet_context packet_ctx;

#define PACKET_STATE_RECEIVE_RECEIVING 1
#define PACKET_STATE_RECEIVE_ESCAPE    2
#define PACKET_STATE_RECEIVE_SUCCESS   6

#define PACKET_STATE_SEND_SENDING  1
#define PACKET_STATE_SEND_ESCAPE   2
#define PACKET_STATE_SEND_CHECKSUM 3
#define PACKET_STATE_SEND_CHECKSUM_2 4
#define PACKET_STATE_SEND_END      5
#define PACKET_STATE_SEND_SUCCESS  7

int packet_send(size_t len);
int packet_receive();

struct mcp23017_context {
	uint16_t oper;
	uint16_t bufpos;
	uint8_t buf[3];
	uint8_t tmp[2];
	void (* callback)();
};

extern struct mcp23017_context mcp23017_ctx;

#define MCP23017_ADDRESS 0x20

#define MCP23017_OPER_IDLE        0

#define MCP23017_OPER_VERFY_A     0x10
#define MCP23017_OPER_VERFY_B     0x20
#define MCP23017_OPER_VERFY_C     0x40
#define MCP23017_OPER_VERFY_D     0x80

#define MCP23017_OPER_WRITE       0x100
#define MCP23017_OPER_COMPLETE    0x200
#define MCP23017_OPER_ERROR       0x400

void mcp23017_write(uint8_t address, uint8_t byte1, uint8_t byte2, void (* callback)());

struct i2c_context {
	uint8_t * buf;
	uint16_t count;
	uint8_t internal_buffer[8];
};

extern struct i2c_context i2c_ctx;

void i2c_initialise();
void i2c_write(uint8_t * addr, uint16_t count);
void i2c_read(uint8_t * addr, uint16_t count);

#endif // USCI_H

