/*
 * t_hash.h
 *
 *  Created on: Jan 31, 2015
 *      Author: root
 */

/**
* Node
*/
typedef struct Node{
    char *content;
    struct Node *pre;
    struct Node *next;
} Node;

/**
* List
*/
typedef struct List {
    char *key;
    long int length;
    long int ttl;
    Node *left;
    Node *right;
    struct List *next;
} List;

List * init(List *list);
char * lpop(List *list, char *key);
char * rpop(List *list, char *key);
int lpush(List *list, char *key, char *content);
int rpush(List *list, char *key, char *content);
int llen(List *list, char *key);
void display(List *list, char *key);
