//
// Created by goat2 on 2023/12/16.
//
#include<stdio.h>
#include<stdlib.h>

#define LEN 100

int comp(const void *left, const void *right);

int main(void) {
    int n = 0, q = 0;
    int str[LEN] = {0};
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &str[i]);
    }

    for (int i = 0; i < q; i++) {
        int key = 0;
        scanf("%d", &key);
        int *ret = bsearch(&key, str, n, sizeof(int), comp);
        if (ret == NULL) {
            printf("-1\n");
        } else {
            printf("%d\n", ret - str);
        }
    }
    return 0;
}

int comp(const void *left, const void *right) {
    return (*(int *) left - *(int *) right);
}