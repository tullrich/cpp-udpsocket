#include <stdio.h>
#include <memory>
#include "udp-server.h"


UDPServer::UDPServer() : UDPConnection() {
	datalen = -1;
	servaddr.sin_port   = htons(PORT);
	printf("Server created\n");
}

int UDPServer::onSocketCreated() {
	if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
		perror("server: can't bind local address");
		return -1;
	}

	printf("server: binding success\n");
	return 0;
}

int UDPServer::onLoop() {
	datalen = recvfrom(sockfd, mesg, BUF_SIZE, 0, (struct sockaddr *)&cliaddr, &addrlen);
	fputs(mesg,stdout);
	sendto(sockfd, mesg, datalen, 0, (struct sockaddr *)&cliaddr, addrlen);

	return 1;
}

UDPServer::~UDPServer() {
	printf("Server destroyed\n");
}


void UDPServer::explode() {
	throw "test\n";
}

int main() {
	UDPServer server;
	if (server.start() < 0) {
		printf("Server terminated with error\n");
		return -1;
	}

	printf("Server terminated without error\n");
}	
