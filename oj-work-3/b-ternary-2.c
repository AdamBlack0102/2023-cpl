//
// Created by goat2 on 2023/10/19.
//
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MAX_LEN 10020
#define MAX 25
#define max_len 25

int main(void) {
    int n = 0;
    scanf("%d", &n);
    getchar();
    char str[MAX_LEN][max_len];

    for (int a = 0; a < n; a++) {
        memset(str, 0, sizeof(str));
        int array[MAX] = { 0 };
        char arr[MAX] = { 0 };
        bool judge = true;
        bool min = false;
        scanf("%s", str[a]);

        getchar();
        int len = strlen(str[a]);
        for (int i = 0; i < len; i++) {
            if (str[a][i] == '-' || isdigit(str[a][i])) {
                if (str[a][i] == '-') {
                    if (isdigit(str[a][i + 1])) {
                        min = true;
                        len--;
                        for (int j = 0; j < len + 1; j++) {
                            str[a][j] = str[a][j + 1];
                        }
                    } else {
                        printf("Radix Error\n");
                        judge = false;
                        break;
                    }
                }
                str[a][i] = str[a][i] - '0';
            } else {
                printf("Radix Error\n");
                judge = false;
                break;
            }
        }
        if (judge == true) {
            int sum = 0, remain = 0, count = 0, tmp = 0, sum_ter = 0;
            char tmp_2;
            if (str[a][0] == 0) {
                printf("0");
            }
            for (int i = 0; i < len; i++) {
                sum = sum * 10 + str[a][i];
            }
            for (int j = 0; sum != 0; j++) {
                remain = sum % 3;
                sum = sum / 3;
                array[j] = remain;
                count++;
            }
            for (int j = 0; j < count; j++) {
                arr[j] = array[j] + '0';
            }
            for (int j = 0; j < count; j++) {
                if (array[j] == 2) {
                    arr[j] = 'Z';
                    array[j + 1]++;
                    if (arr[j + 1] == '0') {
                        arr[j + 1] = '1';
                    }
                } else if (array[j] == 3) {
                    arr[j] = '0';
                    array[j + 1]++;
                    if (arr[j + 1] == '0') {
                        arr[j + 1] = '1';
                    }
                }
            }
            if (array[count] == 1) {
                arr[count] = '1';
                count++;
            }
            for (int j = 0; j < (count / 2); j++) {
                tmp_2 = arr[j];
                arr[j] = arr[count - 1 - j];
                arr[count - 1 - j] = tmp_2;
            }
            if (min == true) {
                for (int j = 0; j < count; j++) {
                    if (arr[j] == '1') {
                        arr[j] = 'Z';
                    } else if (arr[j] == 'Z') {
                        arr[j] = '1';
                    }
                }
            }
            for (int j = 0; j < count; j++) {
                printf("%c", arr[j]);
            }
            printf("\n");
        }
    }
    return 0;
}