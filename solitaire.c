#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    char *rank[] = {"1","2","3","4","5","6","7","8","9","10","J","Q","K"};
    char *symbol[] = {"Heart","Diamond","Club","Spade"};
    int used[52] = {0};
    int r, s, index, count = 0;
    char choice;

    srand(time(NULL));//set the reference base number to current time so random numbers are generated everytime despite formula depencdence of rand()
                      //used NULL as the time isnt to be stored anywhere. prototype: time_t time(time_t *variablename) where time_t is datatype representing 
                      //calender time(number of seconds elapsed with respect to a fixed base).
    printf("********Solitaire Card Game********\n\n");
    printf("%-8s %-8s %-8s %-8s\n", "Heart", "Diamond", "Club", "Spade");
    printf("%-8s %-8s %-8s %-8s\n", "K", "K", "K", "K");
    printf("%-8s %-8s %-8s %-8s\n", "Q", "Q", "Q", "Q");
    printf("%-8s %-8s %-8s %-8s\n", "J", "J", "J", "J");


    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=4;j++)
        {
            printf("%-8d ",i);
        }
        printf("\n");
    }
    while (count < 52) {
        printf("\nPress D to draw, Q to quit: ");
        scanf(" %c", &choice);
        choice=toupper(choice);
        if (choice == 'Q')
            break;

        else if (choice == 'D')
        {
            //shuffle by picking random unused card
            do {
                r = rand() % 13;
                s = rand() % 4;
                index = s * 13 + r;
            } while (used[index]);

            used[index] = 1;
            count++;

            printf("You drew: %s %s\n",symbol[s],rank[r]);
        }
        else{printf("Invalid Input! Retry\n");}
    }

    if (count == 52)
        printf("\nAll cards drawn. Game over!\n");

    return 0;
}
