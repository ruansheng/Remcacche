/*
 * r_hash.c
 *
 *  Created on: Jan 31, 2015
 *      Author: root
 */

nclude <stdio.h>
#include "hash.h"

#define INDEX 128

type struct Node Node;

type struct HashTable HashTable;

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


void h_insert(HashTable *head，char *key,char *content,long int time_ttl){
  Node *node;
  if(head==NULL){
      return -1;
  }

}

void h_delete(char *key,HashTable *head){

}

void h_get(char *key,HashTable *head){

}

