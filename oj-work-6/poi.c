//
// Created by goat2 on 2023/11/17.
//
#include<stdio.h>

#define LEN 1000

int Find(int arr[], int count);

int main(void) {
    int n = 0;
    scanf("%d", &n);
    int str[LEN] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &str[i]);
    }
    for (int i = 0; i < n; i++) {
        int boss = Find(str, i);
        printf("%d ", boss);
    }


    return 0;
}

int Find(int arr[], int count) {
    if (arr[count] == count + 1) {
        return arr[count];
    } else {
        return Find(arr, arr[count] - 1);
    }
}