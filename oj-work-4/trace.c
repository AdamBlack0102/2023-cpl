//
// Created by goat2 on 2023/10/22.
//
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 55

int main(void) {
    bool vis[SIZE][SIZE];
    bool judge = true;
    char map[SIZE][SIZE], new_map[SIZE][SIZE];
    int n = 0, m = 0, x = 0, y = 0, count = 0, count_2 = 0;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    memset(map, 0, sizeof(map));
    memset(new_map, 0, sizeof(new_map));
    memset(vis, 0, sizeof(vis));
    getchar();

    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            new_map[i + 1][j + 1] = map[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (new_map[i][j] == '#') {
                count++;
            }
        }
    }

    printf("%d\n", count);

    int vectors[4][2] = {{0,  1},
                         {0,  -1},
                         {1,  0},
                         {-1, 0}};

    printf("%d %d\n", x, y);


    while (x <= n) {
        if (judge == false) {
            break;
        }
        while (y <= m) {
            if (judge == false) {
                break;
            }
            for (int k = 0; k < 4; ++k) {
                vis[x][y] = 1;
                int newX = x + vectors[k][0];
                int newY = y + vectors[k][1];
                if (new_map[newX][newY] == '#' && vis[newX][newY] == 0) {
                    judge = true;
                    vis[newX][newY] = 1;
                    x = newX;
                    y = newY;
                    printf("%d %d\n", x, y);
                    break;
                } else {
                    judge = false;
                    continue;
                }
            }
        }
    }
    return 0;
}