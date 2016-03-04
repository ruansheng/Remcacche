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
   char *content;
   struct List *pre;
   struct List *next;
};

/**
* List
*/
struct LIST {
   char *key;
   long int size;
   long int ttl;
   struct Node *left;
   struct Node *right;
};
