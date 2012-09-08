#include <stdio.h>
#include <cstring>
#include "stdout-server.h"
#include "gobackn-protocol.h"
#include "server-connection.h"

StdoutServer::StdoutServer(Protocol *p, Connection *c) {
	this->p = p;
	this->c = c;
}

void StdoutServer::start() {
	if (c->connect() < 0) {
		printf("Could not connect\n");
		return;
	}

	p->setConnection(c);

	char *mesg;
	while ((mesg = p->receiveMessage()) != NULL) {
		fputs(mesg,stdout);
		printf("\n");
	}

	printf("server stopping\n");

}

int main() {
	ServerConnection c;
	GoBackNProtocol p;

	StdoutServer server(&p, &c);
	server.start();
}	