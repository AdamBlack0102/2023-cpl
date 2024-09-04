//
// Created by goat2 on 2023/10/15.
//
#include<stdio.h>
#include<stdbool.h>

int main(void) {
    int T = 0;
    scanf("%d", &T);
    int m = 2 * T;
    for (int x = 0; x < m; x = x + 2) {
        bool judge = true;
        int n;
        int str[50005] = {0};
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; i++) {
            scanf("%d", &str[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            if (str[n - 1] < str[i]) {
                judge = false;
                break;
            }
        }
        if (judge == true) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}