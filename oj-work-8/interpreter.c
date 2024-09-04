//
// Created by goat2 on 2023/11/28.
//
#include<stdio.h>

int main(void) {
    int num;
    scanf("%x", &num);
    int *signed_32 = (int *) &num;
    unsigned int *unsigned_32 = (unsigned int *) &num;
    float *float_32 = (float *) &num;

    printf("%d\n%u\n%.6f\n%.3e", *signed_32, *unsigned_32,
           *float_32, *float_32);

    return 0;
}

//arr[i] == *(arr + i)