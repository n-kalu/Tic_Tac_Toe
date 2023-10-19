#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Operations.h"

int main()
{
    printf("\n");

    char circle = ' ';
    char cross = ' ';
    char name[30];
    char ready;
    char lwrReady;

    bool pTurnToPlay = true;
    bool cTurnToPlay = false;

    int curPlay = 0;
    bool play = true;

    printf("Enter Your Name: ");
    scanf("%s", &name);

    //Clear StdIn buffer. 
    ClearStdinBuffer();

    WelcomeIntro(name);

    PrintCellNumbers();

    // Main Operation.
    MainOp(name, ready, lwrReady, pTurnToPlay, cTurnToPlay, play, curPlay);
    
    return (0);
    printf("\n");
}




