//
// Created by goat2 on 2023/10/12.
//
#include<stdio.h>

int main(void) {
    int n, k;
    scanf("%d", &n);
    getchar();
    char str[10000] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%c", &str[i]);
    }
    scanf("%d", &k);
    double stan_s = (k - 1.0) / 2.0;
    for (int i = 0; i < stan_s; i++) {
        char m = str[i];
        str[i] = str[k - i - 1];
        str[k - i - 1] = m;
    }
    int total = k + n;
    double stan = ((n - k) / 2.0) + k;
    for (int i = k; i < stan; i++) {
        char m = str[i];
        str[i] = str[total - i - 1];
        str[total - i - 1] = m;
    }
    for (int i = 0; i < n; i++) {
        printf("%c", str[i]);
    }
    return 0;
}