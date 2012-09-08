#include <stdio.h>
#include <cstring>
#include "client-connection.h"

ClientConnection::ClientConnection() {
	printf("Client connection created\n");
	servaddr.sin_port   = htons(PORT);
}

ClientConnection::~ClientConnection() {
	printf("Client connection destroyed\n");
}