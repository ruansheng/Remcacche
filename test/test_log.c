
#include <stdio.h>
#include "../utils/log.h"

int main(){
	  int status = r_write("remcache.log","hello world !");
	  printf("%d\n",status);
	  return 0;
}
