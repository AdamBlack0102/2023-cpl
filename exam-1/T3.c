//
// Created by goat2 on 2023/10/29.
//
#include <stdio.h>
#include<stdbool.h>
#include<string.h>

int n, k, b, l, count = 1;
bool jo[1600];

int main() {
    memset(jo, true, sizeof(jo));
    scanf("%d%d%d%d", &n, &k, &b, &l);
    int index = 0;
    int left = n;
    int bul = b;
    while (index < n) {
        if (left > 1) {
            if (jo[index] == false) {
                index = (index + 1) % n;
                continue;
            } else {
                if (count == k) {
                    if (bul > 0) {
                        jo[index] = false;
                        count = 1;
                        index = (index + 1) % n;
                        left--;
                        bul--;
                        continue;
                    } else {
                        index = (index + 1) % n;
                        count = 1;
                        bul = b;
                        continue;
                    }
                } else {
                    count++;
                    index = (index + 1) % n;
                }
            }
        } else {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (jo[i] == true) {
            printf("%d", i + 1);
        }
    }

    return 0;
}