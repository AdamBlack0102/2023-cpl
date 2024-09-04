//
// Created by goat2 on 2023/11/22.
//
#include<stdio.h>

#define LEN 1000

int n = 0, L = 0;

int SCANF(int str[]);
int MAX (int value[], const int max[], int ori_value[]);

int main (void) {
    int value[LEN] = { 0 };
    int max[LEN] = { 0 };
    scanf("%d%d", &n, &L);
    SCANF(value);
    SCANF(max);
    int ori_value[LEN] = { 0 };
    for(int i = 0; i < n; i++) {
        ori_value[i] = value[i];
    }
    printf("%d", MAX(value, max, ori_value));

    return 0;
}

int SCANF(int str[]) {
    for(int i = 0; i < n; i++) {
        scanf("%d", &str[i]);
    }
    return *str;
}

int MAX (int value[], const int max[], int ori_value[]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(value[j] > value[j + 1]) {
                int tmp = value[j];
                value[j] = value[j + 1];
                value[j + 1] = tmp;
            }
        }
    }

    int sum = 0;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if(value[i] == ori_value[j]) {
                if(L > 0) {
                    if(max[j] <= L) {
                        sum += ori_value[j] * max[j];
                        L -= max[j];
                        ori_value[j] = -1;
                        continue;
                    } else {
                        sum += ori_value[j] * L;
                        L = 0;
                        return sum;
                    }
                }
            }
        }
    }
    return sum;
}