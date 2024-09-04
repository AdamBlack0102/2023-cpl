//
// Created by goat2 on 2023/10/27.
//
#include<stdio.h>
#include<stdbool.h>

bool IsPrime(int number);

int main (void) {
    int max = 0;
    scanf("%d", &max);
    int count = 0;

    for(int number = 2; number <= max; ++number ) {

        if (IsPrime(number)) {
            count++;
            printf("%d ", number);
        }
    }
    printf("\n count = %d \n", count);

    return 0;
}

bool IsPrime(int number) {
    for(int factor = 2; factor * factor <= number; ++factor){
        if (number % factor == 0) {
            return false;
        }
    }

    return true;
}