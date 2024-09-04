//
// Created by goat2 on 2023/12/20.
//
#include<stdio.h>

int s0, i, n, t, o;

int main(void) {
    scanf("%d%d%d%d%d", &s0, &i, &n, &t, &o);
    if (s0 == 0) {
        if (o == i) {
            printf("1");
            return 0;
        } else {
            printf("0");
            return 0;
        }
    } else if (s0 == 1) {
        if (o == i) {
            printf("1");
            return 0;
        } else if (o == n) {
            printf("2");
            return 0;
        } else {
            printf("0");
            return 0;
        }
    } else if (s0 == 2) {
        if (o == i) {
            printf("1");
            return 0;
        } else if (o == t) {
            printf("3");
            return 0;
        } else {
            printf("0");
            return 0;
        }
    } else if (s0 == 3) {
        if (o == i) {
            printf("1");
            return 0;
        } else {
            printf("0");
            return 0;
        }
    }
    return 0;
}