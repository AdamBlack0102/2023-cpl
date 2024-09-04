//
// Created by goat2 on 2023/12/2.
//
#include<stdio.h>
#include<string.h>

#define LEN 3500

void mystrcat(char *dest, const char *src, int len1,
              int len2, char *cpy_src);

int main(void) {
    int n = 0;
    scanf("%d", &n);
    char dest[LEN] = {0};
    char src[LEN] = {0};
    char cpy_src[LEN] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%s", dest);
        scanf("%s", src);

        int len1 = strlen(dest);
        int len2 = strlen(src);

        mystrcat(dest, src, len1, len2, cpy_src);
    }

    return 0;
}

void mystrcat(char *dest, const char *src, int len1,
              int len2, char *cpy_src) {
    int count = 0;
    int start = strcspn(dest, src);

    int x1 = start, x2 = 0;
    while (start < len1) {
        if (dest[x1++] == src[x2++]) {
            count++;
            if (x1 == len1) {
                break;
            }
        } else {
            count = 0;
            x1 = ++start;
            x2 = 0;
        }
    }


    int x = 0;
    for (int i = count; i < len2; i++) {
        cpy_src[x++] = src[i];
    }

    char ret[LEN] = {0};
    int r = 0;
    for (int i = 0; i < len1; i++) {
        ret[r++] = dest[i];
    }

    for (int i = 0; i < len2 - count; i++) {
        ret[r++] = cpy_src[i];
    }

    ret[r] = '\0';

    printf("%s\n", ret);
//    strcat(dest, cpy_src);
//    int len = strlen(dest);
//    dest[len] = '\0';
//    printf("%s\n", dest);
    memset(cpy_src, 0, sizeof(cpy_src));
}