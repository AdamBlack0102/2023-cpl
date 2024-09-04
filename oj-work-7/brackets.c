//
// Created by goat2 on 2023/11/23.
//
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 1000

char contents[SIZE];
int top = 0;

int pop() {
    contents[top - 1] = 0;
    return contents[--top];
}

void push(char x) {
    contents[top++] = x;
}

int main(void) {
    int n = 0;
    scanf("%d", &n);
    char operation[SIZE] = {0};

    for (int j = 0; j < n; j++) {
        top = 0;
        scanf("%s", operation);
        int len = strlen(operation);
        bool flag = true;

        for (int i = 0; i < len; i++) {
            if (operation[i] == '(' || operation[i] == '['
                || operation[i] == '{') {
                push(operation[i]);
            } else {
                if (contents[top - 1] == '(') {
                    if (operation[i] == ')') {
                        pop();
                        continue;
                    } else {
                        flag = false;
                        break;
                    }
                } else if (contents[top - 1] == '[') {
                    if (operation[i] == ']') {
                        pop();
                        continue;
                    } else {
                        flag = false;
                        break;
                    }
                } else if (contents[top - 1] == '{') {
                    if (operation[i] == '}') {
                        pop();
                        continue;
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag && top == 0) {
            printf("True\n");
        } else {
            printf("False\n");
        }
    }
    return 0;
}
