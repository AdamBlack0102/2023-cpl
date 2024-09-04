//
// Created by goat2 on 2023/10/27.
//
#include<stdio.h>

#define LEN 100

int n;
int str[LEN][LEN];

int main(void) {
    scanf("%d", &n);

    int y = ((n - 1) / 2) + 1;

    str[1][y] = 1;
    str[n][y + 1] = 2;

    int x = n;
    y = y + 1;

    for (int i = 3; i <= n * n; i++) {
        if (str[x - 1][y + 1] == 0 && (y + 1) <= n && (y + 1) >= 1
            && (x - 1) <= n && (x - 1) >= 1) {
            if (str[x - 1][y + 1] != 0) {
                str[x + 1][y] = i;
                x = x + 1;
            } else {
                str[x - 1][y + 1] = i;
                x = x - 1;
                y = y + 1;
            }
        } else if (str[x - 1][y + 1] == 0 && (y + 1) >= (n + 1)
                   && (x - 1) <= n && (x - 1) >= 1) {
            if (str[x - 1][(y + 1) - n] != 0) {
                str[x + 1][y] = i;
                x = x + 1;
            } else {
                str[x - 1][(y + 1) - n] = i;
                x = x - 1;
                y = (y + 1) - n;
            }
        } else if (str[x - 1][y + 1] == 0 && (y + 1) <= n && (y + 1) >= 1
                   && (x - 1) < 1) {
            if (str[n - (x - 1)][y + 1] != 0) {
                str[x + 1][y] = i;
                x = x + 1;
            } else {
                str[n - (x - 1)][y + 1] = i;
                x = n - (x - 1);
                y = y + 1;
            }
        } else if (str[x - 1][y + 1] == 0 && (y + 1) >= (n + 1)
                   && (x - 1) < 1) {
            if (str[n - (x - 1)][(y + 1) - n] != 0) {
                str[x + 1][y] = i;
                x = x + 1;
            } else {
                str[n - (x - 1)][(y + 1) - n] = i;
                x = n - (x - 1);
                y = (y + 1) - n;
            }
        } else if (str[x - 1][y + 1] != 0 && (y + 1) <= n
                   && (x - 1) <= n) {
            str[x + 1][y] = i;
            x = x + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", str[i][j]);
        }
        printf("\n");
    }

    return 0;
}