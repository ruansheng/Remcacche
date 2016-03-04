/*
 * r_hash.c
 *
 *  Created on: Jan 31, 2015
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
* init
*/
List * init(List *list){
	list = (List *)malloc(sizeof(List));
	if(list == NULL) {
		return NULL;
	}
	list->length = 0;
	list->next = NULL;
	return list;
}

/**
* lpop
*/
int lpop(List *list, char *key){
	List *head = list;
	Node *node = NULL;
	Node *pnode = NULL;
    if(head->next == NULL){
       return 0;
    }
	int tmp = 0;
	
    head = head->next;
	while(head) {
		if(strcmp(head->key, key) == 0) {
			if(head->length > 0) {
				node = head->left;		
				tmp = node->content;
				
				head->length--;
				pnode = node->next;
				pnode->pre = NULL;
				head->left = pnode;
				free(node);
			}			
			break;
		}
		head = head->next;
	}
	
	return tmp;
}

/**
* rpop
*/
int rpop(List *list, char *key){
	List *head = list;
	Node *node = NULL;
	Node *pnode = NULL;
    if(head->next == NULL){
       return 0;
    }
	int tmp = 0;
	
    head = head->next;
	while(head) {
		if(strcmp(head->key, key) == 0) {
			if(head->length > 0) {
				node = head->right;		
				tmp = node->content;
				
				head->length--;
				pnode = node->pre;
				pnode->next = NULL;
				head->right = pnode;
				free(node);
			}			
			break;
		}
		head = head->next;
	}
	
	return tmp;
}

/**
* lpush
*/
int lpush(List *list, char *key, int content){
	List * head = NULL;
	List * tmp = NULL;
	List * this_tmp = NULL;
	List * end_tmp = NULL;
	List * new_list_item = NULL;
	Node * new_node = NULL;
	Node * node = NULL;
	
	head = list;

	if(head->next == NULL) {
		new_list_item = (List *)malloc(sizeof(List));
		if(new_list_item == NULL) {
			return -1;
		}
		
		new_list_item->key = key;
		new_list_item->length = 1;
		new_list_item->next = NULL;
		
		new_node = (Node *)malloc(sizeof(Node));
		if(new_node == NULL) {
			free(new_list_item);
			return -1;
		}
		new_node->content = content;
		new_node->pre = NULL;
		new_node->next = NULL;

		new_list_item->left = new_node;
		new_list_item->right = new_node;
		
		head->next = new_list_item;
		return 1;
	} else {
		tmp = head->next;
		int exists = 0;
		while(tmp) {
			if(strcmp(tmp->key, key) == 0) {
				exists = 1;
				this_tmp = tmp;    // 保存当前key所在list的节点地址
				break;
			}
			end_tmp = tmp;         // 保存最后一个节点地址
			tmp = tmp->next;
		}
		
		if(exists == 0) {
			this_tmp = (List *)malloc(sizeof(List));
			if(this_tmp == NULL) {
				return -1;
			}
		
			this_tmp->key = key;
			this_tmp->length = 1;
			this_tmp->next = NULL;
			
			new_node = (Node *)malloc(sizeof(Node));
			if(new_node == NULL) {
				free(this_tmp);
				return -1;
			}
			new_node->content = content;
			new_node->pre = NULL;
			new_node->next = NULL;
			
			this_tmp->left = new_node;
			this_tmp->right = new_node;	
		
			end_tmp->next = this_tmp;
		} else if(exists == 1) {
			new_node = (Node *)malloc(sizeof(Node));
			if(new_node == NULL) {
				return -1;
			}
			
			this_tmp->length++;
			
			node = this_tmp->left;
			
			new_node->content = content;
			new_node->pre = NULL;			
			new_node->next = node;
			node->pre = new_node;
		
			this_tmp->left = new_node;
		}
	}
	return 1;
}

/**
* rpush
*/
int rpush(List *list, char *key, int content){
	List * head = NULL;
	List * tmp = NULL;
	List * this_tmp = NULL;
	List * end_tmp = NULL;
	List * new_list_item = NULL;
	Node * new_node = NULL;
	Node * node = NULL;
	
	head = list;

	if(head->next == NULL) {
		new_list_item = (List *)malloc(sizeof(List));
		if(new_list_item == NULL) {
			return -1;
		}
		
		new_list_item->key = key;
		new_list_item->length = 1;
		new_list_item->next = NULL;
		
		new_node = (Node *)malloc(sizeof(Node));
		if(new_node == NULL) {
			free(new_list_item);
			return -1;
		}
		new_node->content = content;
		new_node->pre = NULL;
		new_node->next = NULL;

		new_list_item->left = new_node;
		new_list_item->right = new_node;
		
		head->next = new_list_item;
		return 1;
	} else {
		tmp = head->next;
		int exists = 0;
		while(tmp) {
			if(strcmp(tmp->key, key) == 0) {
				exists = 1;
				this_tmp = tmp;    // 保存当前key所在list的节点地址
				break;
			}
			end_tmp = tmp;         // 保存最后一个节点地址
			tmp = tmp->next;
		}
		
		if(exists == 0) {
			this_tmp = (List *)malloc(sizeof(List));
			if(this_tmp == NULL) {
				return -1;
			}
		
			this_tmp->key = key;
			this_tmp->length = 1;
			this_tmp->next = NULL;
			
			new_node = (Node *)malloc(sizeof(Node));
			if(new_node == NULL) {
				free(this_tmp);
				return -1;
			}
			new_node->content = content;
			new_node->pre = NULL;
			new_node->next = NULL;
			
			this_tmp->left = new_node;
			this_tmp->right = new_node;	
		
			end_tmp->next = this_tmp;
		} else if(exists == 1) {
			new_node = (Node *)malloc(sizeof(Node));
			if(new_node == NULL) {
				return -1;
			}
			
			this_tmp->length++;
			
			node = this_tmp->right;
			
			new_node->content = content;
			new_node->pre = node;			
			new_node->next = NULL;
			node->next = new_node;
		
			this_tmp->right = new_node;
		}
	}
	return 1;
}

/**
* llen
*/
int llen(List *list, char *key) {
	List * head = list;
	
    if(head->next == NULL){
       return 0;
    }
	
	int length = 0;
	head = head->next;
	while(head) {
		if(strcmp(head->key, key) == 0) {
			length = head->length;
			break;
		}
		
		head = head->next;
	}
	return length;
}

/**
* display
*/
void display(List *list, char *key){
	List *head = list->next;
	Node *node = NULL;
	
	while(head) {
		if(strcmp(head->key, key) == 0) {
			printf("-----list key:%s  length:%ld-----\n", head->key, head->length);
			node = head->left;
			int i;
		    for(i = 0; i < head->length; i++){
		        printf("%d   \n", node->content);
				node = node->next;
		    }
			printf("---------------------------------\n");
			break;
		}
		head = head->next;
	}
}


