//
// Created by goat2 on 2023/9/23.
//
#include <stdio.h>
#include <math.h>
int main(void) {
    int p, q;
    scanf("%d %d", &p, &q);
    double a = q / 2.0;
    double b = p / 3.0;
    double A = a * a;
    double B = b * b * b;
    double formula = A + B;
    double c = sqrt(formula);
    double C = 0.0 - a + c;
    double D = 0.0 - a - c;
    double x = cbrt(C) + cbrt(D);
    printf("%.3f", x);
    return 0;
}