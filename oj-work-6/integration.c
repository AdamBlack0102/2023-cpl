//
// Created by goat2 on 2023/11/21.
//
#include<stdio.h>
#include<math.h>

#define LEN 25

double str[LEN] = {0};
int n = 0, p = 0;

double Simpson(double a, double e, double b);

double Function(double x);

int main(void) {
    double a = 0.0, b = 0.0;
    scanf("%d%d", &n, &p);
    for (int i = 0; i <= n; i++) {
        scanf("%lf", &str[i]);
    }
    scanf("%lf%lf", &a, &b);

    double e = 0.0001;
    printf("%lf", Simpson(a, e, b));

    return 0;
}

double Function(double x) {
    double sum = 0.0;
    for (int i = 0; i <= n; i++) {
        sum += (double)str[i] * pow(x, i);
    }
    if(p == 2) {
        sum *= sum;
    } else if (p == -1) {
        sum = 1.0 / sum;
    } else if (p == -2) {
        sum = 1.0 / (sum * sum);
    } else {
        sum = sum;
    }

    return sum;
}

double Simpson(double a, double e, double b) {
    double mid = (a + b) / 2.0;

    double S = ((b - a) * (4.0 * Function(mid)
                          + Function(a) + Function(b))) / 6.0;
    double SL = ((mid - a) * (4.0 * Function((a + mid) / 2.0)
                             + Function(a) + Function(mid))) / 6.0;
    double SR = ((b - mid) * (4.0 * Function((mid + b) / 2.0)
                             + Function(b) + Function(mid))) / 6.0;

    if (fabs(SL + SR - S) <= 15 * e) {
        return SL + SR + ((SL + SR - S) / 15.0);
    } else {
        double left = Simpson(a, (e / 2.0), mid);
        double right = Simpson(mid, (e / 2.0), b);
        return left + right;
    }
}