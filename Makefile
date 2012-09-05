CLIENT_SOURCES := $(wildcard src/client/*.cpp) $(wildcard src/*.cpp)
CLIENT_OBJECTS := $(patsubst %.cpp,%.o,$(CLIENT_SOURCES))

SERVER_SOURCES := $(wildcard src/server/*.cpp) $(wildcard src/*.cpp)
SERVER_OBJECTS := $(patsubst %.cpp,%.o,$(SERVER_SOURCES))

all: client server

client: $(CLIENT_OBJECTS)
	$(CC) $(CLIENT_OBJECTS) -o bin/udp-client

server: $(SERVER_OBJECTS)
	$(CC) $(SERVER_OBJECTS) -o bin/udp-server
