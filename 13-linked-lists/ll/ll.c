//
// Created by goat2 on 2023/12/29.
//
//<>: 系统路径（安装时）
//"": 先在自己的工程下寻找，如果找不到再去系统路径里面寻找
#include<stdlib.h>
#include <stdio.h>
#include "ll.h"

// TODO: functions on liked list (implementations)

void Init(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
}

void Free(LinkedList *list) {
    while(!IsEmpty((list))) {
        Delete(list, list->head);
    }
}

void Print(const LinkedList *list) {
    if(IsEmpty(list)) {
        return;
    }
    Node *node = list->head;

    do {
        printf("%d", node->val);
        node = node->next;
    } while (node != list->head);

}

void Append(LinkedList *list, int val) {
    Node *node = malloc(sizeof *node);
    if (node == NULL) {
        return;
    }
    node->val = val;      //为val构建一个节点

    if(IsEmpty(list)) {
        list->head = node;
    } else {
        list->tail->next = node;
    }

    list->tail = node;   //不能换顺序
    list->tail->next = list->head;
    //node->next = list->head;    同上，可以替换
}

void Delete(LinkedList *list, Node *prev) {
    if(IsEmpty(list)) {
        return;
    }
    if(IsSingleton(list)) {
        free(list->head);
        Init(list);
        return;
    }
    Node *cur = prev->next;
    Node *next = cur->next;
    prev->next = next;

    if(cur == list->head) {
        list->head = next;
    }

    if(cur == list->tail) {
        list->tail = prev;
    }
    free(cur);
}

int GetHeadVal(const LinkedList *list) {
    if(IsEmpty(list)) {
        return -1;
    }
    return list->head->val;
}

void Insert(LinkedList *list, Node *prev, int val) {

}

bool IsEmpty(const LinkedList *list) {
    return list->head == NULL;
}

bool IsSingleton(const LinkedList *list) {
    return list->head == list->tail;
}
