#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <errno.h>

#define CONNECTADDR "127.0.0.1"
#define CONNECTPORT  6767

typedef struct client {
    char *ip;
    int port;
    int csock;
    char *line;
    char *cmd;
} client;

client *  parseArgv(client *clio, int argc, char **argv);

void connectServer(client *clio);

void loop(client *clio);

void getLineKey(client *clio);

void sendCommand(client *clio);

void getResponse(client *clio);

void closeSock(client *clio);
