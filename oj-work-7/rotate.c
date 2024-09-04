//
// Created by goat2 on 2023/11/24.
//
#include<stdio.h>
#include<string.h>

#define LEN 1005

int a = 0, b = 0, c = 0;
int countW = 1, countS = 1,countA = 1,countD = 1;
int con[4] = { 0 };

/*void WW(int A[], int B[], int C[], int D[]);
void SS(int A[], int B[], int C[], int D[]);
void AA(int A[], int B[], int C[], int D[]);
void DD(int A[], int B[], int C[], int D[]);*/
int COMPARE_MAX (int x, int y, int m, int n);
int COMPARE_MIN (int x, int y, int m, int n);
void SORT(int x, int y, int m, int n);

int main (void) {
    char operation[LEN] = { 0 };
    scanf("%d%d%d", &a, &b, &c);
    int A[3] = {a, 0, 0};
    int B[3] = {a, b, 0};
    int C[3] = {0, b, 0};
    int D[3] = {0, 0, 0};
    scanf("%s", operation);
    int len = strlen(operation);

   /* for(int i = 0; i < len; i++) {
        if(operation[i] == 'W') {
            WW(A, B, C, D);
            continue;
        } else if (operation[i] == 'A') {
            AA(A, B, C, D);
            continue;
        } else if (operation[i] == 'S') {
            SS(A, B, C, D);
            continue;
        } else if (operation[i] == 'D') {
            DD(A, B, C, D);
            continue;
        }
    }*/

    int x1 = COMPARE_MIN(A[0], B[0], C[0], D[0]);
    int x2 = COMPARE_MAX(A[0], B[0], C[0], D[0]);
    int y1 = COMPARE_MIN(A[1], B[1], C[1], D[1]);
    int y2 = COMPARE_MAX(A[1], B[1], C[1], D[1]);

    printf("%d %d %d %d", x1, x2, y1, y2);

    return 0;
}
/*void WW(int A[], int B[], int C[], int D[]) {
    switch(countW) {
        case 1: A[0] -= a; A[2] = a;
            B[0] -= a; B[2] = a;
            countW++;
            break;
        case 2: A[0] = A[0] - a - c; A[2] = c;
            B[0] = B[0] - a - c; B[2] = c;
            C[0] -= c; C[2] = c;
            D[0] -= c; D[2] = c;
            countW++;
            break;
        case 3: A[0] -= c; A[2] = 0;
            B[0] -= c; B[2] = 0;
            C[0] = C[0] - a - c; C[2] = a;
            D[0] = D[0] - a - c; D[2] = a;
            countW++;
            break;
        case 4: C[0] -= a; C[2] = 0;
            D[0] -= a; D[2] = 0;
            countW = 1;
            break;
        default: break;
    }
}

void SS(int A[], int B[], int C[], int D[]) {
    switch(countS) {
        case 1: C[0] += a; C[2] = a;
            D[0] += a; D[2] = a;
            countS++;
            break;
        case 2: A[0] += c; A[2] = c;
            B[0] += c; B[2] = c;
            C[0] = C[0] + a + c; C[2] = c;
            D[0] = D[0] + a + c; D[2] = c;
            countS++;
            break;
        case 3: A[0] = A[0] + a + c; A[2] = a;
            B[0] = B[0] + a + c; B[2] = a;
            C[0] += c; C[2] = 0;
            D[0] += c; D[2] = 0;
            countS++;
            break;
        case 4: A[0] += a; A[2] = 0;
            B[0] += a; B[2] = 0;
            countS = 1;
            break;
        default: break;
    }
}

void AA(int A[], int B[], int C[], int D[]) {
    switch(countA) {
        case 1:B[1] -= b; B[2] = b;
            C[1] -= b; C[2] = b;
            countA++;
            break;
        case 2: A[1] -= c; A[2] = c;
            B[1] = B[1] - b - c; B[2] = c;
            C[1] = C[1] - b - c; C[2] = c;
            D[1] -= c; D[2] = c;
            countA++;
            break;
        case 3: A[1] = A[1] - b - c; A[2] = b;
            B[1] -= c; B[2] = 0;
            C[1] -= c; C[2] = 0;
            D[1] = D[1] - b - c; D[2] = b;
            countA++;
            break;
        case 4: A[1] -= b; A[2] = 0;
            D[1] -= b; D[2] = 0;
            countA = 1;
            break;
        default: break;
    }
}

void DD(int A[], int B[], int C[], int D[]) {
    switch(countD) {
        case 1:
            A[1] = b + A[2]; A[2] = b;
            D[1] = b + A[2]; D[2] = b;
            countD++;
            break;
        case 2:
            A[1] = A[1] + b + c; A[2] = c;
            B[1] = c + B[2]; B[2] = c;
            C[1] = c + C[2]; C[2] = c;
            D[1] = D[1] + b + c; D[2] = c;
            countD++;
            break;
        case 3:
            A[1] = c + A[2]; A[2] = 0;
            B[1] = B[1] + b + c; B[2] = b;
            C[1] = C[1] + b + c; C[2] = b;
            D[1] = c + D[2]; D[2] = 0;
            countD++;
            break;
        case 4:
            B[1] = b + B[2]; B[2] = 0;
            C[1] = b + C[2]; C[2] = 0;
            countD = 1;
            break;
        default: break;
    }
}*/

int COMPARE_MIN (int x, int y, int m, int n) {
   SORT(x,y,m,n);
   return con[0];
}

int COMPARE_MAX (int x, int y, int m, int n) {
    SORT(x,y,m,n);
    return con[3];
}

void SORT(int x, int y, int m, int n) {
    con[0] = x; con[1] = y; con[2] = m; con[3] = n;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3 - i; j++) {
            if(con[j] > con[j + 1]) {
                int tmp = con[j];
                con[j] = con[j + 1];
                con[j + 1] = tmp;
            }
        }
    }
}









