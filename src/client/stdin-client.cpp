#include <stdio.h>
#include <cstring>
#include "stdin-client.h"
#include "gobackn-protocol.h"
#include "client-udpconnection.h"

StdinClient::StdinClient(Protocol *p, Connection *c) {
	this->p = p;
	this->c = c;
}

void StdinClient::start() {
	if (c->connect() < 0) {
		printf("Could not connect\n");
		return;
	}

	p->setConnection(c);

	while (printf("Input Mesg: ") && gets(sendline) != NULL) {
		p->sendMessage(sendline, strlen(sendline));
		printf("Application Layer: MESSAGE '%s' SENT\n", sendline);
	}

	printf("stdin returned NULL\n");
}

/* Run a StdinClient over a ClientUDPConnection using the GoBackNProtocol */
int main() {
	ClientUDPConnection c;
	GoBackNProtocol p;

	StdinClient client(&p, &c);
	client.start();
}