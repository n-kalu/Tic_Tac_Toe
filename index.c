#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

void ClearStdinBuffer();
void PrintCellNumbers();
char RegisterPlayedCell(char cNumber, int tPlay);
void DisplayEmptyCells();

char fst = ' ';
char snd = ' ';
char thd = ' ';
char fth = ' ';
char fif = ' ';
char six = ' ';
char sev = ' ';
char eit = ' ';
char nit = ' ';

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
    //Track cell count after each game
    // int oddCellCount = 0;
    int evenCellCount = 0;


    printf("Enter Your Name: ");
    scanf("%s", &name);

    //Clear StdIn buffer. 
    ClearStdinBuffer();

    printf("\nWelcome %s. You will be playing against the Computer today.", name);
    printf("\n\nTo play, please enter a cell number. See cell numbers below.\n\n");
    printf("NOTE: Your entry shows up as 'X' and the computer's entry shows up as 'O'.\n\n\n");

    PrintCellNumbers();

    //Run the following code while the play still wants to play (i.e if they answer 'Y' to the question "Are you ready to play?").
    while (play)
    {
        printf("\nStart New Game? Y/N: ");
        scanf("%c", &ready);

        //Clear StdIn buffer.
        ClearStdinBuffer();
        lwrReady = tolower(ready);
        
        if (lwrReady == 'y')
        {
            //Check cell count after each game and refresh page when 
            if(turnToPlay == (evenCellCount * 9))
            {
                printf("\e[1;1H\e[2J");
                PrintCellNumbers();
                DisplayEmptyCells();
            }

            //Reprint all the cells everytime a player enters a cell number
            while (curPlay < 9)
            { 
                //Check cell count after each game to refresh page
                // if(turnToPlay == (9 * oddCellCount))
                // {
                //     //reset turnToPlay
                //     // turnToPlay = 0;
                //     //Regex to clear Console
                //     printf("\e[1;1H\e[2J");
                //     PrintCellNumbers();
                // }
                // if(turnToPlay == (18 * evenCellCount))
                // {
                //     printf("\e[1;1H\e[2J");
                //     PrintCellNumbers();
                // }

                //Transfer control to the other player after a cell number has been entered. Alternate between players. 
                if(turnToPlay % 2 == 0)
                {
                    char cellNumber;
                    printf("\nEnter Cell Number: ");
                    scanf("%c", &cellNumber);

                    //Clear StdIn buffer.
                    ClearStdinBuffer();

                    char first, second, third, fourth, fifth, sixth, seventh, eight, ninth;
                    switch (cellNumber)
                    {
                    case '1':
                        first = cellNumber;

                        //Regex to clear Console
                        printf("\e[1;1H\e[2J");
                        PrintCellNumbers();
                        RegisterPlayedCell(first, turnToPlay);

                        break;
                    case '2':
                        second = cellNumber;

                        //Regex to clear Console
                        printf("\e[1;1H\e[2J");
                        PrintCellNumbers();
                        RegisterPlayedCell(second, turnToPlay);

                        break;
                    case '3':
                        third = cellNumber;

                        //Regex to clear Console
                        printf("\e[1;1H\e[2J");
                        PrintCellNumbers();
                        RegisterPlayedCell(third, turnToPlay);

                        break;
                    case '4':
                        fourth = cellNumber;
                        //Regex to clear Console
                        printf("\e[1;1H\e[2J");
                        PrintCellNumbers();
                        RegisterPlayedCell(fourth, turnToPlay);

                        break;
                    case '5':
                        fifth = cellNumber;

                        //Regex to clear Console
                        printf("\e[1;1H\e[2J");
                        PrintCellNumbers();
                        RegisterPlayedCell(fifth, turnToPlay);

                        break;
                    case '6':
                        sixth = cellNumber;

                        //Regex to clear Console
                        printf("\e[1;1H\e[2J");
                        PrintCellNumbers();
                        RegisterPlayedCell(sixth, turnToPlay);

                        break;
                    case '7':
                        seventh = cellNumber;

                        //Regex to clear Console
                        printf("\e[1;1H\e[2J");
                        PrintCellNumbers();
                        RegisterPlayedCell(seventh, turnToPlay);

                        break;
                    case '8':
                        eight = cellNumber;

                        //Regex to clear Console
                        printf("\e[1;1H\e[2J");
                        PrintCellNumbers();
                        RegisterPlayedCell(eight, turnToPlay);

                        break;
                    case '9':
                        ninth = cellNumber;

                        //Regex to clear Console
                        printf("\e[1;1H\e[2J");
                        PrintCellNumbers();
                        RegisterPlayedCell(ninth, turnToPlay);

                        break;
                    
                    default:
                    printf("\nWrong Input. Please ensure to enter 'Y' or 'N'.");
                        break;
                    }

                    // printf("My Turn To Play\n");
                    turnToPlay++;
                }
                else
                {
                    // printf("Computer's Turn To Play\n");

                    //Regex to clear Console
                    printf("\e[1;1H\e[2J");
                    PrintCellNumbers();
                    RegisterPlayedCell(5, turnToPlay);

                    turnToPlay++;
                }
                curPlay++;
            }
            
            
        }
        else if(lwrReady == 'n')
        {
            printf("\nNo worries. Looking forward to playing with you in the future.");
            play = false;
        }
        else
        {
            printf("\nWrong Input. Please ensure to enter 'Y' or 'N'.");
            play = false;
        }

        //Reset Trackers after each play is completed
        curPlay = 0;
        //increment cellCount
        // oddCellCount += 2;
        evenCellCount++;
        
        //Reset Variables
        fst = ' ';
        snd = ' ';
        thd = ' ';
        fth = ' ';
        fif = ' ';
        six = ' ';
        sev = ' ';
        eit = ' ';
        nit = ' ';
    }
    
    return (0);
    printf("\n");
}


