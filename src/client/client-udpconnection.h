#ifndef _CLIENT_UDPCONNECTION_H
#define _CLIENT_UDPCONNECTION_H

#include "common.h"
#include "udp-connection.h"

/* client implementation of UDPConnection */
class ClientUDPConnection : public UDPConnection {
public:
	ClientUDPConnection();
	virtual ~ClientUDPConnection();
};

#endif