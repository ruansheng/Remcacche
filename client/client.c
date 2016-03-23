#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "client.h"

int handle(int fd);
 
int main(void) {
  struct sockaddr_in addr;
 
  printf("welcome to echo client\n");

  int nsd = socket(AF_INET, SOCK_STREAM, 0);

  if(nsd <= 0) {
      printf("create socket fail \n");
      exit(1);
  }

  memset(&addr,0,sizeof(addr));

  addr.sin_family = AF_INET;
  addr.sin_port = htons(CONNECTPORT);
  addr.sin_addr.s_addr=inet_addr(CONNECTADDR);

  if (connect(nsd, (struct sockaddr *)&addr, sizeof(struct sockaddr)) < 0) {
      printf("connect error \n");
      exit(1);
  }

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
      send(fd, sendl, strlen(sendl), 0);
      recv(fd, rev,strlen(rev), 0);
      printf("get data: %s \n", rev);
  }
 
  return 0;
}
