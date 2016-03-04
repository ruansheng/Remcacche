#include "client.h"

/**
* 
*/
/*
int start_client() {
    char ip[20]= {CONNECTADDR};
    int port= CONNECTPORT;
    int server_fd;
    struct sockaddr_in server_listen_addr;
    bzero(&server_listen_addr, sizeof(server_listen_addr));
    server_listen_addr.sin_family = AF_INET;
    server_listen_addr.sin_port = htons(port);
    inet_pton(AF_INET, CONNECTADDR, (void*)&server_listen_addr.sin_addr);
    server_fd = socket(AF_INET,SOCK_STREAM,0);
    int ret = connect(server_fd, (const struct sockaddr *)&server_listen_addr, sizeof(struct sockaddr));     
    //printf("server_fd=[%d] ret=[%d]\n", server_fd,ret);
    if(ret < 0) {
     	perror("error: socket connect!");       
    	exit(1);
    }
	while(1) {
	    char data[20] = {"good luck!\n"};
	    int num = send(server_fd, (void*)data, strlen(data), 0);
	    printf("send bytes[%d][%s]\n", num, data);	
	}
    close(server_fd);
    return 1;
}

int main() {
	start_client();
	return 0;
}
*/

#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
 
int handle(int fd);
 
int main(void) {
 
  int nsd;
  char buf[1024];
 
  char * myaddr = CONNECTADDR;
  struct sockaddr_in addr;
 
  printf("welcome to echo client\n");
  nsd = socket(AF_INET, SOCK_STREAM, 0);
  printf("connect start1 \n");
  //bzero(addr, sizeof(*addr));
  memset(&addr,0,sizeof(addr));
  printf("connect start2 \n");
  addr.sin_family = AF_INET;
  addr.sin_port = htons(CONNECTPORT);
  addr.sin_addr.s_addr=inet_addr(myaddr);
 
  printf("connect start3 \n");
  if (connect(nsd, (struct sockaddr *)&addr, sizeof(struct sockaddr)) < 0) {
    printf("connect error \n");
    return -1;
  }
 
  sleep(5);
  printf("handle start\n");
  handle(nsd);
  close(nsd);
  return EXIT_SUCCESS;
}
 
int handle(int fd) {
 
  char sendl[1024], rev[1024];
 
  int retn;
 
  for (;;) {
 
    memset(sendl,0,sizeof(sendl));
    memset(rev,0,sizeof(rev));
    if (fgets(sendl, 1024, stdin) == NULL) {
      break;
    }
    //
    printf("wirte start\n");
    write(fd, sendl, strlen(sendl));
    read(fd, rev,strlen(rev));
 
  }
 
  return 0;
}
