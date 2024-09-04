//
// Created by goat2 on 2023/10/19.
//
#include<stdio.h>

int main (void) {
    int n;
    scanf("%d", &n);
    int a[50000];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 2; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%d", a[i]);
    }
    return 0;
}