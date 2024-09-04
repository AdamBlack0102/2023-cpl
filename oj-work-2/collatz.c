//
// Created by goat2 on 2023/10/9.
//
#include<stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int i = 0;
    int max = n;
    for (n = n; n != 1; n = n) {
        if (n % 2 == 0) {
            n = n / 2;
            i = i + 1;
            if (n > max) {
                max = n;
            } else {
                max = max;
            }
        } else {
            n = (n * 3) + 1;
            i = i + 1;
            if (n > max) {
                max = n;
            } else {
                max = max;
            }
        }
    }
    printf("%d %d", i, max);
    return 0;
}