/*
 * Log.c
 *
 *  Created on: Jan 17, 2015
 *      Author: ruansheng
 */

#include "log.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * get_time();

int write(char *filepath,char *string){
	FILE *handler;
	handler=fopen(filepath,"at+");
	if(handler==NULL){
		return -1;
	}
	char * buffer;
	buffer=(char *)malloc(128*sizeof(char));
	buffer=get_time();        
	printf("%s\n",buffer);
	fputs(buffer,handler);
	fputs(string,handler);
        fputs("\n",handler);
	fclose(handler);
	return 0;
}

char * get_time(char *date){
	struct tm *curtime_date;
        time_t curtime;
        time(&curtime);
        char buffer[128];
        curtime_date=localtime(&curtime);
        strftime(buffer,sizeof(buffer),"[%Y/%m/%d %H:%M:%S]	",curtime_date);
	printf("%s\n",buffer);
	date=buffer;
	return date;
}
