//
// Created by goat2 on 2023/10/13.
//
#include<stdio.h>
int main(void) {
    int number;
    scanf("%d", &number);

    int num_of_digits = 0;

    do {
        number /= 10;
        num_of_digits++;
    } while (number >0);
    printf("Number of digits is %d\n",
           num_of_digits);
    return 0;
}