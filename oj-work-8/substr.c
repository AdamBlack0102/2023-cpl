//
// Created by goat2 on 2023/11/30.
//
#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define LEN 100005

int main (void) {
    char *S = malloc(LEN * sizeof(char));
    char *T = malloc(LEN * sizeof(char));

    scanf("%s", S);
    scanf("%s", T);

    char *result = strstr(S, T);

    while(result != NULL) {
        printf("%lld ", result - S);
        result += 1;
        result = strstr(result, T);
    }

    free(S);
    free(T);

    return 0;
}

