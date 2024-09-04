//
// Created by goat2 on 2023/12/16.
//
#include<stdio.h>
#include<string.h>

#define LEN 100

int main(void) {
    char str[LEN] = {0};
    char *ret[LEN][LEN] = {0};
    char split = 'a';
    scanf("%s", str);
    getchar();
    scanf("%c", &split);
    *ret[0] = strtok(str, &split);
    int x = 0;
    while(*ret[x++] != NULL) {
        *ret[x] = strtok(NULL, &split);
    }
    x = 0;
    while(ret[x] != NULL) {
        printf("%s\n", *ret[x]);
    }
    return 0;
}