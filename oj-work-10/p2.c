//
// Created by goat2 on 2023/12/29.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 10005

typedef struct num {
    int *coe_p1;
    int *coe_p2;
    int coe_fin;
    int *pow_p1;
    int *pow_p2;
    int pow_fin;
} Num;

void SUM(Num *m, Num *n);
void SUB(Num *m, Num *n);
void MUL(Num *m, Num *n);
int Max(int x, int y);

int p1 = 0, p2 = 0;
char var[LEN];

Num num[LEN] = {0};

int main(void) {
    scanf("%d%d", &p1, &p2);
    scanf("%s", var);
    Num *numbers = (Num *) malloc(LEN * sizeof(Num));
    if (numbers == NULL) return -1;
    memset(numbers, 0, sizeof(struct num));

    numbers->coe_p1 = (int *) malloc((p1 + 1) * sizeof(int));
    numbers->coe_p2 = (int *) malloc((p2 + 1) * sizeof(int));
    numbers->pow_p1 = (int *) malloc((p1 + 1) * sizeof(int));
    numbers->pow_p2 = (int *) malloc((p2 + 1) * sizeof(int));

    for (int i = 0; i <= p1; i++) {
        scanf("%d", &numbers->coe_p1[i]);
    }
    for (int i = 0; i <= p2; i++) {
        scanf("%d", &numbers->coe_p2[i]);
    }

    int x = 0;
    for (int i = p1; i >= 0; i--) {
        numbers->pow_p1[x++] = i;
    }
    x = 0;
    for (int i = p2; i >= 0; i--) {
        numbers->pow_p2[x++] = i;
    }

    SUM(numbers, numbers);
    int max = Max(p1, p2);
    for (int i = 0; i <= max; i++) {
        if (num[i].pow_fin == 0) {
            if (num[i].coe_fin != 0) {
                printf("%d", num[i].coe_fin);
                break;
            } else {
                break;
            }
        } else if (num[i].pow_fin == 1) {
            if (num[i].coe_fin != 1) {
                printf("%d%s", num[i].coe_fin, var);
            } else {
                printf("%s", var);
            }
            if (i < max && num[i + 1].coe_fin > 0) {
                printf("+");
                continue;
            } else {
                continue;
            }
        } else {
            if (num[i].coe_fin != 1) {
                printf("%d%s^%d", num[i].coe_fin, var,
                       num[i].pow_fin);
            } else {
                printf("%s^%d", var,
                       num[i].pow_fin);
            }
        }
        if (i < max && num[i + 1].coe_fin > 0) {
            printf("+");
            continue;
        } else {
            continue;
        }
    }
    printf("\n");

    SUB(numbers, numbers);
    for (int i = 0; i <= max; i++) {
        if (num[i].pow_fin == 0) {
            if (num[i].coe_fin != 0) {
                printf("%d", num[i].coe_fin);
                break;
            } else {
                break;
            }
        } else if (num[i].pow_fin == 1) {
            if (num[i].coe_fin != 1 && num[i].coe_fin != -1) {
                printf("%d%s", num[i].coe_fin, var);
            } else if (num[i].coe_fin == -1) {
                printf("-%s", var);
            } else {
                printf("%s", var);
            }


            if (i < max && num[i + 1].coe_fin > 0) {
                printf("+");
                continue;
            } else {
                continue;
            }

        } else {
            if (num[i].coe_fin != 1) {
                printf("%d%s^%d", num[i].coe_fin, var,
                       num[i].pow_fin);
            } else {
                printf("%s^%d", var,
                       num[i].pow_fin);
            }
        }

        if (i < max && num[i + 1].coe_fin > 0) {
            printf("+");
            continue;
        } else {
            continue;
        }

    }
    printf("\n");

    MUL(numbers, numbers);
    int max2 = p1 + p2;
    for (int i = 0; i <= max2; i++) {
        if (num[i].pow_fin == 0) {
            if (num[i].coe_fin != 0) {
                printf("%d", num[i].coe_fin);
                break;
            } else {
                break;
            }
        } else if (num[i].pow_fin == 1) {
            if (num[i].coe_fin != 1 && num[i].coe_fin != -1) {
                printf("%d%s", num[i].coe_fin, var);
            } else if (num[i].coe_fin == 1) {
                printf("%s", var);
            } else {
                printf("-%s", var);
            }


            if (i < max2 && num[i + 1].coe_fin > 0) {
                printf("+");
                continue;
            } else {
                continue;
            }

        } else {
            if (num[i].coe_fin != 1) {
                printf("%d%s^%d", num[i].coe_fin, var,
                       num[i].pow_fin);
            } else {
                printf("%s^%d", var,
                       num[i].pow_fin);
            }
        }

        if (i < max2 && num[i + 1].coe_fin > 0) {
            printf("+");
            continue;
        } else {
            continue;
        }

    }
    printf("\n");

    free(numbers->coe_p1);
    free(numbers->coe_p2);
    free(numbers->pow_p1);
    free(numbers->pow_p2);
    free(numbers);

    return 0;
}

