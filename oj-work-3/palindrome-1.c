//
// Created by goat2 on 2023/10/15.
//
#include<stdio.h>

int main(void) {
    int n = 0;
    scanf("%d", &n);
    char s[10000] = {0};
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%c", &s[i]);
    }
    if (n % 2 == 0) {
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                s[i] = s[n - 1 - i];
            } else {
                continue;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                s[i] = s[(n - 1) - i];
            } else {
                continue;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%c", s[i]);
    }
    return 0;
}