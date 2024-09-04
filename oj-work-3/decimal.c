//
// Created by goat2 on 2023/10/20.
//
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

int main(void) {
    bool judge = true;
    int len, N;
    scanf("%d%d", &len, &N);
    char str[35] = { 0 };
    for(int i = 0; i < len; i++) {
        scanf("%s", &str[i]);
    }

    for(int i = 0; i < len; i++) {
        if (!isdigit(str[i]) && !isupper(str[i])) {
            printf("Error\n");
            judge = false;
            break;
        }
    }

    for(int i = 0; i < len; i++) {
        if(judge == true) {
            if(len <= 10) {
                int max = len - 1;
                if(str[i] >= '0' && str[i] <= '&max') {

                } else {
                    printf("Error\n");
                    break;
                }
            } else {
                if()
            }
        }
    }



    return 0;
}