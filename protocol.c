//
// Created by ruansheng on 16/4/3.
//

/*
  protocol:
        rpush
            request   (rpush user zhangsan)
                *queue
                #3
                rpush
                user
                zhangsan
            response
                +OK
                #0

                -ERROR
                #1
                command is error

        qlen
            request  (qlen user)
                *queue
                #2
                qlen
                user
            response
                +OK
                #1
                7

                -ERROR
                #1
                command is error
 */

#include "server.h"

char * parseCommand(event *ev, char cmd[1024]) {
    const char *tmp = cmd;
    char type[1024];
    char command[1024];
    char key[1024];
    char value[2014];
    int i = 0;
    int j = 0;
    while(*tmp != '\0') {
        if(*tmp == ' ') {
            tmp++;
            continue;
        }
        if(*tmp == '\n') {
            if(i == 0) {
                type[j] = '\0';
            } else if(i == 1) {
                command[j] = '\0';
            } else if(i == 2) {
                key[j] = '\0';
            } else if(i == 3) {
                value[j] = '\0';
            }
            i++;
            j = 0;
        } else {
            if(i == 0) {
                type[j] = *tmp;
            } else if(i == 1) {
                command[j] = *tmp;
            } else if(i == 2) {
                key[j] = *tmp;
            } else if(i == 3) {
                value[j] = *tmp;
            } else {
                break;
            }
            j++;
        }
        tmp++;
    }

    if(strcmp(type, "*queue") == 0) {
        if (strcmp(command, "rpush") == 0) {
            int ret = rpushCommand(ev, key, value);
            if (ret == 1) {
                return "OK";
            } else {
                return "rpush error";
            }
        } else if (strcmp(command, "rpop") == 0) {
            rpopCommand(ev, key);
            return "OK";
        } else if (strcmp(command, "list") == 0) {
            listCommand(ev, key);
            return "OK";
        } else if (strcmp(command, "qlen") == 0) {
            int qlen = qlenCommand(ev, key);
            printf("qlen: %d \n", qlen);
            return "OK";
        } else {
            return "command error";
        }
    } else if(strcmp(type, "*string") == 0) {
        if (strcmp(command, "set") == 0) {
            int ret = setCommand(ev, key, value);
            if (ret == 1) {
                return "OK";
            } else {
                return "rpush error";
            }
        } else if (strcmp(command, "get") == 0) {
            getCommand(ev, key);
            return "OK";
        } else if (strcmp(command, "list") == 0) {
            listCommand(ev, key);
            return "OK";
        } else if (strcmp(command, "qlen") == 0) {
            int qlen = qlenCommand(ev, key);
            printf("qlen: %d \n", qlen);
            return "OK";
        } else {
            return "command error";
        }
    } else {
        return "type error";
    }
}

/*
char * makeServerProtocolData(int type, const void *str) {
    char *cmd;
    if(type == 0) {  // OK
        sprintf(cmd, "+OK\n%s\n", str);
    } else {
        sprintf(cmd, "-ERROR\n%s\n", str);
    }

    return cmd;
}
*/

char * makeServerProtocolData(char *fmt, ...) {
    va_list   arg;
    char cmd[1024];

    va_start(arg, fmt);
    vsprintf(cmd, fmt,arg);
    va_end(arg);
    return cmd;
}