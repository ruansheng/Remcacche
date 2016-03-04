/*
 * t_hash.h
 *
 *  Created on: Jan 31, 2015
 *      Author: root
 */
#include <stdio.h>

typedef struct NODE Node;
typedef struct LIST List;


/**
* Node
*/
struct NODE {
   int content;
   Node *pre;
   Node *next;
};

/**
* List
*/
struct LIST {
   char *key;
   long int length;
   long int ttl;
   Node *left;
   Node *right;
   List *next;
};

List * init(List *list);
int lpop(List *list, char *key);
int rpop(List *list, char *key);
int lpush(List *list, char *key, int content);
int rpush(List *list, char *key, int content);
int llen(List *list, char *key);
void display(List *list, char *key);
