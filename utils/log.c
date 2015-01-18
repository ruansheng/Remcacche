/*
 * Log.c
 *
 *  Created on: Jan 17, 2015
 *      Author: ruansheng
 */

#include "log.h"

#include <stdio.h>

int write(char *filepath[],char *string[]){
		FILE *handler;
		handler=fopen(filepath,"at+");
		if(handler==NULL){
			return -1;
		}
	    fputs(string,handler);
	    fputs("\n",handler);
	return 0;
}
