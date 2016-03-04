
#include <stdio.h>
#include "../utils/list.h"

int main(){
	List *list;
	list = init(list);
	int i;
	for(i = 0; i < 10; i++) {
		lpush(list, "user", i);  
		lpush(list, "feed", i*10);  
	}
	
	rpush(list, "user", 1000);
	
	display(list, "user");
	printf("llen:%d \n", llen(list, "user"));
	
	int one = lpop(list, "user");
	printf("lpop: %d \n", one);
	
	display(list, "user");
	printf("llen:%d \n", llen(list, "user"));
	
	int two = rpop(list, "user");
	printf("rpop: %d \n", two);
	
	display(list, "user");
	printf("llen:%d \n", llen(list, "user"));
	
	return 0;
}
