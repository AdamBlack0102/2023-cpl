//
// Created by goat2 on 2023/10/22.
//
#include<stdio.h>
#include<string.h>

int main(void) {
    int n = 0;
    char map[105][105];
    char new_map[105][105];
    memset(map, 'o', sizeof(map));
    memset(new_map, 'o', sizeof(new_map));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
    }

    for (int i = 1; i < (n + 1); i++) {
        for (int j = 1; j < (n + 1); j++) {
            new_map[i][j] = map[i - 1][j - 1];
        }
    }

    int vectors[8][2] = {{0,  1},
                         {0,  -1},
                         {1,  0},
                         {-1, 0},
                         {1,  -1},
                         {1,  1},
                         {-1, 1},
                         {-1, -1}};


    for (int i = 1; i < (n + 1); i++) {
        for (int j = 1; j < (n + 1); j++) {
            int count = 0;

            for (int k = 0; k < 8; ++k) {
                if (new_map[i][j] == '*') {
                    break;
                } else {
                    int newI = i + vectors[k][0];
                    int newJ = j + vectors[k][1];
                    if (new_map[newI][newJ] == '*') {
                        count++;
                    }
                }
                new_map[i][j] = count;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (new_map[i][j] != '*') {
                new_map[i][j] = new_map[i][j] + '0';
            }
        }
    }

    for (int i = 1; i < (n + 1); i++) {
        for (int j = 1; j < (n + 1); j++) {
            printf("%c", new_map[i][j]);
        }
        printf("\n");
    }

    return 0;
}