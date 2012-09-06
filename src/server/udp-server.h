#ifndef _UDP_SERVER_H
#define _UDP_SERVER_H

#include "common.h"

class UDPServer : public UDPConnection {
protected:
	int datalen;
	char mesg[BUF_SIZE];

	virtual int onSocketCreated();
	virtual int onLoop();
	
public:
	UDPServer();
	virtual ~UDPServer();

	void explode();
};

#endif 
