#ifndef _STDOUT_SERVER_H
#define _STDOUT_SERVER_H

#include "common.h"

class StdoutServer {
private:
	Protocol *p;
	Connection *c;

public:
	StdoutServer(Protocol *p, Connection *c);
	void start();
};

#endif