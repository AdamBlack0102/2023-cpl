//
// Created by goat2 on 2023/11/10.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main(void) {
    char str[] = "Hello World!\0";
    char *p;
    p = str;
    while(*p!=' ') {
        printf("%c", *p-1);
        p++;
    }
    return 0;
}

