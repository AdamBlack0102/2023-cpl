//
// Created by goat2 on 2023/12/30.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *next;
} Node;

typedef struct list{
    Node **head;
    Node **tail;
} LinkedList;

int main(void) {
    int n = 0, m = 0, x = 0, y = 0;
    scanf("%d%d", &n, &m);
    LinkedList *list = malloc(n * sizeof (LinkedList));
    for(int i = 1; i <= n; i++) {
        list[i].head = malloc(sizeof(Node*));
        list[i].tail = malloc(sizeof(Node*));
        list->head = NULL;
        list->tail = NULL;
        Node *node = malloc(sizeof(Node));
        node->val = i;
        node->next = NULL;
        *list->head = node;
    }

    return 0;
}