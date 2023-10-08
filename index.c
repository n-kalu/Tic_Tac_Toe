#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    printf("\n");

    char circle = ' ';
    char cross = ' ';
    char name[30];
    char ready;
    char lwrReady;
    

    //Trackers

    int turnToPlay = 0;
    int curPlay = 0;
    bool play = true;


    printf("Enter Your Name: ");
    scanf("%s", &name);

    //Clear StdIn buffer. 
    getchar();
    printf("\nWelcome %s. You will be playing against the Computer today.", name);
    printf("\n\nTo play, please enter a cell number. See cell numbers below.\n\n\n");

    printf("       |       |       \n");
    printf("   1   |   2   |   3   \n");
    printf("-------|-------|-------\n");
    printf("       |       |       \n");
    printf("   4   |   5   |   6   \n");
    printf("       |       |       \n");
    printf("-------|-------|-------\n");
    printf("   7   |   8   |   9   \n");
    printf("       |       |       \n");

    //Run the following code while the play still wants to play (i.e if they answer 'Y' to the question "Are you ready to play?").
    while (play)
    {
        printf("\nAre you ready to play? Y/N: ");
        scanf("%c", &ready);
        //Clear StdIn buffer.
        getchar();
        lwrReady = tolower(ready);
        
        if (lwrReady == 'y')
        {
            //Reprint all the cells everytime a player enters a cell number
            while (curPlay < 9)
            { 
                //Transfer control to the other player after a cell number has been entered. Alternate between players. 
                if(turnToPlay % 2 == 0)
                {
                    char cellNumber;
                    printf("Enter Cell Number: ");
                    scanf("%c", &cellNumber);

                    char first, second, third, fourth, fifth, sixth, seventh, eight, ninth;
                    switch (cellNumber)
                    {
                    case '1':
                        first = cellNumber;
                        break;
                    case '2':
                        second = cellNumber;
                        break;
                    case '3':
                        third = cellNumber;
                        break;
                    case '4':
                        fourth = cellNumber;
                        break;
                    case '5':
                        fifth = cellNumber;
                        break;
                    case '6':
                        sixth = cellNumber;
                        break;
                    case '7':
                        seventh = cellNumber;
                        break;
                    case '8':
                        eight = cellNumber;
                        break;
                    case '9':
                        ninth = cellNumber;
                        break;
                    
                    default:
                        break;
                    }

                    // printf("My Turn To Play\n");
                    turnToPlay++;
                }
                else
                {
                    // printf("Computer's Turn To Play\n");
                    turnToPlay++;
                }
                curPlay++;
            }
            
            
        }
        else if(lwrReady == 'n')
        {
            printf("\nNo worries. Thanks for stopping by. Looking forward to playing with you in the future.");
            play = false;
        }
        else
        {
            printf("\nWrong Input. Please ensure to enter 'Y' or 'N'.");
            play = false;
        }

        //Reset Trackers after each play is completed
        curPlay = 0;
    }
    
    
    

////MAY NEED TO CHANGE THIS.


    // printf("\n\n\n       |       |       \n");
    // printf("   %c   |   %c   |   %c  \n", cross, circle, cross);
    // printf("-------|-------|-------\n");
    // printf("       |       |       \n");
    // printf("   %c   |   %c   |   %c  \n", cross, cross, circle);
    // printf("       |       |       \n");
    // printf("-------|-------|-------\n");
    // printf("   %c   |   %c   |   %c  \n", circle, cross, circle);
    // printf("       |       |       \n");



















    // char circle = 'O';
    // char cross = 'X';

    // printf("       |       |       \n");
    // printf("   X   |   O   |   X   \n");
    // printf("-------|-------|-------\n");
    // printf("       |       |       \n");
    // printf("   X   |   X   |   O   \n");
    // printf("       |       |       \n");
    // printf("-------|-------|-------\n");
    // printf("   O   |   O   |   O   \n");
    // printf("       |       |       \n");

    return (0);
    printf("\n");
}