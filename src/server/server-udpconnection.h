#ifndef _SERVER_UDPCONNECTION_H
#define _SERVER_UDPCONNECTION_H

#include "common.h"
#include "udp-connection.h"

/* Server implementation of UDPConnection */
class ServerUDPConnection : public UDPConnection {
protected:
	virtual int onSocketCreated();
	
public:
	ServerUDPConnection();
	virtual ~ServerUDPConnection();
};

#endif 
