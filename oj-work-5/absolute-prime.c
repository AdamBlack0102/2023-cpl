//
// Created by goat2 on 2023/10/28.
//
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool Prime(int x);

int Flip(int x);

int main(void) {

    int n = 0, count = 0, flip = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        flip = Flip(i);
        if (Prime(i) && Prime(flip)) {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}

bool Prime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(x + 0.5); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int Flip(int x) {
    int flip = 0, uni = 0, ten = 0, hund = 0, thou = 0;

    thou = x / 1000;
    hund = (x % 1000) / 100;
    ten = ((x % 1000) % 100) / 10;
    uni = x - thou * 1000 - hund * 100 - ten * 10;

    if (thou == 0 && hund == 0 && ten == 0) {
        flip = uni;
    } else if (thou == 0 && hund == 0 && ten != 0) {
        flip = ten + uni * 10;
    } else if (thou == 0 && hund != 0) {
        flip = hund + ten * 10 + uni * 100;
    } else {
        flip = thou + hund * 10 + ten * 100 + uni * 1000;
    }

    return flip;
}