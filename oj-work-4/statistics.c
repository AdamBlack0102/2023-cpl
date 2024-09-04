//
// Created by goat2 on 2023/10/26.
//
#include<stdio.h>
#include<string.h>

int n, max, x;
char str[1010];
int bucket[52], ;
int main (void) {
    scanf("%d", &n);
    scanf("%s", str);

   for(int i = 0; i < n; i++) {
       switch (str[i]) {
           case 'a' : bucket[0]++; break;
           case 'A' : bucket[1]++; break;
           case 'b' : bucket[2]++; break;
           case 'B' : bucket[3]++; break;
           case 'c' : bucket[4]++; break;
           case 'C' : bucket[5]++; break;
           case 'd' : bucket[6]++; break;
           case 'D' : bucket[7]++; break;
           case 'e' : bucket[8]++; break;
           case 'E' : bucket[9]++; break;
           case 'f' : bucket[10]++; break;
           case 'F' : bucket[11]++; break;
           case 'g' : bucket[12]++; break;
           case 'G' : bucket[13]++; break;
           case 'h' : bucket[14]++; break;
           case 'H' : bucket[15]++; break;
           case 'i' : bucket[16]++; break;
           case 'I' : bucket[17]++; break;
           case 'j' : bucket[18]++; break;
           case 'J' : bucket[19]++; break;
           case 'k' : bucket[20]++; break;
           case 'K' : bucket[21]++; break;
           case 'l' : bucket[22]++; break;
           case 'L' : bucket[23]++; break;
           case 'm' : bucket[24]++; break;
           case 'M' : bucket[25]++; break;
           case 'n' : bucket[26]++; break;
           case 'N' : bucket[27]++; break;
           case 'o' : bucket[28]++; break;
           case 'O' : bucket[29]++; break;
           case 'p' : bucket[30]++; break;
           case 'P' : bucket[31]++; break;
           case 'q' : bucket[32]++; break;
           case 'Q' : bucket[33]++; break;
           case 'r' : bucket[34]++; break;
           case 'R' : bucket[35]++; break;
           case 's' : bucket[36]++; break;
           case 'S' : bucket[37]++; break;
           case 't' : bucket[38]++; break;
           case 'T' : bucket[39]++; break;
           case 'u' : bucket[40]++; break;
           case 'U' : bucket[41]++; break;
           case 'v' : bucket[42]++; break;
           case 'V' : bucket[43]++; break;
           case 'w' : bucket[44]++; break;
           case 'W' : bucket[45]++; break;
           case 'x' : bucket[46]++; break;
           case 'X' : bucket[47]++; break;
           case 'y' : bucket[48]++; break;
           case 'Y' : bucket[49]++; break;
           case 'z' : bucket[50]++; break;
           case 'Z' : bucket[51]++; break;
       }
   }

    for(int i = 1; i < n; i++) {
        if(bucket[i] == 0) {
            bucket[i] = bucket[i + 1];
        }
       /* if(bucket[i - 1] >= bucket[i]) {
            max = bucket[i - 1];
        } else {
            max = bucket[i];
        }*/
    }

    for (int i = max; i > 0; i--) {
        for(int j = 0; j < n; j++) {
            if(bucket[j] == max) {
                printf("=");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

  /*  for(int i = 0; i < )*/

    return 0;
}