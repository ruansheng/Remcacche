#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "client.h"

/**
* 使用帮助
*/
void usage() {
  fprintf(stderr,"Usage: ./client [options]\n");
  fprintf(stderr,"       ./client - (read config from stdin)\n");
  fprintf(stderr,"       ./client -h or --help\n");
  fprintf(stderr,"       ./client --host demo.client.com --port 7777\n");
  exit(1);
}

void connectServer(client *clio) {
  struct sockaddr_in addr;

  int nsd = socket(AF_INET, SOCK_STREAM, 0);

  if(nsd <= 0) {
     printf("create socket fail \n");
     exit(1);
  }

  clio->csock = nsd;

  memset(&addr,0,sizeof(addr));

  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr=inet_addr(clio->ip);
  addr.sin_port = htons(clio->port);

  if(connect(nsd, (struct sockaddr *)&addr, sizeof(struct sockaddr)) < 0) {
     printf("connect %s:%d error \n", clio->ip, clio->port);
     exit(1);
  }
}

/**
 * 解析参数
 */
client * parseArgv(client *clio, int argc, char **argv) {
  if(argc == 2 && strcmp(argv[1],"--help") == 0) {
    usage();
  }

  clio = (client *)malloc(sizeof(client));
  if(argc == 1) {
     clio->ip = (char *)malloc(sizeof(CONNECTADDR));
     strcpy(clio->ip, CONNECTADDR);
     clio->port = CONNECTPORT;
  }

  return clio;
}

/**
 * splitString
 */
void splitString(client *clio) {
    const char *c = clio->line;
    char cmd[3][1024];
    int i = 0;
    int j = 0;
    int total = 0;
    while(*c != '\0') {
        if(*c == ' ') {
            cmd[i][j] = '\0';
            i++;
            j = 0;
            c++;
            while(*c == ' ') {
                *c++;
            }
        } else {
            cmd[i][j] = *c;
            j++;
            c++;
            total++;
        }
    }

    char *str = (char *)malloc(total + 9); // *queue \n set \n name \n ruansheng
    if(str == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    char *tmp = str;
    strcpy(str, "*queue\n");
    str += 7;
    for(int s = 0; s <= i; s++) {
        strcpy(str, cmd[s]);
        str += strlen(cmd[s]);
        strcpy(str, "\n");
        str += 1;
    }
    clio->cmd = tmp;
}

/**
* 获取输入的command
* command length <= 100
*/
void getLineKey(client *clio) {
    printf("%s:%d>", clio->ip, clio->port);
    char line[1024];
    memset(line, '\0', 1014);
    fgets(line, 1024, stdin);
    clio->line = (char *)malloc(strlen(line));
    strcpy(clio->line, line);

    splitString(clio);
    sendCommand(clio);
}

/**
 * sendCommand
 */
void sendCommand(client *clio) {
    write(clio->csock, clio->cmd, strlen(clio->cmd) + 1);
}

/**
 * getResponse
 */
void getResponse(client *clio) {
    char buffer[1024];
    memset(buffer,0,sizeof(buffer));
    read(clio->csock, buffer, 1024);
    printf("%s \n", buffer);
}

/**
 * loop
 */
void loop(client *clio) {
  connectServer(clio);
  for(;;) {
     getLineKey(clio);
     sendCommand(clio);
     getResponse(clio);
  }
}

/**
 * close socket
 */
void closeSock(client *clio) {
   close(clio->csock);
   exit(0);
}

int main(int argc, char **argv) {
  client *clio;
  clio = parseArgv(clio, argc, argv);
  loop(clio);
  closeSock(clio);
  return 0;
}