//
// Created by goat2 on 2023/9/23.
//
#include <math.h>
#include <stdio.h>
int main(void) {

    double pi = log(640320.0  * 640320.0 * 640320.0 + 744.0) / sqrt(163.0);
    printf("%.15f\n", pi);


    double PI = 4.0 *((4.0 * atan(1.0 / 5.0)) - (atan(1.0 / 239.0)));
    printf("%.15f", PI);

    return 0;
}

