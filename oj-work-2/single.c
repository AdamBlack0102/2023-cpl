//
// Created by goat2 on 2023/10/8.
//
#include<stdio.h>
int main(void) {
    int n;
    scanf("%d", &n);
    n = (2 * n) - 1;
    int numbers[1000005];
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    int single = 0;
    for (int i = 0; i < n; i++) {
        single = single ^ numbers[i];
    }
    printf("%d", single);
    return 0;
}






