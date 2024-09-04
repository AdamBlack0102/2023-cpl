//
// Created by goat2 on 2023/10/29.
//
#include <stdio.h>

#define LEN 100005

char tmp;

int main() {
    int len = 0;
    scanf("%d", &len);
    char str[LEN] = {0};
    scanf("%s", str);

    if (len % 2 != 0) {
        for (int i = 0; i < (len - 1) / 2; i++) {
            tmp = str[i];
            str[i] = str[len - 1 - i];
            str[len - 1 - i] = tmp;
        }

        for (int i = 0; i < len; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                continue;
            } else if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 'a' + 'A';
                continue;
            } else if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + 'a' - 'A';
                continue;
            }
        }
    } else if (len % 2 == 0) {
        for (int i = 0; i < len / 2; i++) {
            tmp = str[i];
            str[i] = str[len - 1 - i];
            str[len - 1 - i] = tmp;
        }

        for (int i = 0; i < len; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                continue;
            } else if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 'a' + 'A';
                continue;
            } else if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + 'a' - 'A';
                continue;
            }
        }
    }

    printf("%s", str);

    return 0;
}