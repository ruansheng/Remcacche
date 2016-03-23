#include<stdio.h>
#include<string.h>

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

/**
* 获取输入的command
* command length <= 100
*/
char * getLineKey() {
	printf("ip:host>");
	char *key = (char *)malloc(sizeof(char) * 100);
	if(key == NULL) {
		exit(-1);
	}
	scanf("%s", key);
	return key;
}

int main(int argc, char **argv) {
	if(strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"--help") == 0) {
		usage();
	}
	
	return 0;
}