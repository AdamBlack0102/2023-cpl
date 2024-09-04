//
// Created by goat2 on 2023/12/2.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 1005

char *interleaveString(char *A);

char *all[LEN];

int main(void) {
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        char *A = malloc(LEN);
        scanf("%s", A);
        char *result = interleaveString(A);
        printf("%s\n", result);
        free(A);
        free(result);
    }

    return 0;
}

char *interleaveString(char *A) {
    memset(all, 0, sizeof(all));
    all[0] = strtok(A, ";");
    int x = 0;
    while (all[x++] != NULL) {
        all[x] = strtok(NULL, ";");
    }
    char *s1 = all[0];
    char *s2 = all[1];
    char *ds1_char = all[2];
    char *ds2_char = all[3];
    char *size_char = all[4];

    int size = atoi(size_char);
    int ds1 = atoi(ds1_char);
    int ds2 = atoi(ds2_char);

    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);

    char *s3 = malloc(sizeof(char) * (size + 1));
    char *s3_ptr = s3;
    int len_s3 = 0;

    int count = 0;
    int max_count = 1000;

    while ((s1 != NULL || s2 != NULL) && len_s3 <= size - 1) {
        if (len_s3 <= size - 1 - ds1) {
            int copy_len1 = (len_s1 >= ds1) ? ds1 : len_s1;
            memcpy(s3_ptr, s1, copy_len1);
            s3_ptr += copy_len1;
            len_s3 += copy_len1;
            s1 += copy_len1;
            len_s1 -= copy_len1;
        } else {
            int copy_len1 = (size - 1 - len_s3 >= len_s1) ? len_s1 : size - 1 - len_s3;
            memcpy(s3_ptr, s1, copy_len1);
            s3_ptr += copy_len1;
            len_s3 += copy_len1;
            s1 = NULL;
            break;
        }
        if (len_s3 <= size - 1 - ds2) {
            int copy_len2 = (len_s2 >= ds2) ? ds2 : len_s2;
            memcpy(s3_ptr, s2, copy_len2);
            s3_ptr += copy_len2;
            len_s3 += copy_len2;
            s2 += copy_len2;
            len_s2 -= copy_len2;
        } else {
            int copy_len2 = (size - 1 - len_s3 >= len_s2) ? len_s2 : size - 1 - len_s3;
            memcpy(s3_ptr, s2, copy_len2);
            s3_ptr += copy_len2;
            len_s3 += copy_len2;
            s2 = NULL;
            break;
        }
        if (count >= max_count) {
            break;
        }
        count++;
    }

    if (s1 == NULL && s2 != NULL) {
        int copy_len2 = size - 1 - len_s3;
        if (copy_len2 <= strlen(s2)) {
            memcpy(s3_ptr, s2, copy_len2);
            len_s3 += copy_len2;
        } else {
            memcpy(s3_ptr, s2, strlen(s2));
            len_s3 += strlen(s2);
        }
    } else if (s1 != NULL && s2 == NULL) {
        int copy_len1 = size - 1 - len_s3;
        if (copy_len1 <= strlen(s1)) {
            memcpy(s3_ptr, s1, copy_len1);
            len_s3 += copy_len1;
        } else {
            memcpy(s3_ptr, s1, strlen(s1));
            len_s3 += strlen(s1);
        }

    }
    s3[len_s3] = '\0';

    return s3;
}

