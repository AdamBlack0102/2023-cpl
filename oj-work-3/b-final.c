//
// Created by goat2 on 2023/10/19.
//
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

#define MAX_LEN 10020
#define max_len 25

int main(void) {
    int n = 0;
    scanf("%d", &n);
    getchar();

    for (int a = 0; a < n; a++) {
        char array[MAX_LEN][max_len];
        bool judge = true;
        int ter = 0, dec = 0, sum = 0;
        scanf("%s", array[a]);
        int len = strlen(array[a]);

        for (int i = 0; i < len; i++) {
            if (array[a][i] == '1') {
                ter = pow(3, (len - 1 - i));
                dec = ter;
                sum = dec + sum;
            } else if (array[a][i] == 'Z') {
                ter = pow(3, (len - 1 - i));
                dec = (-1) * ter;
                sum = dec + sum;
                continue;
            } else if (array[a][i] != '0') {
                judge = false;
                printf("Radix Error\n");
                break;
            }
        }
        if (judge) {
            printf("%d\n", sum);
        }
    }
    return 0;
}