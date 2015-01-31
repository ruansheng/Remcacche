/*
 * r_time.c
 *
 *  Created on: Jan 31, 2015
 *      Author: root
 */


#include <stdio.h>
#include "r_time.h"

char * get_time(){
	struct tm *curtime_date;
	time_t curtime;
	time(&curtime);
	static char buffer[128];
	curtime_date=localtime(&curtime);
	strftime(buffer,sizeof(buffer),"[%Y-%m-%d %H:%M:%S]	",curtime_date);
	return buffer;
}
