//
// Created by goat2 on 2023/10/13.
//
#include<stdio.h>
#include<stdbool.h>
int main (void) {
    int max = 0;
    scanf("%d", &max);
    int count = 0;

    for(int number = 2; number <= max; ++number ) {
        bool is_prime = true;//标志位

        for(int factor = 2; factor * factor <= number; ++factor){
            if (number % factor == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            count++;
            printf("%d ", number);
        }
    }
    printf("\n count = %d \n", count);

    return 0;
}