//
// Created by goat2 on 2023/10/13.
//
//#include<stdio.h>

//int main(void) {
  //  int n;
  //  scanf("%d", &n);
  //  int numbers[100000];
  //  for (int i = 0; i <= n; i++) {
  //      scanf("%d", &numbers[i]);
 //   }
  //  int stand = 0;//总的起立的人
 //   int d = 0;//差值
  //  int perf = 0;//托
 //   for (int i = 0; i < n; i++) {
  //      if ()
  //      stand = perf + stand;
 //       d = (i + 1) - stand;
   //     if (d >= perf) {
//            perf = d;
   //     }
 //   }
//    printf("%d", perf);
 //   return 0;
//}

#include<stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int numbers[100000] = {0};
    for (int i = 0; i <= n; i++) {
        scanf("%d", &numbers[i]);
    }

    int stand = numbers[0];
    int dd = 0;
    int d = 0;
    for (int i = 1; i <= n; i++) {
        if (i <= stand) {
            stand = stand + numbers[i];
        } else {
            if (numbers[i] != 0) {
                dd = i - stand;
                stand = numbers[i] + dd + stand;
                d = dd + d;
            }

        }
    }
    printf("%d", d);
    return 0;
}