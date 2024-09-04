//
// Created by goat2 on 2023/11/20.
//
#include <stdio.h>
#include<string.h>
#include<math.h>

#define SIZE 450

void Paint(char str[SIZE][SIZE], int n, int x, int y);

int main(void) {
    int n = 0;
    scanf("%d", &n);
    char str[SIZE][SIZE];
    memset(str, 0, sizeof(str));
    int biggest_x = pow(2, n + 1);
    int biggest_y = pow(2, n);
    Paint(str, n, 1, 1);
    for (int i = 0; i < biggest_y; i++) {
        for (int j = 0; j < biggest_x; j++) {
            if (str[i][j] == 0) {
                printf(" ");
            } else {
                printf("%c", str[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}

void Paint(char str[SIZE][SIZE], int n, int x, int y) {
    if (n == 1) {
        str[x - 1][y] = '/';
        str[x - 1][y + 1] = '\\';
        str[x][y - 1] = '/';
        str[x][y] = '_';
        str[x][y + 1] = '_';
        str[x][y + 2] = '\\';
    } else {
        Paint(str, n - 1, x,
              y + pow(2, n) / 2);
        Paint(str, n - 1, x + pow(2, n) / 2,
              y);
        Paint(str, n - 1,
              x + pow(2, n) / 2, y + pow(2, n));
    }
}

