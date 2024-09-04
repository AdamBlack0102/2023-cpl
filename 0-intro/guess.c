//
// Created by goat2 on 2023/9/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
//print the rules
    int high = 100;
    int chance = 7;
            printf("the computer will generate a random number from 1 to %d.\n"
       "you have %d chances to guess.\n",high,chance);

//generate a random number

    srand(time(NULL));
    int random = rand() % high + 1;

    //ask players to enter their guess number
    while(chance > 0) {
    printf("enter your guess number.\n");

    //store the guess number
    int guess;
    scanf("%d", &guess);

    //compare the guess number with the random number
    //loop:repeat the program until guess number == random number
    //tell players the result

    if(random == guess) {printf("you win!\n");
        break;}
        else if(random < guess) {printf("random < guess.\n");}
        else {printf("random > guess.\n");}
        chance = chance - 1;
    }

    printf("you lose!\n");


    return 0;
}







