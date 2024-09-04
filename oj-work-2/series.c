//
// Created by goat2 on 2023/10/9.
//
#include<stdio.h>
#include<math.h>

int main(void) {
    int n;
    double x;
    double sum = 0, a, b, nume, deno, div;
    scanf("%lf%d", &x, &n);
    n = n + 1;
    for (int i = 0; i < n; i++) {
        a = pow(-1, i);
        b = pow(x, ((2 * i) + 1));
        nume = a * b;
        deno = (2 * i) + 1;
        div = nume / deno;
        sum = div + sum;
    }
    double form = 4 * sum;
    printf("%.10f", form);
    return 0;
}