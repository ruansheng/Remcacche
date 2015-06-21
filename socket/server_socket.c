/*
 * server_socket.c
 *
 *  Created on: Jan 18, 2015
 *      Author: ruansheng
 */

#include "server_socket.h"



int start_socket()
{
    ///定义sockfd
    int server_sockfd = socket(AF_INET,SOCK_STREAM, 0);

    char * server_ip = BINDADDR;

    ///定义sockaddr_in
    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(BINDPORT);
    server_sockaddr.sin_addr.s_addr = inet_addr(server_ip);

    ///bind，成功返回0，出错返回-1
    if(bind(server_sockfd,(struct sockaddr *)&server_sockaddr,sizeof(server_sockaddr))==-1)
    {
        perror("bind");
        exit(1);
    }
	
    printf("bind success...\n");

    ///listen，成功返回0，出错返回-1
    if(listen(server_sockfd,QUEUE) == -1)
    {
        perror("listen");
        exit(1);
    }

    printf("listen success...\n");

    ///客户端套接字
    struct sockaddr_in client_addr;
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    client_addr.sin_port = htons(BINDPORT);
    char buffer[BUFFER_SIZE];

    socklen_t length = sizeof(client_addr);

    while(1)
    {
	///成功返回非负描述字，出错返回-1
    	int conn = accept(server_sockfd, (struct sockaddr*)&client_addr, &length);
   	if(conn<0)
    	{
        	perror("connect");
        	exit(1);
    	}

    	printf("accept success...\n");

        memset(buffer,0,sizeof(buffer));
        int len = recv(conn, buffer, sizeof(buffer),0);
        if(strcmp(buffer,"exit\n")==0)
            break;
	printf("data:%s\n",buffer);
        send(conn, buffer, len, 0);
	close(conn);
    }

    close(server_sockfd);
    return 0;
}
