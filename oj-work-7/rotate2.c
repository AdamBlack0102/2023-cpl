//
// Created by goat2 on 2023/11/26.
//
#include<stdio.h>
#include<string.h>

#define LEN 10005

int a = 0, b = 0, c = 0;
char operation[LEN] = {0};

void ABX_S(int x1, int x2) {
    x2 = x1;
    x1 -= c;
}

void ABX_P(int x1, int x2) {
    x1 = x2;
    x2 += c;
}

void BCX_S(int x1, int x2) {
    x2 = x1;
    x1 -= a;
}

void BCX_P(int x1, int x2) {
    x1 = x2;
    x2 += a;
}

void ACX_S(int x1, int x2) {
    x2 = x1;
    x1 -= b;
}

void ACX_P(int x1, int x2) {
    x1 = x2;
    x2 += b;
}

void ABY_S(int y1, int y2) {
    y2 = y1;
    y1 -= c;
}

void ABY_P(int y1, int y2) {
    y1 = y2;
    y2 += c;
}

void BCY_S(int y1, int y2) {
    y2 = y1;
    y1 -= a;
}

void BCY_P(int y1, int y2) {
    y2 = y1;
    y1 += a;
}

void ACY_S(int y1, int y2) {
    y2 = y1;
    y1 -= b;
}

void ACY_P(int y1, int y2) {
    y2 = y1;
    y1 += b;
}

int main(void) {
    scanf("%d%d%d", &a, &b, &c);
    scanf("%s", operation);
    int len = strlen(operation);

    int x1 = 0, x2 = a, y1 = 0, y2 = b;

    for (int i = 0; i < len; i++) {
        if (operation[i] == 'W') {
            if ((y2 - y1 == b && x2 - x1 == a) || (y2 - y1 == a && x2 - x1 == b)) {
                ABX_S(x1, x2);
            } else if ((y2 - y1 == b && x2 - x1 == c) || (y2 - y1 == c && x2 - x1 == b)) {
                BCX_S(x1, x2);
            } else if ((y2 - y1 == a && x2 - x1 == c) || (y2 - y1 == c && x2 - x1 == a)) {
                ACX_S(x1, x2);
            }

        } else if (operation[i] == 'S') {
            if ((y2 - y1 == b && x2 - x1 == a) || (y2 - y1 == a && x2 - x1 == b)) {
                ABX_P(x1, x2);
            } else if ((y2 - y1 == b && x2 - x1 == c) || (y2 - y1 == c && x2 - x1 == b)) {
                BCX_P(x1, x2);
            } else if ((y2 - y1 == a && x2 - x1 == c) || (y2 - y1 == c && x2 - x1 == a)) {
                ACX_P(x1, x2);
            }
        } else if (operation[i] == 'A') {
            if ((x2 - x1 == b && y2 - y1 == a) || (x2 - x1 == a && y2 - y1 == b)) {
                ABY_S(y1, y2);
            } else if ((x2 - x1 == b && y2 - y1 == c) || (x2 - x1 == c && y2 - y1 == b)) {
                BCY_S(y1, y2);
            } else if ((x2 - x1 == a && y2 - y1 == c) || (x2 - x1 == c && y2 - y1 == a)) {
                ACY_S(y1, y2);
            }
        } else if (operation[i] == 'D') {
            if ((x2 - x1 == b && y2 - y1 == a) || (x2 - x1 == a && y2 - y1 == b)) {
                ABY_P(y1, y2);
            } else if ((x2 - x1 == b && y2 - y1 == c) || (x2 - x1 == c && y2 - y1 == b)) {
                BCY_P(y1, y2);
            } else if ((x2 - x1 == a && y2 - y1 == c) || (x2 - x1 == c && y2 - y1 == a)) {
                ACY_P(y1, y2);
            }

        }
    }

    printf("%d %d %d %d", x1, x2, y1, y2);

    return 0;
}