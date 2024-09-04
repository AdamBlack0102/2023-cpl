//
// Created by goat2 on 2023/10/29.
//
#include <stdio.h>
#include<string.h>


int main() {
    int t = 0, x = 0;
    scanf("%d%d", &t, &x);

    for (int i = 0; i < t; i++) {
        int n = 0;
        scanf("%d", &n);
        int board[4][4];
        memset(board, 0, sizeof(board));
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                scanf("%d", &board[a][b]);
            }
        }

        int flag = 0;
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                if (flag == 1) {
                    memset(board, 0, sizeof(board));
                    break;
                }
                int re = board[a][b];
                for (int col = 1; col < x; col++) {
                    if (flag == 1) {
                        break;
                    } else {
                        re = re & board[a][col];
                    }
                }
                if (flag == 0) {
                    switch (re) {
                        case 1 :
                            printf("1\n");
                            re = board[a][b];
                            flag = 1;
                            break;
                        case 2 :
                            printf("2\n");
                            re = board[a][b];
                            flag = 1;
                            break;
                        case 4 :
                            printf("4\n");
                            re = board[a][b];
                            flag = 1;
                            break;
                        default :
                            re = board[a][b];
                    }
                }

                for (int row = 1; row < x; row++) {
                    if (flag == 1) {
                        break;
                    } else {
                        re = re & board[row][b];
                    }
                }

                if (flag == 0) {
                    switch (re) {
                        case 1 :
                            printf("1\n");
                            re = board[a][b];
                            flag = 1;
                            break;
                        case 2 :
                            printf("2\n");
                            re = board[a][b];
                            flag = 1;
                            break;
                        case 4 :
                            printf("4\n");
                            re = board[a][b];
                            flag = 1;
                            break;
                        default :
                            re = board[a][b];
                    }
                }


                int w = 0;
                while (w < x) {
                    if (flag == 1) {
                        break;
                    } else {
                        w++;
                        re = re & board[a + w][b + w];
                    }
                }
                if (flag == 0) {
                    switch (re) {
                        case 1 :
                            printf("1\n");
                            re = board[a][b];
                            flag = 1;
                            break;
                        case 2 :
                            printf("2\n");
                            re = board[a][b];
                            flag = 1;
                            break;
                        case 4 :
                            printf("4\n");
                            re = board[a][b];
                            flag = 1;
                            break;
                        default :
                            re = board[a][b];
                    }
                }
            }
            if (flag == 1) {
                memset(board, 0, sizeof(board));
                break;
            }
        }
    }

    return 0;
}