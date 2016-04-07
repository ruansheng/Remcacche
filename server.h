/*
 * server.c
 *
 *  Created on: Jan 17, 2015
 *      Author: ruansheng
 */

#include <stdio.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/ioctl.h>
#include<arpa/inet.h>
#include<libgen.h>
#include <sys/time.h>
#include<errno.h>
#include<stdarg.h>

#include "list.h"

#define PORT  6767
#define QUEUE_SIZE   20
#define BUFFER_SIZE 1024

/* exit */
#define EXIT(log) (perror(log),exit(1));

/* event */
typedef struct event {
    int port;
    int queue;
    int buffer_size;
    int server_sockfd;
    fd_set read_fds;
    fd_set temp_fds;
    List *list;  /* queue */
    Dict *dict;  /* string */
} event;

/* make server return protocol data*/
char * makeServerProtocolData(char *fmt, ...);

/* parse client send to server protocol data */
char * parseCommand(event *ev, char cmd[1024]);

/* string */
int setCommand(event *ev, char key[1024], char value[1024]);
char * getCommand(event *ev, char cmd[1024]);

/* queue */
int rpushCommand(event *ev, char key[1024], char value[1024]);
char * rpopCommand(event *ev, char cmd[1024]);
char * listCommand(event *ev, char cmd[1024]);
int qlenCommand(event *ev, char key[1024]);

/* sock */
void init_socket(event *ev);
void create_bind_socket(event *ev);
void listen_socket(event *ev);
void loop(event *ev);

/* log */
void sysLog(int level, const char *fmt, ...);