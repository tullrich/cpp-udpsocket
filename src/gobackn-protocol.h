#ifndef _GOBACKN_PROTOCOL_H
#define _GOBACKN_PROTOCOL_H 
#include "common.h"

#define N 10
#define MAX_DATAGRAM_SIZE 256

/* c/c++ % computes remainder, not modulo, the formula below
	returns modulo. */
#define MOD(x, m) (x%m + m)%m
#define LAST_SENT_SEQN MOD(current_seqn - 1, N)


#define DATAGRAM_IDENT "DATA"
#define ACK_IDENT "ACK"



class GoBackNProtocol : public Protocol {
	private:
		char* window[N];
		char buffer[BUF_SIZE];
		int current_seqn;
		int last_acked_seqn;
		int expected_seqn;
		int last_sent_ackn;
		int num_active;

		void sendDatagram(char* p);
		bool canAddToWindow();
		void addToWindow(char b) ;
		bool windowEmpty();
		bool acceptAcks() ;
		bool listenForAck();
		bool parseValidAck(int *ack_seqn, char* data_in);
		bool parseValidDatagram(int *datagram_seqn, char *payload, char* data_in);
		void removeFromWindow(int mesg_seqn);
		void sendAck(int seqn);
		void resendWindow();

	public:
		GoBackNProtocol();
		virtual int sendMessage(char* line, unsigned int t);
		virtual char* receiveMessage();
};

typedef struct {
	char magic[5];
} Message;

#endif