//
// Created by goat2 on 2023/12/30.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
} Stack;

void push(Stack* stack, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        return 0;  // 栈为空，返回0
    }
    Node* temp = stack->top;
    int value = temp->val;
    stack->top = temp->next;
    free(temp);
    return value;
}

int main(void) {
    int n = 0, m = 0;
    scanf("%d%d", &n, &m);

    Stack* stacks = malloc(n * sizeof(Stack));  // 分配n个栈的空间

    // 初始化栈
    for (int i = 0; i < n; i++) {
        stacks[i].top = NULL;
        push(&stacks[i], i + 1);  // 初始时第i个栈中有一个整数i+1
    }

    // 执行m次操作
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x != y) {
            int value = pop(&stacks[x - 1]);
            push(&stacks[y - 1], value);
        }
    }

    // 输出每个栈中的元素
    for (int i = 0; i < n; i++) {
        printf("栈 %d: ", i + 1);
        Node* current = stacks[i].top;
        while (current != NULL) {
            printf("%d ", current->val);
            current = current->next;
        }
        printf("\n");
    }

    // 释放内存
    for (int i = 0; i < n; i++) {
        Node* current = stacks[i].top;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(stacks);

    return 0;
}