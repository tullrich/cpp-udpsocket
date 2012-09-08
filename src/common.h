#ifndef _COMMON_H
#define _COMMON_H
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 12346
#define BUF_SIZE 4096
#define DEBUG true

class Connection {
public:
	virtual int connect() = 0;
	virtual void setTimeout(int secs) = 0;
	virtual int send(const void *message, unsigned int length) = 0;
	virtual int blocking_receive(char* return_buf) = 0;
};

class Protocol {
protected:
	Connection *c;
public:
	void setConnection(Connection *c) {
		this->c = c;
	};
	virtual int sendMessage(char* line, unsigned int t) = 0;
	virtual char* receiveMessage() = 0;
};

#include "udp-connection.h"

#endif