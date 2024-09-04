//
// Created by goat2 on 2023/11/29.
//
//arr[i] == *(arr + i)
#include<stdio.h>
#include<string.h>
#include<malloc.h>

int main(void) {
    char *arr = malloc(4096 * sizeof(arr));

    if (arr == NULL) {
        return 0;
    }

    gets(arr);

    char *pointer = arr;

    if (*pointer >= 'a' && *pointer <= 'z') {
        *arr = *arr - 'a' + 'A';
        pointer++;
    }

    for (int x = 1; x < 4096; x++) {
        if (*(arr + x) >= 'a' && *(arr + x) <= 'z' && *(arr + (x - 1)) == ' ') {
            *(arr + x) = *(arr + x) - 'a' + 'A';
            pointer++;
        } else if (*(arr + x) >= 'A' && *(arr + x) <= 'Z' && *(arr + (x - 1)) != ' ') {
            *(arr + x) = *(arr + x) + 'a' - 'A';
            pointer++;
        }
    }
    printf("%s", arr);
    return 0;
}
