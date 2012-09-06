#ifndef _UDP_CLIENT_H
#define _UDP_CLIENT_H

#include "common.h"

class UDPClient : public UDPConnection {
protected:
	int datalen;
	char sendline[BUF_SIZE], recvline[BUF_SIZE + 1];
	

	virtual int onLoop();
public:
	UDPClient();
	virtual ~UDPClient();
};

#endif