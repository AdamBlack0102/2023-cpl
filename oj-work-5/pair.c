//
// Created by goat2 on 2023/11/5.
//
#include<stdio.h>

int main(void) {

    int n = 0, m = 0, t = 0;
    int stra[500] = {0};
    int strb[500] = {0};
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &stra[i]);
    }

    int x = t + 1;
    for (int i = 0; i < m; i++) {
        scanf("%d", &strb[i]);
    }

    for (int j = 0; j < m; j++) {
        int low = 0, high = n - 1;
        if (strb[j] >= t) {
            continue;
        } else {
            while (low <= high) {
                int mid = stra[(low + high) / 2];
                int mid_index = (low + high) / 2;
                if (t - mid - strb[j] < x
                && t - mid - strb[j] >= 0) {
                    x = t - mid - strb[j];
                    break;
                }
                if (t - mid - strb[j] > 0) {
                    low = mid_index + 1;
                }else if(t - mid - strb[j] < 0){
                    high = mid_index - 1;
                } else {
                    break;
                }
            }
        }
    }

    if (x == t + 1) {
        printf("-1");
        return 0;
    }else {
        printf("%d", x);
    }

    return 0;
}