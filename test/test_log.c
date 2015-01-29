
#include <stdio.h>
#include "../utils/log.h"

void main(){
  int status = write("remcache.log","hello world !");
  printf("%d\n",status);
}
