/*
 * Log.c
 *
 *  Created on: Jan 17, 2015
 *      Author: ruansheng
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "log.h"

char * get_time(){
	struct tm *curtime_date;
	time_t curtime;
	time(&curtime);
	static char buffer[128];
	curtime_date=localtime(&curtime);
	strftime(buffer,sizeof(buffer),"[%Y-%m-%d %H:%M:%S]",curtime_date);
	return buffer;
}

int r_write(char *filepath, char *string){
	FILE *handler;
	handler=fopen(filepath,"at+");
	if(handler==NULL){
		return -1;
	}
	char *buffer;
	buffer=get_time();
	fprintf(handler, "%s  %s\n", buffer, string);
	fclose(handler);
	return 0;
}

