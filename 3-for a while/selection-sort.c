//
// Created by goat2 on 2023/10/13.
//
#include<stdio.h>
#define LEN 20
int numbers[LEN] = {0};
int main (void) {
    int len = -1;

    while (scanf("%d", &numbers[++len]) != EOF);
    for (int i = 0; i < len; i++) {
    printf("%d", numbers[i]);
    }



    return 0;
}