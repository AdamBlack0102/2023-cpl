//
// Created by goat2 on 2023/11/10.
//
#include <stdio.h>

#define NUM 3
const int numbers[NUM] = { 65, 28, 37 };

int Min(const int nums[], int len);

int main() {
    int min = Min(numbers, NUM);

    printf("min = %d\n", min);

    return 0;
}

// compute the minimum of nums[0 .. len - 1]
int Min(const int nums[], int len) {
    if (len == 1) {
        return nums[0];
    }

    int partial_min = Min(nums, len - 1);

    return partial_min < nums[len - 1] ? partial_min : nums[len - 1];
}