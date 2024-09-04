//
// Created by goat2 on 2023/10/20.
//
#include<stdio.h>

#define LEN_L 5
#define LEN_R 6

int L[LEN_L] = {};
int R[LEN_R] = {};

int main(void) {
    int l = 0;
    int r = 0;

    while (l < LEN_L && r < LEN_R) {
        if (L[l] <= R[r]) {
            printf("%d ", L[l]);
            l++;
        } else {
            printf("%d ", R[r]);
            r++;
        }
    }
    while (r < LEN_R) {
        printf("%d ", R[r]);
        r++;
    }
    while (l < LEN_L) {
        printf("%d ", L[l]);
        l++;
    }
    return 0;
}