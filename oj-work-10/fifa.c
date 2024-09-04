//
// Created by goat2 on 2023/12/23.
//
#include<stdio.h>
#include<stdlib.h>

#define LEN 150

typedef struct teams {
    char *member;
    char *team;
} Teams;

typedef struct scores {
    int atc[LEN];
    int def[LEN];
    int org[LEN];
} Scores;

typedef struct ptr {
    Teams teams;
    Scores scores;
    double ave_atc;
    double ave_def;
    double ave_org;
} Ptr;

double AVERAGE(const int str[]);

int COMPARE_ATC(const void *a, const void *b);

int COMPARE_DEF(const void *a, const void *b);

int COMPARE_ORG(const void *a, const void *b);

int main(void) {
    int n = 0;
    scanf("%d", &n);

    int x = n;

    Ptr *ptr = (Ptr *) malloc(n * sizeof(Ptr));

    for (int i = 0; i < n; i++) {
        ptr[i].teams.team = (char *) malloc(LEN * sizeof(char));
        scanf("%s", ptr[i].teams.team);
        for (int j = 0; j < 11; j++) {
            ptr[i].teams.member = (char *) malloc(LEN * sizeof(char));
            scanf("%s %d %d %d", ptr[i].teams.member,
                  &ptr[i].scores.atc[j], &ptr[i].scores.def[j],
                  &ptr[i].scores.org[j]);
        }
        ptr[i].ave_atc = AVERAGE(ptr[i].scores.atc);
        ptr[i].ave_def = AVERAGE(ptr[i].scores.def);
        ptr[i].ave_org = AVERAGE(ptr[i].scores.org);
    }

    qsort(ptr, x, sizeof(Ptr), COMPARE_ATC);
    for (int i = 0; i < n; i++) {
        printf("%s ", ptr[i].teams.team);
    }
    printf("\n");
    qsort(ptr, x, sizeof(Ptr), COMPARE_DEF);
    for (int i = 0; i < n; i++) {
        printf("%s ", ptr[i].teams.team);
    }
    printf("\n");
    qsort(ptr, x, sizeof(Ptr), COMPARE_ORG);
    for (int i = 0; i < n; i++) {
        printf("%s ", ptr[i].teams.team);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        free(ptr[i].teams.team);
        free(ptr[i].teams.member);
    }
    free(ptr);

    return 0;
}

double AVERAGE(const int str[]) {
    int sum = 0;
    for (int i = 0; i < LEN; i++) {
        sum += str[i];
    }

    double ave = (double) sum / 11;

    return ave;
}

int COMPARE_ATC(const void *a, const void *b) {
    if (((Ptr *) a)->ave_atc == ((Ptr *) b)->ave_atc) return 0;
    return (((Ptr *) b)->ave_atc > ((Ptr *) a)->ave_atc ? 1 : -1);
}

int COMPARE_DEF(const void *a, const void *b) {
    if (((Ptr *) a)->ave_def == ((Ptr *) b)->ave_def) return 0;
    return (((Ptr *) b)->ave_def > ((Ptr *) a)->ave_def ? 1 : -1);
}

int COMPARE_ORG(const void *a, const void *b) {
    if (((Ptr *) a)->ave_org == ((Ptr *) b)->ave_org) return 0;
    return (((Ptr *) b)->ave_org > ((Ptr *) a)->ave_org ? 1 : -1);
}
