//
// Created by goat2 on 2023/10/21.
//
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 3
#define SIZE_BIG 9
#define LONG 81
#define LONG_TEST 10

int main(void) {
    bool judge = true;
    int small[SIZE][SIZE], big[SIZE_BIG][SIZE_BIG],
            test[SIZE_BIG] = {0}, test_big[LONG] = {0};
    memset(small, 0, sizeof(small));
    memset(big, 0, sizeof(big));
    int tmp = 0;

    for (int i = 0; i < SIZE_BIG; i++) {
        for (int j = 0; j < SIZE_BIG; j++) {
            scanf("%d", &big[i][j]);
        }
    }

    for (int x = 0; x < SIZE_BIG; x = x + 3) {
        for (int w = 0; w < SIZE_BIG; w = w + 3) {
            int judge_1[LONG_TEST] = {0};
            if (judge == false) {
                break;
            }
            judge = true;
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    small[i][j] = big[i + x][j + w];
                }
            }

            int row = 0, col = 0, y = 3, h = 0;
            while (y < SIZE_BIG) {
                col = 0;
                while (row < SIZE) {
                    while (col < SIZE) {
                        while (h < y) {
                            test[h] = small[row][col];
                            col++;
                            h++;
                        }
                        row++;
                        break;
                    }
                    y = y + 3;
                    col = 0;
                }
            }

            for (int i = 0; i < SIZE_BIG; i++) {
                judge_1[test[i]]++;
            }

            for (int i = 0; i < LONG_TEST; i++) {
                if (judge_1[i] > 1) {
                    judge = false;
                    break;
                }
            }
        }
    }


    if (judge == true) {
        int row = 0, col = 0, y = 9, h = 0;
        while (y < LONG) {
            col = 0;
            while (row < SIZE_BIG) {
                while (col < SIZE_BIG) {
                    while (h < y) {
                        test_big[h] = big[row][col];
                        col++;
                        h++;
                    }
                    row++;
                    break;
                }
                y = y + 9;
                col = 0;
            }
        }

        int judge_2[LONG_TEST] = {0};

        for (int i = 0; i < LONG_TEST; i++) {
            judge_2[test_big[i]]++;
        }

        for (int i = 0; i < LONG_TEST; i++) {
            if (judge_2[i] > 9) {
                judge = false;
                break;
            }
        }
    }

    if (judge == true) {
        for (int i = 0; i < SIZE_BIG; i++) {
            int judge_3[10] = {0};
            for (int j = 0; j < SIZE_BIG; j++) {
                judge_3[big[i][j]]++;
                if (judge_3[j] > 1) {
                    judge = false;
                    break;
                }
            }
        }
    }

    if (judge == true) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}