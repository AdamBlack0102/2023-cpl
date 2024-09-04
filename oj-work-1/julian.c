//
// Created by goat2 on 2023/9/23.
//
#include <stdio.h>
int main(void) {
    int year;
    int month;
    int day;

    scanf("%d%d%d", &year, &month, &day);

    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + (12 * a) - 3;
    int A = (153 * m + 2) / 5;
    int B = 365 * y;
    int C = y / 4;
    int D = y / 100;
    int E = y / 400;

    int JDN = day + A + B + C - D + E - 32045;
    printf("%d", JDN);

    return 0;
}