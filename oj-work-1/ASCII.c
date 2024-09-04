//
// Created by goat2 on 2023/9/23.
//

#include <stdio.h>
int main(void) {
    int n;
    scanf("%d", &n);
    char C = n;
    printf("%d %c\n", n,C);
    char c = C + 'a' - 'A';
    int m = c;
    printf("%d %c\n", m,c);
    return 0;
}



