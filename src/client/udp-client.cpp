#include <stdio.h>
#include <cstring>
#include "udp-client.h"

UDPClient::UDPClient() : UDPConnection() {
	printf("Client created\n");
	servaddr.sin_port   = htons(PORT);
}

int UDPClient::onLoop() {
	printf("onLoop begin\n");

	if (fgets(sendline, BUF_SIZE, stdin) == NULL) {
		return -1;
	}

	sendto(sockfd, sendline, strlen(sendline), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
	datalen = recvfrom(sockfd, recvline, BUF_SIZE, 0, NULL, NULL);
	recvline[datalen] = '\0'; /* null terminate */

	return 1;
}

UDPClient::~UDPClient() {
	printf("Client destroyed\n");
}

int main() {
	UDPClient client;
	if (client.start() < 0) {
		printf("Client terminated with error\n");
		return -1;
	}

	printf("Client terminated without error\n");
}