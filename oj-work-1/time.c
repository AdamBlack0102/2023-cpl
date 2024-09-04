//
// Created by goat2 on 2023/9/23.
//
#include <stdio.h>
int main(void) {
    char month[15];
    int day;
    int year;
    char weekday[10];
    int hour;
    int minute;
    int second;

    scanf("%s %d %d %s %d %d %d", month, &day, &year, weekday, &hour,
           &minute, &second);

    printf("%.3s %.3s %.2d %.2d:%.2d:%.2d %.4d", weekday, month,
           day, hour, minute, second, year);

    return 0;
}