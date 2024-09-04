//
// Created by goat2 on 2023/11/26.
//

#include <stdio.h>
#include <stdlib.h>

#define LEN 605
#define max(x, y) x > y ? x : y

void sum();

int n, m, d, max;
int v[LEN][LEN], re[LEN][LEN], center[LEN][2];

int main(void) {
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &v[i][j]);
        }
    }

    sum();

    max = re[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            max = max(max, re[i][j]);
        }
    }

    int a = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (re[i][j] == max) {
                center[a][0] = i;
                center[a][1] = j;
                a++;
            }
        }
    }

    printf("%d %d\n", max, a);
    for (int i = 0; i < a; i++) {
        printf("%d %d\n", center[i][0], center[i][1]);
    }

    return 0;
}

void sum() {
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            re[x][y] = 0;
            for (int i = x - d; i <= x + d; i++) {
                int tmp = d - abs(x - i);
                for (int j = y - tmp; j <= y + tmp; j++) {
                    re[x][y] += v[i][j];
                }
            }
        }
    }
}