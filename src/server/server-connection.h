#ifndef _SERVER_CONNECTION_H
#define _SERVER_CONNECTION_H

#include "common.h"

class ServerConnection : public UDPConnection {
protected:
	virtual int onSocketCreated();
	
public:
	ServerConnection();
	virtual ~ServerConnection();
};

#endif 
