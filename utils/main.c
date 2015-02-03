#include <stdio.h>
#include "r_hash.h"

typedef struct Node HashTable;

void main(){
   HashTable *head,*temp;
   
   head=h_init(); 
   
   int status=h_insert(head,"name","ruansheng");
   printf("status=%d\n",status);
  
   display(head);
}