void SUM(Num *m, Num *n) {
    int x1 = 0, x2 = 0;
    int x = 0;
    int max = Max(p1, p2);
    for (int i = 0; i <= max && x1 <= p1 && x2 <= p2; i++)
        if (m->pow_p1[x1] == n->pow_p2[x2]) {
            num[x].pow_fin = m->pow_p1[x1];
            num[x].coe_fin = m->coe_p1[x1] + n->coe_p2[x2];
            x++;
            x1++;
            x2++;
        } else if (m->pow_p1[x1] > n->pow_p2[x2]) {
            num[x].pow_fin = m->pow_p1[x1];
            num[x].coe_fin = m->coe_p1[x1];
            x++;
            x1++;
        } else {
            num[x].pow_fin = n->pow_p2[x2];
            num[x].coe_fin = m->coe_p2[x2];
            x++;
            x2++;
        }
}

void SUB(Num *m, Num *n) {
    int x1 = 0, x2 = 0;
    int x = 0;
    int max = Max(p1, p2);
    for (int i = 0; i <= max && x1 <= p1 && x2 <= p2; i++) {
        if (m->pow_p1[x1] == n->pow_p2[x2]) {
            num[x].pow_fin = m->pow_p1[x1];
            num[x].coe_fin = m->coe_p1[x1] - n->coe_p2[x2];
            x++;
            x1++;
            x2++;
        } else if (m->pow_p1[x1] > n->pow_p2[x2]) {
            num[x].pow_fin = m->pow_p1[x1];
            num[x].coe_fin = m->coe_p1[x1];
            x++;
            x1++;
        } else {
            num[x].pow_fin = n->pow_p2[x2];
            num[x].coe_fin = n->coe_p2[x2];
            x++;
            x2++;
        }
    }
}

void MUL(Num *m, Num *n) {
    int x = 0;
    for (int i = 0; i <= p1; i++) {
        for (int j = 0; j <= p2; j++) {
            num[x].pow_fin = m->pow_p1[i] + n->pow_p2[j];
            num[x].coe_fin = m->coe_p1[i] * n->coe_p2[j];
            x++;
        }
    }

    for (int i = 0; i < x; i++) {
        if (num[i].coe_fin == 0) {
            continue;
        }
        for (int j = i + 1; j < x; j++) {
            if (num[i].pow_fin == num[j].pow_fin) {
                num[i].coe_fin += num[j].coe_fin;
                num[j].coe_fin = 0;
            }
        }
    }

    int x1 = 0;
    for (int i = 0; i < x; i++) {
        if (num[i].coe_fin != 0) {
            num[x1].pow_fin = num[i].pow_fin;
            num[x1].coe_fin = num[i].coe_fin;
            x1++;
        }
    }

    for (int i = x1; i < x; i++) {
        num[i].pow_fin = 0;
        num[i].coe_fin = 0;
    }
}

int Max(int x, int y) {
    if(x > y) {
        return x;
    } else {
        return y;
    }
}