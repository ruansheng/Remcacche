/**
* get index
*/
int get_index(char *key){
  if(key==NULL){
     return -1;
  }
  int total=0;
  while(*key!='\0'){
    total+=*key;
    key++;
  }
  int index=total%INDEX;
  return index;
}


/**
* init HashTable
*/
HashTable* h_init(){
  HashTable *head;
  head=(HashTable *)malloc(sizeof(HashTable));
  if(head==NULL){
    return NULL;
  }
  head->next=NULL;
  return head;
}

int h_insert(HashTable *head,long int size){
  HashTable *node,*temp=head;

  node=(HashTable *)malloc(sizeof(HashTable));
  if(node==NULL){
     return -1;
  }

  node->size=size;
  node->next=NULL;

  temp->next=node;
  
  printf("head size=%ld\n",node->size);
  
  return 0;
}

int h_delete(char *key,HashTable *head){
   HashTable *node,*temp;
   if(head==NULL){
      return -1;
   }
   node=head;
   while(node!=NULL){
      if(*key==*(node->key)){
           temp=node;
           node->next=temp->next;
           break;
      }
   }
   free(temp);
   return 0;
}

void display(HashTable *head){
  printf("%s\n",head->content);
  HashTable *temp;
  temp=head;
  for(temp=temp->next;temp!=NULL;temp=temp->next){
     printf("size=%ld\n",temp->size);
  }
}

HashTable* h_get(char *key,HashTable *head){
   HashTable *temp;
   if(head==NULL){
      return NULL;
   }
   temp=head;
   while(temp!=NULL){
      if(*key==*(temp->content)){
         break;
      }else{
         temp=temp->next;
      }
   }
   return temp;
}

