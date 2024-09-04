//
// Created by goat2 on 2023/10/15.
//
#include<stdio.h>
#include<stdbool.h>


int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);
    char str[10000];
    for (int i = 0; i < n; i++) {
        str[i] = true;
    }
    int count = 1;
    int left_people = n;
    int index = 0;
    for (index = 0; index < n; index++) {
        while (left_people > 1) {
            if (str[index] == false) {
                index = (index + 1) % n;
            } else {
                if (count != k) {
                    count++;
                    index = (index + 1) % n;
                } else {
                    str[index] = false;
                    count = 1;
                    index = (index + 1) % n;
                    left_people--;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (str[i] == true) {
            printf("%d", i + 1);
        }
    }
    return 0;
}