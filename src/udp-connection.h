#ifndef _UDP_CONNECTION
#define _UDP_CONNECTION

#include <netinet/in.h>
#include <sys/socket.h>
#include "common.h"

class UDPConnection {
protected:
	int* i;
	int sockfd;
	struct sockaddr_in servaddr, cliaddr;
	unsigned int addrlen;

	virtual int onSocketCreated();
	virtual int onLoop() {};

public:
	UDPConnection();
	virtual ~UDPConnection();

	virtual void dumpInfo();
	virtual int start();
};

#endif