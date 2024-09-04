//
// Created by goat2 on 2023/12/29.
//

// macro (宏)
// header guard
#ifndef GUESS_LL_H
#define GUESS_LL_H

// TODO: adding code here

#include <stdbool.h>

// (1) define data type: circular singly linked list
typedef struct node {
    int val;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
    Node *tail;
} LinkedList;

// (2) functions on liked list (declarations)
void Init(LinkedList *list);
void Free(LinkedList *list);
void Print(const LinkedList *list);

bool IsEmpty(const LinkedList *list);
bool IsSingleton(const LinkedList *list);

void Append(LinkedList *list, int val);
void Delete(LinkedList *list, Node *prev);
void Insert(LinkedList *list, Node *prev, int val);

int GetHeadVal(const LinkedList *list);

#endif //GUESS_LL_H
