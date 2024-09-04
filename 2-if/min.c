//
// Created by goat2 on 2023/10/8.
//
#include<stdio.h>
int main (void) {
    int year = 0;
    scanf("%d", &year);
    int leap = 0;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if(year % 400 == 0) {
                leap = 1;
            }
        } else {
            leap = 0;
        }

    } else {
        leap = 0;
    }

    return 0;
}