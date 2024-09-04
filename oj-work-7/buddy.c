//
// Created by goat2 on 2023/11/26.
//
#include<stdio.h>

#define LEN 100005

typedef struct nodes {
    int id;
    int size;
    int next;
} Nodes;

Nodes nodes[LEN] = {0};

int n, q, id, m, idx;
char operation[4] = {0};

void Q();

void MALLOC();

int NEED(int x);

int main(void) {
    scanf("%d%d", &n, &q);
    nodes[0].next = -1;
    nodes[0].id = 0;
    nodes[0].size = n;
    while (q--) {
        scanf("%s", operation);
        if (operation[0] == 'A') {
            scanf("%d%d", &id, &m);
            m = NEED(m);
            MALLOC();
        } else if (operation[0] == 'Q') {
            Q();
        }
    }
    return 0;
}

void Q() {
    int now = 0;
    printf("%d\n", idx + 1);
    while (now != -1) {
        printf("%d ", nodes[now].id);
        now = nodes[now].next;
    }
    printf("\n");
}

void MALLOC() {
    int now = 0;
    while (now != -1) {
        if (nodes[now].size == m && nodes[now].id == 0) {
            break;
        }
        now = nodes[now].next;
    }

    if (now != -1) {
        nodes[now].id = id;
        return;
    }

    now = 0;
    while (now != -1) {
        if (nodes[now].size > m && nodes[now].id == 0) {
            break;
        }
        now = nodes[now].next;
    }

    if (now == -1) {
        return;
    }

    int size = nodes[now].size;
    while (size != m) {
        ++idx;
        nodes[idx].size = size - 1;
        nodes[idx].id = 0;
        nodes[idx].next = nodes[now].next;

        nodes[now].next = idx;
        nodes[now].size = size - 1;
        nodes[now].id = 0;
        size--;
    }

    nodes[now].id = id;


}

int NEED(int x) {
    int result = 0;
    int now = 1;
    while (x > now) {
        now *= 2;
        result++;
    }
    return result;
}






