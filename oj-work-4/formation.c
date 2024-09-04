//
// Created by goat2 on 2023/10/21.
//
#include<stdio.h>
#include<string.h>

#define MAX 200

int main(void) {
    int m = 0, n = 0;
    scanf("%d%d", &m, &n);
    char str[MAX] = {0};
    char new_str[MAX][MAX];

    memset(new_str, '0', sizeof(new_str));

    scanf("%s", &str[0]);

    for (int i = 0; i < n; i++) {
        new_str[1][i + 1] = str[i];
    }


    for (int row = 1; row < (m + 2); row++) {
        for (int col = 1; col < (n + 2); col++) {
            char left = new_str[row][col - 1],
                    mid = new_str[row][col],
                    right = new_str[row][col + 1];
            if ((left == '1' && mid == '0' && right == '0') ||
                (left == mid && mid == right)) {
                new_str[row + 1][col] = '0';
            } else {
                new_str[row + 1][col] = '1';
            }
        }
    }

    for (int i = 2; i < (m + 1); i++) {
        for (int j = 1; j < (n + 1); j++) {
            printf("%c", new_str[i][j]);
        }
        printf("\n");
    }

    return 0;
}