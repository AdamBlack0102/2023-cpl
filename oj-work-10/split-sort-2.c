//
// Created by goat2 on 2023/12/16.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 1000
char str[LEN];
char *ret[LEN];
char split;
int comp(const void *left, const void *right);

int main(void) {
    scanf("%s", str);
    int len = strlen(str);
    str[len] = '\0';
    getchar();
    scanf("%c", &split);
    ret[0] = strtok(str, &split);
    int x = 0;
    while (ret[x++] != NULL) {
        ret[x] = strtok(NULL, &split);
    }

    qsort(ret, x - 1, sizeof(char *), comp);
    for (int i = 0; i < x - 1; i++) {
        printf("%s\n", ret[i]);
    }
    return 0;
}

int comp(const void *left, const void *right) {
    return strcmp(*(const char **) left, *(const char **) right);
}