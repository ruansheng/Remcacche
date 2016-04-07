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
    char *key;
    char *content;
    int ttl;
    struct Node *pre;
    struct Node *next;
} Node;

/**
* Dict
*/
typedef struct {
    long int total; /* key count */
    Node **nodes;
} Dict;

Dict * initDict();
char * set(List *list, char *key);
char * get(List *list, char *key);
int del(List *list, char *key, char *content);