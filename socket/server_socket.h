/*
 * server_socket.h
 *
 *  Created on: Jan 18, 2015
 *      Author: ruansheng
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>

#define MYPORT  8889
#define QUEUE   20
#define BUFFER_SIZE 1024

int start_socket();
