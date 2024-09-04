//
// Created by goat2 on 2023/11/14.
//
#include<stdio.h>

int COUNT(int n);

int main(void) {
    int n = 0;
    scanf("%d", &n);
    int count = COUNT(n);
    printf("%d", count);

    return 0;
}

int COUNT(int n) {
   if(n == 1 || n == 0) {
       return 1;
   } else {
       return COUNT (n - 1) + COUNT (n - 2);
   }
}