// FUNCTIONS//
void ClearStdinBuffer()
{
    while (getchar() != '\n')
    {
        
    }
    
}

void PrintCellNumbers()
{
    printf("      CELL NUMBERS\n\n");
    printf("       |       |       \n");
    printf("   1   |   2   |   3   \n");
    printf("-------|-------|-------\n");
    printf("       |       |       \n");
    printf("   4   |   5   |   6   \n");
    printf("       |       |       \n");
    printf("-------|-------|-------\n");
    printf("   7   |   8   |   9   \n");
    printf("       |       |       \n");
}


char RegisterPlayedCell(char cNumber, int tPlay)
{

    if(tPlay % 2 > 0)
    {
        fif = 'O';

        printf("\n\n      CURRENT GAME");
        printf("\n\n       |       |       \n");
        printf("   %c   |   %c   |   %c  \n", fst, snd, thd);
        printf("-------|-------|-------\n");
        printf("       |       |       \n");
        printf("   %c   |   %c   |   %c  \n", fth, fif, six);
        printf("       |       |       \n");
        printf("-------|-------|-------\n");
        printf("   %c   |   %c   |   %c  \n", sev, eit, nit);
        printf("       |       |       \n");
    }
    if(tPlay % 2 == 0)
    {
        //Player's turn to play

        if (cNumber == '1')
        {
            fst = 'X';
        }
        else if (cNumber == '2')
        {
            snd = 'X';
        }
        else if (cNumber == '3')
        {
            thd = 'X';
        }
        else if (cNumber == '4')
        {
            fth = 'X';
        }
         else if (cNumber == '5')
        {
            fif = 'X';
        }
         else if (cNumber == '6')
        {
            six = 'X';
        }
         else if (cNumber == '7')
        {
            sev = 'X';
        }
         else if (cNumber == '8')
        {
            eit = 'X';
        }
        else
        {
            nit = 'X';
        }
        
        printf("\n\n      CURRENT GAME");
        printf("\n\n       |       |       \n");
        printf("   %c   |   %c   |   %c  \n", fst, snd, thd);
        printf("-------|-------|-------\n");
        printf("       |       |       \n");
        printf("   %c   |   %c   |   %c  \n", fth, fif, six);
        printf("       |       |       \n");
        printf("-------|-------|-------\n");
        printf("   %c   |   %c   |   %c  \n", sev, eit, nit);
        printf("       |       |       \n");
    }
    
}

void DisplayEmptyCells()
{
    printf("\n\n      CURRENT GAME");
    printf("\n\n       |       |       \n");
    printf("       |       |       \n");
    printf("-------|-------|-------\n");
    printf("       |       |       \n");
    printf("       |       |       \n");
    printf("       |       |       \n");
    printf("-------|-------|-------\n");
    printf("       |       |       \n");
    printf("       |       |       \n");
}




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