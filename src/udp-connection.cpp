#include <stdio.h>
#include "udp-connection.h"

UDPConnection::UDPConnection() : servaddr {0}, cliaddr{0}{
	sockfd = -1;
	addrlen = sizeof(struct sockaddr_in);
	i = 0;
	printf("Generic connection created\n");
}

int UDPConnection::start() {
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("can't open datagram socket");
		return -1;
	}

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (onSocketCreated() < 0) {
		perror("error in OnSocketCreated\n");
		return -1;
	}

	int loopReturn = 1;
	while (loopReturn == 1) {
		loopReturn = onLoop();
	}

	return loopReturn;
}

int UDPConnection::onSocketCreated() {
	return 1;
}

void UDPConnection::dumpInfo() {
	printf("sockfd: %i addrlen: %i\n", sockfd, addrlen);
}

UDPConnection::~UDPConnection() {
	printf("Generic connection destroyed\n");
}