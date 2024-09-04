//
// Created by goat2 on 2023/11/17.
//
#include<stdio.h>

#define LEN 1000

int main(void) {
    int n = 0;
    scanf("%d", &n);
    int str[LEN] = {0};
    int re[LEN] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &str[i]);
    }
    for (int i = 0; i < n; i++) {
        int mid = i;
        int left = i;
        int right = i;
        while (str[mid] > str[right + 1] && right + 1 < n) {
            right++;
        }
        while (str[left - 1] < str[mid] && left >= 0) {
            if (left == 0) {
                break;
            } else {
                left--;
            }
        }

        printf("%d %d\n", left + 1, right + 1);

    }

    return 0;
}

/*void Max (int str[], int left, int right, int re[]) {
    if(left > right) {
        return;
    }
    int mid = left;
    for(int i = left + 1; i < right; i++) {
        if(str[mid] > str[i]) {
            mid = i;
        }
    }
    re[mid] = 1;

    Max(str, left, mid - 1, re);
    Max(str, mid + 1, right, re);

}*/
