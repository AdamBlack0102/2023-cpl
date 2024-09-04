//
// Created by goat2 on 2023/12/6.
//
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define LEN 1030

char rule[LEN], command[LEN][LEN], rule1[LEN], rule2[LEN];
int m, n;

int main(void) {
    scanf("%s", rule);

    int len = strlen(rule);
    int x2 = 0;
    for (int i = 1; i < len; i++) {
        if (rule[i] == ':') {
            rule2[x2++] = rule[i - 1];
            rule[i - 1] = -1;
            rule[i] = -1;
        }
    }

    int x1 = 0;
    for (int i = 0; i < len; i++) {
        if (rule[i] != -1) {
            rule1[x1++] = rule[i];
        }
    }

    int a = 0;
    while (scanf("%s", command[a++]) != EOF);

    bool flag = true;
    bool legal = true;
    bool cons1 = true;
    bool cons2 = true;
    bool cont1 = true;
    bool cont2 = true;
    int count = 0;
    int len1 = strlen(rule1);
    int len2 = strlen(rule2);
    for (int i = 1; i < a - 1; i++) {

        for (int j = 0; j < strlen(command[i]); j++) {
            legal = false;
            if (command[i][1] == '.') break;
            if (command[i][j] >= 'a' && command[i][j] <= 'z') {
                if (command[i][j + 1] >= 'a' && command[i][j + 1] <= 'z') {
                    break;
                }
                legal = true;
                break;
            }
        }
        cons1 = true;
        cons2 = true;
        x1 = 0;
        x2 = 0;

        if (legal) {
            if (len1 == 0) cons1 = false, cont1 = false;
            if (len2 == 0) cons2 = false, cont2 = false;
            if (cont1)
                while (command[i][1] != rule1[x1++]) {
                    if (x1 == len1) {
                        cons1 = false;
                    }
                }

            if (cont2)
                while (command[i][1] != rule2[x2++]) {
                    if (x2 == len2) {
                        cons2 = false;
                    }
                }

            if (!cons2 && !cons1) {
                printf("%s: invalid option -- '%c'",
                       command[0], command[i][1]);
                return 0;
            }

            if (cons2 && command[i + 1][0] == 0) {
                printf("%s: option requires an argument -- '%c'",
                       command[0], command[i][1]);
                return 0;
            }
        }
    }
    for (int i = 1; i < a - 1; i++) {
        while (1) {
            for (int j = 0; j < strlen(command[i]); j++) {
                legal = false;
                if (command[i][1] == '.') break;
                if (command[i][j] >= 'a' && command[i][j] <= 'z') {
                    if (command[i][j + 1] >= 'a' && command[i][j + 1] <= 'z') {
                        break;
                    }
                    legal = true;
                    break;
                }
            }
            cons1 = true;
            cons2 = true;
            x1 = 0;
            x2 = 0;

            if (legal) {
                if (len1 == 0) cons1 = false;
                if (len2 == 0) cons2 = false;
                while (command[i][1] != rule1[x1++]) {
                    if (x1 == len1) {
                        cons1 = false;
                    }
                }
                while (command[i][1] != rule2[x2++]) {
                    if (x2 == len2) {
                        cons2 = false;
                    }
                }

                if (cons2) {
                    if (flag) {
                        printf("%s\n", command[0]);
                        flag = false;
                    }
                    if (command[i + 1][0] != 0) {
                        printf("%c=%s\n", command[i][1], command[i + 1]);
                        i++;
                    }
                    break;
                } else {
                    if (flag) {
                        printf("%s\n", command[0]);
                        flag = false;
                    }
                    printf("%c\n", command[i][1]);
                    break;
                }
            } else {
                break;
            }
        }
    }
    return 0;
}

