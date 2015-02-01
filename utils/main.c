#include <stdio.h>
#include "r_hash.h"

typedef struct Node HashTable;

void main(){
   HashTable *head;
   int status=h_init(head); 
   printf("status:%d\n",status);
   printf("%s",head->content);
}
