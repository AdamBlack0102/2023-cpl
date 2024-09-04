//
// Created by goat2 on 2023/10/17.
//
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

#define MAX_LEN 10020
#define max_len 20

int main(void) {
    bool judge = true;
   /* bool symbol_f = false;*/
    int n = 0;
    scanf("%d", &n);
    getchar();
    int ter = 0, dec = 0, sum = 0;
    char array[MAX_LEN][max_len];
    for (int a = 0; a <= (n - 1); a++) {
        scanf("%s", array[a]);
        int len = strlen(array[a]);
        for (int i = 0; i < len; i++) {
            /*if (array[a][i] == '-') {
                symbol_f = true;
                i++;
                if (array[a][i] == '1') {
                    array[a][i] = 1;
                    ter = pow(3, (len - 1 - i));
                    dec = 1 * ter;
                    sum = dec + sum;
                    continue;
                } else if (array[a][i] == 'Z') {
                    array[a][i] = -1;
                    ter = pow(3, (len - 1 - i));
                    dec = (-1) * ter;
                    sum = dec + sum;
                    continue;
                } else if (array[a][i] == 0) {
                    i = 0;
                    continue;
                } else if (array[a][i] == '0') {
                    array[a][i] = 0;
                    sum = sum;
                    continue;
                } else {
                    array[a][i] = 0;
                    judge = false;
                    printf("Radix Error\n");
                    break;
                }
            } *//*else {*/
                if (array[a][i] == '1') {
                    /*array[a][i] = 1;*/
                    ter = pow(3, (len - 1 - i));
                    dec = 1 * ter;
                    sum = dec + sum;
                    continue;
                } else if (array[a][i] == 'Z') {
                    /*array[a][i] = -1;*/
                    ter = pow(3, (len - 1 - i));
                    dec = (-1) * ter;
                    sum = dec + sum;
                    continue;
                } else if (array[a][i] == 0) {
                    i = 0;
                    continue;
                } /*else if (array[a][i] == '0') {
                    array[a][i] = 0;
                    sum = sum;
                    continue;
                }*/ else if (array[a][i] != '0'){
                    judge = false;
                    printf("Radix Error\n");
                    break;
                }
            //}
        }
       /* if (judge == true && symbol_f == true) {
            printf("%d\n", -sum);
            sum = 0;*/
        //} else
         if (judge == true /*&& *//*symbol_f == false*/) {
            printf("%d\n", sum);
            sum = 0;
        } else {
            break;
        }
    }
    return 0;
}