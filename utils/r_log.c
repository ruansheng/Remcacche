/*
 * Log.c
 *
 *  Created on: Jan 17, 2015
 *      Author: ruansheng
 */

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "r_log.h"
#include "r_time.h"

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

