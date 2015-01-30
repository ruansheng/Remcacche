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

int r_write(char *filepath,char *string){
	FILE *handler;
	handler=fopen(filepath,"at+");
	if(handler==NULL){
		return -1;
	}
	char *buffer;
	buffer=get_time();
	fputs(buffer,handler);
	fputs(string,handler);
    fputs("\n",handler);
	fclose(handler);
	return 0;
}

char * get_time(){
	struct tm *curtime_date;
	time_t curtime;
	time(&curtime);
	static char buffer[128];
	curtime_date=localtime(&curtime);
	strftime(buffer,sizeof(buffer),"[%Y-%m-%d %H:%M:%S]	",curtime_date);
	return buffer;
}
