//
// Created by goat2 on 2023/10/28.
//
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int main (void) {
    int x;
    scanf("%d", &x);

    if(x < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(x + 0.5); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;

}