//
// Created by goat2 on 2023/9/23.
//要求用户输入一个软妹币数额，然后显示出如何用最少张数的50软妹币，20软妹币、10软妹币、5软妹币和1软妹币钞票来付款

#include <stdio.h>
int main(void){
    int n;
    const int ONE = 50;
    const int TWO = 20;
    const int THREE = 10;
    const int FOUR = 5;

    scanf("%d", &n);
    int first = n / ONE;
    printf("%d\n", first);

    int second = (n - (first * ONE)) / TWO;
    printf("%d\n", second);

    int third = (n - (first * ONE) - (second * TWO)) / THREE;
    printf("%d\n", third);

    int forth = (n - (first * ONE) - (second * TWO) - (third * THREE)) / FOUR;
    printf("%d\n", forth);

    int fifth = (n - (first * ONE) - (second * TWO) - (third * THREE) - (forth * FOUR));
    printf("%d\n", fifth);


    return 0;

}
