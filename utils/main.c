#include <stdio.h>
#include "hash.h"

typedef struct Node HashTable;

int main(){
   HashTable *head,*temp;
   
   head=h_init(); 
   
   int status=h_insert(head,3);
   printf("status=%d\n",status);
   printf("%ld\n",head->size);
//   display(head);
   return 0;
}
