//
// Created by goat2 on 2023/11/17.
//
#include<stdio.h>

/**
 * @brief sort numb[left .. right] using merge sort
 * @param nums
 * @param left
 * @param right
 */
#define LEN 7

void MergeSort (int nums[], int left, int right);

/**
 * @brief merge nums[left...right]
 * @param nums
 * @param left
 * @param mid
 * @param right
 */
void Merge(int nums[], int left, int mid, int right);

int main(void) {
    int numbers[LEN] = {};

    for(int i = 0; i < LEN; i++) {
        printf("%d", numbers[i]);
    }

    return 0;
}

void MergeSort (int nums[], int left, int right) {
    if(left == right) {
        return;
    }

    int mid = (left + right) / 2;
    MergeSort(nums, left, mid);
    MergeSort(nums, mid + 1, right);

    Merge(nums, left, mid, right);

}

void Merge(int nums[], int left, int mid, int right) {
    int copy[LEN] = {0};

}