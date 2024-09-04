//
// Created by goat2 on 2023/11/23.
//
#include<stdio.h>

#define SIZE 1000

char contents[SIZE];
int top = 0;

void pop(void) {
    if (top == 0) {
        printf("Empty\n");
    } else {
        contents[top] = '\0';
        top--;
    }
}

void TOP(void) {
    if (top == 0) {
        printf("Empty\n");
    } else {
        printf("%c\n", contents[top]);
    }
}

void print(void) {
    if (top == 0) {
        printf("Empty\n");
    } else {
        for (int i = top; i > 0; i--) {
            printf("| %c |\n", contents[i]);
        }
        printf("|===|\n");
    }
}

void push(char x) {
    contents[++top] = x;
}

int main(void) {
    int n = 0;
    scanf("%d", &n);
    char operation[SIZE] = {0};
    char x;

    for (int j = 0; j < n; j++) {
        scanf("%s", &operation[0]);
        if (operation[0] == 'p') {
            if (operation[1] == 'o') {
                pop();
            } else if (operation[1] == 'u') {
                getchar();
                scanf("%c", &x);
                push(x);
            } else {
                print();
            }
        } else {
            TOP();
        }
    }
    return 0;
}
