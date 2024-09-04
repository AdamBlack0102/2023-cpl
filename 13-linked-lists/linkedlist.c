//
// Created by goat2 on 2024/1/2.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int val;
    struct node *next;
}Node;

void query(Node *node);
Node *get_node();
void insert_before_head(int x);
void insert(Node *node, int x);

Node *head;
Node *tail;

int main(void) {
    head = get_node();
    tail = head;

    return 0;
}

//如果是结构体指针 就用->; 如果不是指针 就用.
//Node *: 指向Node的指针
void query(Node *node) {
    Node *now = node;
    if(now != NULL) {
        printf("%d", now->val);
        now = now->next;
    }
}

Node *get_node() {
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->val = 0;
    return node;
}

void insert_before_head(int x) {
    Node *cur = (Node *) get_node;
    cur->val = x;
    cur->next = head;
    head = cur;
}

void insert(Node *node, int x) {
    Node *p = get_node();
    p->next = node->next;
    p->val = x;
    node->next = p;
    if(node == NULL) {
        tail = p;
    }
}
