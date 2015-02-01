/*
 * r_hash.c
 *
 *  Created on: Jan 31, 2015
 *      Author: root
 */

nclude <stdio.h>
#include "r_hash.h"

#define INDEX 128

type struct Node HashTable;

/**
* get index
*/
int get_index(char *key){
  if(key==NULL){
     return -0;
  }
  int total=0;
  while(*a!='\0'){
    total+=*a;
    a++;
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


void h_insert(HashTable *head，char *key,char *content,long int time_ttl=0){
  HashTable *node,*temp;
  if(head==NULL){
      return -1;
  }
  
  if(key==NULL){
    return -1;
  }

  if(content==NULL){
    return -1;
  }

  node=(HashTable *)malloc(sizeof(HashTable));
  if(node==NULL){
     return -1;
  }

  temp=head;
  for(int i=0;p!=NULL;i++){
    temp=temp->next;
  }

  node->key=key;
  node->content=content;
  node->time_ttl=time_ttl;
  node->next=NULL;
  temp=node;
  return 0;
}

void h_delete(char *key,HashTable *head){
   HashTable *node,*temp;
   if(head==NULL){
      return -1;
   }
   node=head;
   for(int i=0;node!=NULL;i++){
      if(*content==*(node->content)){
           temp=node;
           node->next=temp->next;
           break;
      }
   }
   free(temp);
   return 0;
}

HashTable* h_get(char *key,HashTable *head){
   HashTable *temp;
   if(head==NULL){
      return NULL;
   }
   temp=head;
   for(int i=0;temp!=NULL;i++){
      if(*key==*(temp->content)){
         break;
      }else{
         temp=temp->next;
      }
   }
   return temp;
}

