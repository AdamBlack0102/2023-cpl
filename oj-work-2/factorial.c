//
// Created by goat2 on 2023/10/9.
//
#include<stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    const int NUM = 10007;
    int fac = 1;
    int mul = 1;
    int plus = 0;
    int k = 0;
    for (int i = 1; i <= n; i++) {
        fac = i % NUM;
        mul = fac * mul % NUM;
        k = mul % NUM;
        plus = (plus + k) % NUM;
    }
    fac = plus % NUM;
    printf("%d", fac);
    return 0;
}