//
// Created by goat2 on 2023/10/27.
//
#include<stdio.h>

#define LEN 10

//global variable
//file scope

//int dict[]: 元素首地址 the address of the first element of the array
int BinarySearch(int key, const int dict[], int len);

int main(void) {
    const int dictionary[LEN] = {1, 1, 2, 3, 5, 8, 13, 21, 35, 56};
    int key = 0;
    scanf("%d", &key);

   /* int low = 0;
    int high = LEN - 1;
    int idx = BinarySearch(key, dict[], LEN);
    while (low <= high) {
        int mid = (low + high) / 2;

        if (key > dict[mid]) {
            low = mid + 1;
        } else if (key < dict[mid]) {
            high = mid - 1;
        } else {
            idx = mid;
            //break;
            high = mid - 1;
        }
    }*/
    printf("idx = %d\n", index);
    return 0;
}

int BinarySearch(int key, const int dict[], int len) {
    int low = 0;
    int high = LEN - 1;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (key > dict[mid]) {
            low = mid + 1;
        } else if (key < dict[mid]) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}