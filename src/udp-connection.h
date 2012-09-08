#ifndef _UDP_CONNECTION
#define _UDP_CONNECTION

class UDPConnection : public Connection {
protected:
	int sockfd;
	struct sockaddr_in servaddr, cliaddr;
	unsigned int addrlen;

	int datalen;
	char mesg[BUF_SIZE];

	virtual int onSocketCreated();

public:
	UDPConnection();
	virtual ~UDPConnection();

	/* inherited from Connection */
	virtual int connect();
	virtual void setTimeout(int secs);
	virtual int send(const void *message, unsigned int length);
	virtual int blocking_receive(char* return_buf);

	virtual void dumpInfo();
};

#endif