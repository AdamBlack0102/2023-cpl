//
// Created by goat2 on 2023/10/15.
//
#include<stdio.h>

int main(void) {
    int n = 0;
    scanf("%d", &n);
    char bit[2005] = {0};
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= n; a++) {
            if (a % i == 0) {
                if (bit[a] == 0) {
                    bit[a] = 1;
                } else {
                    bit[a] = 0;
                }
            } else {
                continue;
            }
        }

    }
    for (int i = 1; i <= n; i++) {
        if (bit[i] == 1) {
            printf("%d ", i);
        } else {
            continue;
        }
    }
    printf("%c", 8);
    return 0;
}