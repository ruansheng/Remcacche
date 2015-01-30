/*
 * server.c
 *
 *  Created on: Jan 17, 2015
 *      Author: ruansheng
 */

#include <stdio.h>

//#include "socket/server_socket.h"
#include "utils/log.h"

/**
 * in function
 */
int main(){
//	start_socket();
	int status = r_write("remcache.log","hello world !");
	printf("%d\n",status);
    return 0;
}


