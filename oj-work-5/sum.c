//
// Created by goat2 on 2023/10/27.
//
#include<stdio.h>
#include<math.h>

int n, t, sum, add;

int main(void) {
    scanf("%d%d", &n, &t);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            add += pow(10, j) * t;
        }
        sum += add;
        add = 0;
    }

    printf("%d", sum);

    return 0;
}