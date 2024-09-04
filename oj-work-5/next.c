//
// Created by goat2 on 2023/11/2.
//
#include<stdio.h>
#include<stdbool.h>

int main(void) {
    int n = 0;
    scanf("%d", &n);
    int str[2005] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &str[i]);
    }

    int count = 1;

    for (int i = (n - 1); i > 0; i--) {
        if (str[i] < str[i - 1]) {
            count++;
        } else {
            break;
        }
    }

    int min = str[n - count - 1];
    bool flag = true;

    if (n - count == n - 1) {
        min = str[n - 1];
        flag = false;

    }


    if (flag == true) {
        for (int y = n - 1; y >= n - count; y--) {
            if (str[y] > min) {
                min = str[y];
                break;
            }
        }
    }

    int tmp = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == min) {
            tmp = str[i];
            str[i] = str[n - count - 1];
            str[n - count - 1] = tmp;
            break;
        }
    }

    for (int i = n - count; i <= (2 * n - count - 2) / 2; i++) {
        tmp = str[i];
        str[i] = str[(2 * n - count - 1) - i];
        str[(2 * n - count - 1) - i] = tmp;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", str[i]);
    }

    return 0;
}





