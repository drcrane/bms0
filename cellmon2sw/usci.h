#ifndef USCI_H
#define USCI_H

#include <stddef.h>

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

#endif // USCI_H

