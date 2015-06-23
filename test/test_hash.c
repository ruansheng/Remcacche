#include <stdio.h>
#include<stdlib.h>
#include "../utils/hash.h"

int main(){
	HashTable *list;
	init_hash(list);
	printf("%p\n\n",list);
	insert_hash(list,"name", "ruansheng", 2005);
	insert_hash(list,"like", "play", 2009);

	printf("list key=%s\n",list->key);
	printf("list content=%s\n",list->content);
	printf("list time_ttl=%ld\n\n",list->time_ttl);

	char *content1=get_hash("name", list);
	printf("content:%s\n\n",content1);
//
//	char *content2=h_get("like", list);
//	printf("content:%s\n\n",content2);
	return 0;
}
