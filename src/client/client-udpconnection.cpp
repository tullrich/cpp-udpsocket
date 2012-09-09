#include <stdio.h>
#include <cstring>
#include "client-udpconnection.h"

ClientUDPConnection::ClientUDPConnection() {
	printf("Client connection created\n");
	servaddr.sin_port   = htons(PORT);
}

ClientUDPConnection::~ClientUDPConnection() {
	printf("Client connection destroyed\n");
}