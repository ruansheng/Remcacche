/*
 * t_hash.h
 *
 *  Created on: Jan 31, 2015
 *      Author: root
 */
#include <stdio.h>

/**
* Node
*/
struct Node {
   char *key;
   char *content;
   long int time_ttl;
   long int size;
   struct Node *pre;
   struct Node *next;
};

/**
* HashTable
*/
struct HashTable {
   struct Node *node;
   struct HashTable *pre;
   struct HashTable *next;
};
~               
