//
// Created by goat2 on 2023/11/17.
//
#include<stdio.h>

int SUM(int a, int b);

int main(void) {
    int a = 0, b = 0;
    scanf("%d%d", &a, &b);
    int sum = SUM(a, b);
    printf("%d", sum);

    return 0;
}

int SUM(int a, int b) {
    if (b == 1 || a == b) {
        return 1;
    } else {
        return SUM(a - 1, b - 1) + SUM(a - 1, b);
    }
}