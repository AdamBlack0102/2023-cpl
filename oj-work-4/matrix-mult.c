//
// Created by goat2 on 2023/10/21.
//
#include<stdio.h>
#include<string.h>

#define MAX_LEN 200
#define max_len 200

int main(void) {
    int str_a[MAX_LEN][max_len];
    int str_b[MAX_LEN][max_len];
    int str_c[MAX_LEN][max_len];
    memset(str_a, 0, sizeof(str_a));
    memset(str_b, 0, sizeof(str_b));
    int m = 0, n = 0, p = 0, mul = 0;
    scanf("%d%d%d", &m, &n, &p);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &str_a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &str_b[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int a = 0; a < n; a++) {
                mul = str_a[i][a] * str_b[a][j];
                sum = sum + mul;
            }
            str_c[i][j] = sum;
            printf("%d ", str_c[i][j]);
            if (j == (p - 1)) {
                printf("\n");
            }
        }
    }
    return 0;
}