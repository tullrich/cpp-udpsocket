#ifndef _UDP_CLIENT_H
#define _UDP_CLIENT_H

#include "common.h"

class ClientConnection : public UDPConnection {
public:
	ClientConnection();
	virtual ~ClientConnection();
};

#endif