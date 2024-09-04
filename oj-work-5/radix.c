//
// Created by goat2 on 2023/11/2.
//
#include<stdio.h>
#include<string.h>
#include<math.h>

int max = 0;

int MAX(char x[]);

int main(void) {

    char p[3] = {0}, q[3] = {0}, r[3] = {0};
    scanf("%s %s %s", p, q, r);

    int lenp = strlen(p),
            lenq = strlen(q),
            lenr = strlen(r);
//转整数
    for (int i = 0; i < lenp; i++) {
        p[i] -= '0';
    }

    for (int i = 0; i < lenq; i++) {
        q[i] -= '0';
    }

    for (int i = 0; i < lenr; i++) {
        r[i] -= '0';
    }
//求最大的一个数字，以决定最小的进制
    MAX(p);
    MAX(q);
    MAX(r);

    int sp = 0, sq = 0, sr = 0;
//转成一个整数
    if (lenp == 1) {
        sp = p[0];
    } else {
        sp = (p[0] * 10) + p[1];
    }

    if (lenq == 1) {
        sq = q[0];
    } else {
        sq = (q[0] * 10) + q[1];
    }

    if (lenr == 1) {
        sr = r[0];
    } else {
        sr = (r[0] * 10) + r[1];
    }

    int re = 0;
    int sump = 0, sumq = 0, sumr = 0;

    if (max < 1) {
        max = 1;
    }

    for (int n = max + 1; n <= 40; n++) {

        for (int a = 0; a < lenp; a++) {
            re = p[a] * pow(n, (lenp - 1.0 - a));
            sump += re;
            sump = sp;
        }

        for (int b = 0; b < lenq; b++) {
            re = q[b] * pow(n, (lenq - 1.0 - b));
            sumq += re;
            sumq = sq;
        }

        for (int i = 0; i < lenr; i++) {
            re = r[i] * pow(n, (lenr - 1.0 - i));
            sumr += re;
            sumr = sr;
        }

        if (sump * sumq == sumr) {
            printf("%d", n);
            return 0;
        }
    }

    printf("0");

    return 0;
}

int MAX(char x[]) {
    int len = strlen(x);
    for (int i = 0; i < len; i++) {
        if (x[i] > max) {
            max = x[i];
        }
    }
    return max;
}


