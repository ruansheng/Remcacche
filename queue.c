//
// Created by ruansheng on 16/4/3.
//

#include "server.h"

int rpushCommand(event *ev, char key[1024], char value[1024]) {
    return rpush(ev->list, key, value);
}

int qlenCommand(event *ev, char key[1024]) {
    return llen(ev->list, key);
}

char * rpopCommand(event *ev, char key[1024]) {
    char *data = rpop(ev->list, key);
}

char * listCommand(event *ev, char key[1024]) {
    display(ev->list, key);
}