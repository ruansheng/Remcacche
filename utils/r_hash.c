/*
 * r_hash.c
 *
 *  Created on: Jan 31, 2015
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "r_hash.h"

#define INDEX 128

typedef struct Node HashTable;

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


int h_insert(HashTable *head,char *key,char *content){
  HashTable *node,*temp;
  
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

  char *temp_key=(char *)malloc(20);
  char *temp_content=(char *)malloc(20);
  strcpy(temp_key,key);
  strcpy(temp_content,content); 

  node->key=temp_key;
  node->content=temp_content;
  node->next=NULL;
  printf("content=%s\n",node->content);

  if(head==NULL){
      head=node;
  }
  
  printf("head content=%s",head->content);
/*
  temp=head;
  while(temp!=NULL){
    temp=temp->next;
  }

  node->key=key;
  node->content=content;
  node->next=NULL;
  printf("content=%s\n",node->content);
  temp->next=node;
  */ 
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
  for(temp=head->next;temp!=NULL;temp=temp->next){
     printf("content=%s\n",temp->content);
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

