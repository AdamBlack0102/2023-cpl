//
// Created by goat2 on 2023/11/26.
//
#include <stdio.h>
#include <stdbool.h>

#define min(x,y) x<y?x:y

int a0, b0, c0, va, vb, vc;

bool pour(int k, int a, int b, int c);

int main(void) {
    int k = 0, a = 0, b = 0, c = 0;
    scanf("%d%d%d%d%d%d%d%d%d%d", &k, &va, &vb, &vc, &a, &b, &c, &a0, &b0, &c0);
    if(pour(k, a, b, c)) printf("Yes\n");
    else printf("No\n");

    return 0;
}

bool pour(int k, int a, int b, int c) {
    if(a == a0 && b == b0 && c == c0) return true;
    if(k == 0) return false;

    if(pour(k - 1, 0, min(a + b, vb), c) == true) return true;
    if(pour(k - 1, 0, b, min(a + c, vc)) == true) return true;
    if(pour(k - 1, min(a + b, va), 0, c) == true) return true;
    if(pour(k - 1, a, 0, min(b + c, vc)) == true) return true;
    if(pour(k - 1, a, min(c + b, vb), 0) == true) return true;
    if(pour(k - 1, min(a + c, va), b, 0) == true) return true;

    return false;
}
