//
// Created by goat2 on 2023/9/23.
//
#include <stdio.h>
int main(void) {
    double m;
    double R;
    scanf("%lf %lf", &m, &R);

    double G = 6.674e-11;
    double M = 77.15;

    double A = G * M * m;
    double B = R * R;

    double F = A / B;
    printf("%.3e", F);

    return 0;
}