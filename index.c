#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void ClearStdinBuffer();
void PrintCellNumbers();
char RegisterPlayedCell(int currentPlay, char cNumber, bool pToPlay, bool cToPlay);
void DisplayEmptyCells();
void Result(bool pToPlay, bool cToPlay, char playerName[30]);
void PrintResult(char pName[30]);

char cellEntry[3][4] = {{' ', ' ', ' ', '\0'}, {' ', ' ', ' ', '\0'}, {' ', ' ', ' ', '\0'}};

//Tracker for number of times the Player and the Computer won or had a draw. 
int pNoWins = 0;
int cNoWins = 0;
int noDraws = 0;

//Bool Variable to confirm win or lose
bool isGameWon = false;

//Variable to track when the computer has a pathway to win
bool computerPathwayToWin = true;

//Tracks current game being played to determine if it's odd or even. E.g. First game is even, second game is odd, etc. 
int oddEvenGame = 0;


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

    printf("\nWelcome %s. You will be playing against the Computer today.", strupr(name));
    printf("\n\nTo play, please enter a cell number. See cell numbers below.\n\n");
    printf("NOTE: Your entry will show up as 'X' and the computer's entry will show up as 'O'.\n\n\n");

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
            //Refresh page after each game 
            if(pTurnToPlay)
            {
                printf("\e[1;1H\e[2J");
                PrintCellNumbers();
                DisplayEmptyCells();
            }

            //Reprint all the cells everytime a player enters a cell number
            while (curPlay < 9)
            { 
                //Transfer control to the other player after a cell number has been entered. Alternate between players. 
                if(pTurnToPlay)
                {
                    char cellNumber;
                    printf("\nEnter Cell Number: ");
                    scanf("%c", &cellNumber);
                    

                    //Check for input errors when the player/user tries to enter the cell number. 
                    if(cellNumber == '1' || cellNumber == '2'|| cellNumber == '3'|| cellNumber == '4'|| cellNumber == '5'|| cellNumber == '6'|| cellNumber == '7'|| cellNumber == '8'|| cellNumber == '9')
                    {
                        // Do Nothing.
                    }
                    else
                    {
                        ClearStdinBuffer();
                        printf("\nERROR: Wrong input! Please enter only numbers(1 - 9) corresponding to the cell of your choice.\n");
                        continue;
                    }

                    //Clear StdIn buffer.
                    ClearStdinBuffer();

                    char first, second, third, fourth, fifth, sixth, seventh, eight, ninth;
                    switch (cellNumber)
                    {
                    case '1':
                        //Check if the cell already has an entry. This is to avoid double entry into the same cell. 
                        if (cellEntry[0][0] != ' ')
                        {
                            printf("\nERROR: This cell already has an entry. Please choose an empty cell.\n");
                            continue;
                        }
                        else
                        {
                            first = cellNumber;

                            //Regex to clear Console
                            printf("\e[1;1H\e[2J");
                            PrintCellNumbers();
        
                            RegisterPlayedCell(curPlay, first, pTurnToPlay, cTurnToPlay);

                            //Display Result if there is a match
                            Result(pTurnToPlay, cTurnToPlay, name);
                        }                     
                        break;

                    case '2':
                       
                        //Check if the cell already has an entry. This is to avoid double entry into the same cell. 
                        if (cellEntry[0][1] != ' ')
                        {
                            printf("\nERROR: This cell already has an entry. Please choose an empty cell.\n");
                            continue;
                        }
                        else
                        {
                            second = cellNumber;

                            //Regex to clear Console
                            printf("\e[1;1H\e[2J");
                            PrintCellNumbers();
                
                            RegisterPlayedCell(curPlay, second, pTurnToPlay, cTurnToPlay);

                            //Display Result if there is a match
                            Result(pTurnToPlay, cTurnToPlay, name);
                        }
                        break;

                    case '3':

                        //Check if the cell already has an entry. This is to avoid double entry into the same cell. 
                        if (cellEntry[0][2] != ' ')
                        {
                            printf("\nERROR: This cell already has an entry. Please choose an empty cell.\n");
                            continue;
                        }
                        else
                        {
                            third = cellNumber;

                            //Regex to clear Console
                            printf("\e[1;1H\e[2J");
                            PrintCellNumbers();
                            
                            RegisterPlayedCell(curPlay, third, pTurnToPlay, cTurnToPlay);

                            //Display Result if there is a match
                            Result(pTurnToPlay, cTurnToPlay, name);
                        }
                        break;

                    case '4':

                        //Check if the cell already has an entry. This is to avoid double entry into the same cell. 
                        if (cellEntry[1][0] != ' ')
                        {
                            printf("\nERROR: This cell already has an entry. Please choose an empty cell.\n");
                            continue;
                        }
                        else
                        {
                            fourth = cellNumber;

                            //Regex to clear Console
                            printf("\e[1;1H\e[2J");
                            PrintCellNumbers();
                        
                            RegisterPlayedCell(curPlay, fourth, pTurnToPlay, cTurnToPlay);

                            //Display Result if there is a match
                            Result(pTurnToPlay, cTurnToPlay, name);
                        }
                        break;
                        
                    case '5':

                        //Check if the cell already has an entry. This is to avoid double entry into the same cell. 
                        if (cellEntry[1][1] != ' ')
                        {
                            printf("\nERROR: This cell already has an entry. Please choose an empty cell.\n");
                            continue;
                        }
                        else
                        {
                            fifth = cellNumber;

                            //Regex to clear Console
                            printf("\e[1;1H\e[2J");
                            PrintCellNumbers();
                        
                            RegisterPlayedCell(curPlay, fifth, pTurnToPlay, cTurnToPlay);

                            //Display Result if there is a match
                            Result(pTurnToPlay, cTurnToPlay, name);
                        }
                        break;

                    case '6':

                        //Check if the cell already has an entry. This is to avoid double entry into the same cell. 
                        if (cellEntry[1][2] != ' ')
                        {
                            printf("\nERROR: This cell already has an entry. Please choose an empty cell.\n");
                            continue;
                        }
                        else
                        {
                            sixth = cellNumber;

                            //Regex to clear Console
                            printf("\e[1;1H\e[2J");
                            PrintCellNumbers();
                            
                            RegisterPlayedCell(curPlay, sixth, pTurnToPlay, cTurnToPlay);

                            //Display Result if there is a match
                            Result(pTurnToPlay, cTurnToPlay, name);
                        }
                        break;

                    case '7':

                        //Check if the cell already has an entry. This is to avoid double entry into the same cell. 
                        if (cellEntry[2][0] != ' ')
                        {
                            printf("\nERROR: This cell already has an entry. Please choose an empty cell.\n");
                            continue;
                        }
                        else
                        {
                            seventh = cellNumber;

                            //Regex to clear Console
                            printf("\e[1;1H\e[2J");
                            PrintCellNumbers();

                            RegisterPlayedCell(curPlay, seventh, pTurnToPlay, cTurnToPlay);

                            //Display Result if there is a match
                            Result(pTurnToPlay, cTurnToPlay, name);
                        }
                        break;

                    case '8':

                        //Check if the cell already has an entry. This is to avoid double entry into the same cell. 
                        if (cellEntry[2][1] != ' ')
                        {
                            printf("\nERROR: This cell already has an entry. Please choose an empty cell.\n");
                            continue;
                        }
                        else
                        {
                            eight = cellNumber;

                            //Regex to clear Console
                            printf("\e[1;1H\e[2J");
                            PrintCellNumbers();
                        
                            RegisterPlayedCell(curPlay, eight, pTurnToPlay, cTurnToPlay);

                            //Display Result if there is a match
                            Result(pTurnToPlay, cTurnToPlay, name);
                        }
                        break;

                    case '9':

                        //Check if the cell already has an entry. This is to avoid double entry into the same cell. 
                        if (cellEntry[2][2] != ' ')
                        {
                            printf("\nERROR: This cell already has an entry. Please choose an empty cell.\n");
                            continue;
                        }
                        else
                        {
                            ninth = cellNumber;

                            //Regex to clear Console
                            printf("\e[1;1H\e[2J");
                            PrintCellNumbers();
                            
                            RegisterPlayedCell(curPlay, ninth, pTurnToPlay, cTurnToPlay);

                            //Display Result if there is a match
                            Result(pTurnToPlay, cTurnToPlay, name);
                        }             
                        break;
                    
                    default:
                    printf("\nERROR: Wrong Input. Please ensure to enter 'Y' or 'N'.\n");
                        break;
                    }                    
                    
                    //Check if the Player or the Computer Won the game
                    if (isGameWon)
                    { 
                        //Reset isGameWon
                        isGameWon = false;
                        //break out of the loop
                        break;
                    }

                     //Reset variables
                    pTurnToPlay = false;
                    cTurnToPlay = true;
                }
                else if(cTurnToPlay = true)
                {
                    //Regex to clear Console
                    printf("\e[1;1H\e[2J");
                    PrintCellNumbers();

                    //Set the second parameter "cNumber" to a default value of '0' as it is not required for calculations here
                    RegisterPlayedCell(curPlay, 0, pTurnToPlay, cTurnToPlay);

                    //Display Result if there is a match
                    Result(pTurnToPlay, cTurnToPlay, name);

                    //Check if the Player or the Computer Won the game
                    if (isGameWon)
                    { 
                        //Reset isGameWon
                        isGameWon = false;

                        //break out of the loop
                        break;
                    }

                    //Reset variables
                    pTurnToPlay = true;
                    cTurnToPlay = false;
                }

                //Increment curPlay
                curPlay++;
            }
            
            
        }
        else if(lwrReady == 'n')
        {
            printf("\nNo worries. Looking forward to playing with you in the future.\n\n\n\n");
            play = false;
        }
        else
        {
            printf("\nERROR: Wrong Input. Please ensure to enter 'Y' or 'N'.");
            play = false;
        }

        //Reset Trackers after each play is completed
        curPlay = 0;

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cellEntry[i][j] = ' ';
            }
            
        }

        //Alternate whose turn it is to play after each game is won. 
        if(oddEvenGame % 2 == 0)
        {
            //Reset variables
            pTurnToPlay = false;
            cTurnToPlay = true;

            // increment oddEvenGame
            oddEvenGame++;
        }
        else
        {
            //Reset variables
            pTurnToPlay = true;
            cTurnToPlay = false;

            // increment oddEvenGame
            oddEvenGame++;
        }
                         
    }
    
    return (0);
    printf("\n");
}

// *************************************************************************************************************************************************** //
// FUNCTIONS //

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

char RegisterPlayedCell(int currentPlay, char cNumber, bool pToPlay, bool cToPlay)
{
    if(cToPlay)
    {
        if(currentPlay < 2)
        {
            bool valueAssigned = false;
            //Code for when the computer is the first person to play or the second person to play. In other words, "currentPlay" < 2
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    //Go through each cell to determine which cell has already been selected. Set choose the center cell if it has not been chosen yet. A little bias don't hurt nobody. lol. 
                    if (cellEntry[i][j] == 'X')
                    {
                        if (i == 1 && j == 1 )
                        {
                            // Do nothing
                            
                        }
                        else
                        {
                            cellEntry[1][1] = 'O';
                            valueAssigned = true;
                            //Break out of this loop(1st) if valueAssigned is 'true'
                            break;
                        }
                    }
                }
                //Break out of this loop(2nd) if valueAssigned is 'true'. Also reset valueAssigned.
                if(valueAssigned == true)
                {
                    //Reset "valueAssigned"
                    valueAssigned = false;
                    break;
                } 

                if(i == 2 && valueAssigned == false)
                {
                    //Set seed for random number
                    srand(time(NULL));
                    int x;
                    int y;
                    while ((x = rand() % 2) < 10 && (y = rand() % 2) < 10)
                    {
                        if (cellEntry[x][y] == 'X')
                        {
                            // Do Nothing.
                        }
                        else
                        {
                            cellEntry[x][y] = 'O';
                            break;
                        }
                        
                    }
                }
                
            }
        }
        else
        {
            if(computerPathwayToWin == true)
            {
                //Check if the computer has a pathway to win(In other words, are there two cells already containing entries by the computer and are
                //those two cells in a single row, column or diagonal?). If this is the case, then fill in the last cell in the row, column or 
                //diagonal to win the game. 

                int k = 0;
                int l = 1;
                int m = 2;
                int n = 2;

                //Track/check when col 1, 2 and 3 have two matching entries from the computer
                int computerIMatchCounterCol1 = 0;
                int computerIMatchCounterCol2 = 0;
                int computerIMatchCounterCol3 = 0;

                //Track/check when the left diagonal and right diagonal have two matching entries from the computer
                int computerIMatchCounterLDia = 0;
                int computerIMatchCounterRDia = 0;

                //Track/check when row 1, 2 and 3 have two matching entries from the computer
                int computerJMatchCounter = 0;


                //Track/check when two matching entries from the computer is found. 
                bool computerIMatchFound = false;
                bool computerJMatchFound = false;


                for(int i = 0; i < 3; i++)
                {
                    //run through row 1 - 3
                    for(int j = 0; j < 3; j++)
                    {        
                        //[ROW 1] [i][j]
                        // Check if the other player has 2 matching entries('X') in row 1
                        if(i == 0)
                        {
                            if(cellEntry[i][j] == 'O')
                            {
                                //For Row 1, increment computerJMatchCounter by 1 everytime an 'O' is found.
                                computerJMatchCounter++;
                            }

                            //When there are two cells in row 1 that have the value 'O' already entered by the computer, if the third cell is empty,
                            //insert 'O' to complete the row to win the game.   
                            if(computerJMatchCounter == 2 && j == 2)
                            {
                                for(int a = 0; a < 3; a++)
                                {
                                    if(cellEntry[i][a] == ' ')
                                    {
                                        cellEntry[i][a] = 'O';
                                        computerJMatchCounter = 0;
                                        computerJMatchFound = true;
                                        break;
                                    }
                                }
                            }
                            
                        }

                        //[ROW 2] [i][j]
                        //Run only if a match of two entries from the other user has not been found yet.
                        if(computerJMatchFound == false)
                        {
                            // Check if the other player has 2 matching entries('X') in row 2
                            if(i == 1)
                            {
                                if(cellEntry[i][j] == 'O')
                                {
                                    //For Row 1, increment computerJMatchCounter by 1 everytime an 'O' is found.
                                    computerJMatchCounter++;
                                }

                                //When there are two cells in row 2 that have the value 'O' already entered by the computer, if the third cell is empty,
                                //insert 'O' to complete the row to win the game.   
                                if(computerJMatchCounter == 2 && j == 2)
                                {
                                    for(int a = 0; a < 3; a++)
                                    {
                                        if(cellEntry[i][a] == ' ')
                                        {
                                            cellEntry[i][a] = 'O';
                                            computerJMatchCounter = 0;
                                            computerJMatchFound = true;
                                            break;
                                        }
                                    }
                                }
                                
                            }
                        }
    
                        //[ROW 3] [i][j]
                        //Run only if a match of two entries from the other user has not been found yet. 
                        if(computerJMatchFound == false)
                        {
                            // Check if the other player has 2 matching entries('X') in row 3
                            if(i == 2)
                            {
                                if(cellEntry[i][j] == 'O')
                                {
                                    //For Row 1, increment computerJMatchCounter by 1 everytime an 'O' is found.
                                    computerJMatchCounter++;
                                }

                                //When there are two cells in row 3 that have the value 'O' already entered by the computer, if the third cell is empty,
                                //insert 'O' to complete the row to win the game.   
                                if(computerJMatchCounter == 2 && j == 2)
                                {
                                    for(int a = 0; a < 3; a++)
                                    {
                                        if(cellEntry[i][a] == ' ')
                                        {
                                            cellEntry[i][a] = 'O';
                                            computerJMatchCounter = 0;
                                            computerJMatchFound = true;
                                            break;
                                        }
                                    }
                                }
                                
                            }
                        }
    
                        //Reset computerJMatchCounter after each row iteration is complete.
                        if(j == 2)
                        {
                            computerJMatchCounter = 0;
                        }
                    }

                    if (computerJMatchFound == true)
                    {
                        break;
                    }
                    

                    //[COL 1] [i][k] - Computer
                    //Run only if a match of two entries from the other user has not been found yet.
                    if(computerIMatchFound == false)
                    {
                        // Check if the other player has 2 matching entries('X') in col 1

                        if(cellEntry[i][k] == 'O')
                        {
                            //For col 1, increment computerIMatchCounterCol1 by 1 everytime an 'O' is found.
                            computerIMatchCounterCol1++;
                        }

                        //When there are two cells in col 1 that have the value 'O' already entered by the computer, if the third cell is empty,
                        //insert 'O' to complete the row to win the game.   
                        if(computerIMatchCounterCol1 == 2 && i == 2)
                        {
                            for(int a = 0; a < 3; a++)
                            {
                                if(cellEntry[a][k] == ' ')
                                {
                                    cellEntry[a][k] = 'O';
                                    computerIMatchCounterCol1 = 0;
                                    computerIMatchFound = true;
                                    break;
                                }
                            }
                        }
                    }
                    


                    //[COL 2] [i][l] - Computer
                    //Run only if a match of two entries from the other user has not been found yet.
                    if(computerIMatchFound == false)
                    {   
                        if(cellEntry[i][l] == 'O')
                        {
                            //For col 2, increment computerIMatchCounterCol2 by 1 everytime an 'O' is found.
                            computerIMatchCounterCol2++;
                        }

                        //When there are two cells in col 2 that have the value 'O' already entered by the computer, if the third cell is empty,
                        //insert 'O' to complete the row to win the game.   
                        if(computerIMatchCounterCol2 == 2 && i == 2)
                        {
                            for(int a = 0; a < 3; a++)
                            {
                                if(cellEntry[a][l] == ' ')
                                {
                                    cellEntry[a][l] = 'O';
                                    computerIMatchCounterCol2 = 0;
                                    computerIMatchFound = true;
                                    break;
                                }
                            }
                        }
                            
                    }


                    //[COL 3] [i][m] - Computer
                    //Run only if a match of two entries from the other user has not been found yet.
                    if(computerIMatchFound == false)
                    {
                        if(cellEntry[i][m] == 'O')
                        {
                            //For col 3, increment computerIMatchCounterCol3 by 1 everytime an 'O' is found.
                            computerIMatchCounterCol3++;
                        }

                        //When there are two cells in col 3 that have the value 'O' already entered by the computer, if the third cell is empty,
                        //insert 'O' to complete the row to win the game.   
                        if(computerIMatchCounterCol3 == 2 && i == 2)
                        {
                            for(int a = 0; a < 3; a++)
                            {
                                if(cellEntry[a][m] == ' ')
                                {
                                    cellEntry[a][m] = 'O';
                                    computerIMatchCounterCol3 = 0;
                                    computerIMatchFound = true;
                                    break;
                                }
                            }
                        }
                        
                    }

                    //[LEFT DIAGONAL - Top to Bottom] [i][i] - Computer
                    //Run only if a match of two entries from the other user has not been found yet.
                    if(computerIMatchFound == false)
                    {
                        if(cellEntry[i][i] == 'O')
                        {
                            //For the left diagonal, increment computerIMatchCounterLDia by 1 everytime an 'X' is found.
                            computerIMatchCounterLDia++;
                        }

                        //When there are two cells in the left diagonal that have the value 'O' already entered by the computer, if the third cell is empty,
                        //insert 'O' to complete the row to win the game.   
                        if(computerIMatchCounterLDia == 2 && i == 2)
                        {
                            for(int a = 0; a < 3; a++)
                            {
                                if(cellEntry[a][a] == ' ')
                                {
                                    cellEntry[a][a] = 'O';
                                    computerIMatchCounterLDia - 0;
                                    computerIMatchFound = true;
                                    break;
                                }
                            }
                        }
                    }

                    //[RIGHT DIAGONAL - Top to Bottom] [i][n] - Computer
                    //Run only if a match of two entries from the other user has not been found yet.
                    if(computerIMatchFound == false)
                    {
                            if(cellEntry[i][n] == 'O')
                            {
                                //For the right diagonal, increment computerIMatchCounterRDia by 1 everytime an 'X' is found.
                                computerIMatchCounterRDia++;
                            }

                            //When there are two cells in the left diagonal that have the value 'O' already entered by the computer, if the third cell is empty,
                            //insert 'O' to complete the row to win the game.   
                            if(computerIMatchCounterRDia == 2 && i == 2)
                            {
                                int c = 2;
                                for(int a = 0; a < 3; a++)
                                {
                                    if(cellEntry[a][c] == ' ')
                                    {
                                        cellEntry[a][c] = 'O';
                                        computerIMatchCounterRDia - 0;
                                        computerIMatchFound = true;
                                        break;
                                    }
                                    
                                    // decrease the value of c by 1
                                    c--;
                                    
                                }
                            }                        
                    }

                    // decrease the value of n by 1
                    n--;

                    
                    
                    if (i == 2)
                    {
                        if (computerIMatchFound == false && computerJMatchFound == false)
                        {
                            computerPathwayToWin = false;
                        }     
                        
                    }
                    
                }   
            }


            if(computerPathwayToWin == false)
            {
                int k = 0;
                int l = 1;
                int m = 2;
                int n = 2;

                //Track/check when col 1, 2 and 3 have two matching entries from the other player
                int iMatchCounterCol1 = 0;
                int iMatchCounterCol2 = 0;
                int iMatchCounterCol3 = 0;

                //Track/check when the left diagonal and right diagonal have two matching entries from the other player
                int iMatchCounterLDia = 0;
                int iMatchCounterRDia = 0;

                //Track/check when row 1, 2 and 3 have two matching entries from the other player
                int jMatchCounter = 0;

                //Track/check when two matching entries from the other user is found. 
                bool iMatchFound = false;
                bool jMatchFound = false;

                //Track rows, columns and diagonals that are filled but the entries are not a match. In otherwords it's not a win.
                bool row1FilledNoMatch = false;
                bool row2FilledNoMatch = false;
                bool row3FilledNoMatch = false;

                bool col1FilledNoMatch = false;
                bool col2FilledNoMatch = false;
                bool col3FilledNoMatch = false;

                bool lDiagonalFilledNoMatch = false;
                bool rDiagonalFilledNoMatch = false;

                for(int i = 0; i < 3; i++)
                {
                    // If there is no pathway for the computer to win the game, then check to see if the other player has a pathway to win the game.In other
                    // words, does the other player already have two cell entries that are in a single row, column or diagonal. If that's the case, then block
                    // the other user from winning.

                    for(int j = 0; j < 3; j++)
                    {        
                        //[ROW 1] [i][j]
                        // Check if the other player has 2 matching entries('X') in row 1
                        if(i == 0)
                        {
                            if(cellEntry[i][j] == 'X')
                            {
                                //For Row 1, increment jMatchCounter by 1 everytime an 'X' is found.
                                jMatchCounter++;
                            }
                            //When there are two cells in row 1 that have the value 'X' from the other player, and we have checked all the cells in the row, block
                            //the other user from winning by setting the cell that has ' ' to 'O'.  
                            if(jMatchCounter == 2 && j ==2)
                            {
                                for(int a = 0; a < 3; a++)
                                {
                                    if(cellEntry[i][a] == ' ')
                                    {
                                        cellEntry[i][a] = 'O';
                                        jMatchCounter = 0;
                                        jMatchFound = true;
                                        break;
                                    }
                                    else
                                    {
                                        //Match not found and row is filled
                                        row1FilledNoMatch = true;
                                    
                                        //If the third cell neither contains 'X' nor ' ', then it must contain 'O' already. So do nothing. Reset jMatchCounter.
                                        jMatchCounter = 0;
                                    }
                                }
                            }
                        }

                        //[ROW 2] [i][j]
                        //Run only if a match of two entries from the other user has not been found yet.
                        if(iMatchFound == false && jMatchFound == false)
                        {
                            // Check if the other player has 2 matching entries('X') in row 2
                            if(i == 1)
                            {
                                if(cellEntry[i][j] == 'X')
                                {
                                    //For Row 2, increment jMatchCounter by 1 everytime an 'X' is found.
                                    jMatchCounter++;
                                }
                                //When there are two cells in row 2 that have the value 'X' from the other player, and we have checked all the cells in the row, block
                                //the other user from winning by setting the cell that has ' ' to 'O'.  
                                if(jMatchCounter == 2 && j ==2)
                                {
                                    for(int a = 0; a < 3; a++)
                                    {
                                        if(cellEntry[i][a] == ' ')
                                        {
                                            cellEntry[i][a] = 'O';
                                            jMatchCounter = 0;
                                            jMatchFound = true;
                                            break;
                                        }
                                        else
                                        {
                                            //Match not found and row is filled
                                            row2FilledNoMatch = true;
                                        
                                            //If the third cell neither contains 'X' nor ' ', then it must contain 'O' already. So do nothing. Reset jMatchCounter
                                            jMatchCounter = 0;
                                        }
                                    }
                                }
                            }
                        }

                        //[ROW 3] [i][j]
                        //Run only if a match of two entries from the other user has not been found yet. 
                        if(iMatchFound == false && jMatchFound == false)
                        {
                            // Check if the other player has 2 matching entries('X') in row 3
                            if(i == 2)
                            {
                                if(cellEntry[i][j] == 'X')
                                {
                                    //For Row 3, increment matchCounter by 1 everytime an 'X' is found.
                                    jMatchCounter++;
                                }
                                //When there are two cells in row 3 that have the value 'X' from the other player, and we have checked all the cells in the row, block
                                //the other user from winning by setting the cell that has ' ' to 'O'.  
                                if(jMatchCounter == 2 && j ==2)
                                {
                                    for(int a = 0; a < 3; a++)
                                    {
                                        if(cellEntry[i][a] == ' ')
                                        {
                                            cellEntry[i][a] = 'O';
                                            jMatchCounter = 0;
                                            jMatchFound = true;
                                            break;
                                        }
                                        else
                                        {
                                            // Match not found and row is filled
                                            row3FilledNoMatch = true;

                                            //If the third cell neither contains 'X' nor ' ', then it must contain 'O' already. So do nothing. Reset jMatchCounter
                                            jMatchCounter = 0;
                                        }
                                    }
                                }
                                
                            }
                        }

                        //Reset jMatchCounter after each row iteration is complete. 
                        if(j == 2)
                        {
                            jMatchCounter = 0;
                        }
                    }

                    //Break if two entries from the other player were found in either row 1, 2 or 3 to be matching.
                    //Do not run the codes beneath this one if that is the case.  
                    if(jMatchFound == true)
                    {
                        //reset 
                        computerPathwayToWin == true;
                        break;
                    }

                    
                    //[COL 1] [i][k]
                    //Run only if a match of two entries from the other user has not been found yet.
                    if(iMatchFound == false && jMatchFound == false)
                    {
                        // Check if the other player has 2 matching entries('X') in col 1
                        if(cellEntry[i][k] == 'X')
                        {
                            //For col 2, increment iMatchCounterCol1 by 1 everytime an 'X' is found.
                            iMatchCounterCol1++;
                        }
                        //When there are two cells in col 1 that have the value 'X' from the other player, and we have checked all the cells in the col, block
                        //the other user from winning by setting the cell that has ' ' to 'O'.  
                        if(iMatchCounterCol1 == 2 && i == 2)
                        {
                            for(int a = 0; a < 3; a++)
                            {
                                if(cellEntry[a][k] == ' ')
                                {
                                    cellEntry[a][k] = 'O';
                                    iMatchCounterCol1 = 0;
                                    iMatchFound = true;
                                    break;
                                }
                                else
                                {
                                    // Match not found and col is filled
                                    col1FilledNoMatch = true;
                                    
                                    //If the third cell neither contains 'X' nor ' ', then it must contain 'O' already. So do nothing. Reset iMatchCounterCol1
                                    iMatchCounterCol1 = 0;
                                }
                            }
                        }
                    }  


                    //[COL 2] [i][l]
                    //Run only if a match of two entries from the other user has not been found yet.
                    if(iMatchFound == false && jMatchFound == false)
                    {
                        // Check if the other player has 2 matching entries('X') in col 2
                        if(cellEntry[i][l] == 'X')
                        {
                            //For col 2, increment iMatchCounterCol2 by 1 everytime an 'X' is found.
                            iMatchCounterCol2++;
                        }
                        //When there are two cells in col 1 that have the value 'X' from the other player, and we have checked all the cells in the col, block
                        //the other user from winning by setting the cell that has ' ' to 'O'.  
                        if(iMatchCounterCol2 == 2 && i ==2)
                        {
                            for(int a = 0; a < 3; a++)
                            {
                                if(cellEntry[a][l] == ' ')
                                {
                                    cellEntry[a][l] = 'O';
                                    iMatchCounterCol2 = 0;
                                    iMatchFound = true;
                                    break;
                                }
                                else
                                {
                                    // Match not found and col is filled
                                    col2FilledNoMatch = true;
                                    
                                    //If the third cell neither contains 'X' nor ' ', then it must contain 'O' already. So do nothing. Reset iMatchCounterCol2
                                    iMatchCounterCol2 = 0;
                                }
                            }
                        }
                    }

                    //[COL 3] [i][m]
                    //Run only if a match of two entries from the other user has not been found yet.
                    if(iMatchFound == false && jMatchFound == false)
                    {
                        // Check if the other player has 2 matching entries('X') in col 3
                        if(cellEntry[i][m] == 'X')
                        {
                            //For col 3, increment iMatchCounterCol3 by 1 everytime an 'X' is found.
                            iMatchCounterCol3++;
                        }
                        //When there are two cells in col 1 that have the value 'X' from the other player, and we have checked all the cells in the col, block
                        //the other user from winning by setting the cell that has ' ' to 'O'.  
                        if(iMatchCounterCol3 == 2 && i ==2)
                        {
                            for(int a = 0; a < 3; a++)
                            {
                                if(cellEntry[a][m] == ' ')
                                {
                                    cellEntry[a][m] = 'O';
                                    iMatchCounterCol3 = 0;
                                    iMatchFound = true;
                                    break;
                                }
                                else
                                {
                                    // Match not found and col is filled
                                    col3FilledNoMatch = true;

                                    //If the third cell neither contains 'X' nor ' ', then it must contain 'O' already. So do nothing. Reset iMatchCounterCol3
                                    iMatchCounterCol3 = 0;
                                }
                            }
                        }
                    }


                    //[LEFT DIAGONAL - Top to Bottom] [i][i]
                    //Run only if a match of two entries from the other user has not been found yet.
                    if(iMatchFound == false && jMatchFound == false)
                    {
                        // Check if the other player has 2 matching entries('X') in the left diagonal                    
                        if(cellEntry[i][i] == 'X')
                        {
                            //For the left diagonal, increment iMatchCounterLDia by 1 everytime an 'X' is found.
                            iMatchCounterLDia++;
                        }
                        //When there are two cells in the left diagonal that have the value 'X' from the other player, and we have checked all the cells in the diagonal, block
                        //the other user from winning by setting the cell that has ' ' to 'O'.  
                        if(iMatchCounterLDia == 2 && i ==2)
                        {
                            for(int a = 0; a < 3; a++)
                            {
                                if(cellEntry[a][a] == ' ')
                                {
                                    cellEntry[a][a] = 'O';
                                    iMatchCounterLDia = 0;
                                    iMatchFound = true;
                                    break;
                                }
                                else
                                {
                                    // Match not found and diagonal is filled. 
                                    lDiagonalFilledNoMatch = true;
                                    
                                    //If the third cell neither contains 'X' nor ' ', then it must contain 'O' already. So do nothing. Reset iMatchCounterLDia
                                    iMatchCounterLDia = 0;
                                }
                            }
                        }
                    }

                    //[RIGHT DIAGONAL - Top to Bottom] [i][n]
                    //Run only if a match of two entries from the other user has not been found yet.
                    if(iMatchFound == false && jMatchFound == false)
                    {
                        // Check if the other player has 2 matching entries('X') in the left diagonal
                        if(cellEntry[i][n] == 'X')
                        {
                            //For the left diagonal, increment iMatchCounterRDia by 1 everytime an 'X' is found.
                            iMatchCounterRDia++;
                        }
                        //When there are two cells in the left diagonal that have the value 'X' from the other player, and we have checked all the cells in the diagonal, block
                        //the other user from winning by setting the cell that has ' ' to 'O'.  
                        if(iMatchCounterRDia == 2 && i ==2)
                        {
                            int b = 2;
                            for(int a = 0; a < 3; a++)
                            {
                                if(cellEntry[a][b] == ' ')
                                {
                                    cellEntry[a][b] = 'O';
                                    iMatchCounterRDia = 0;
                                    iMatchFound = true;
                                    break;
                                }
                                else
                                {
                                    // Match not found and diagonal is filled
                                    rDiagonalFilledNoMatch = true;

                                    //If the third cell neither contains 'X' nor ' ', then it must contain 'O' already. So do nothing. Reset iMatchCounterRDia
                                    iMatchCounterRDia = 0;
                                }
                                
                                // decrease the value of b by 1
                                b--;
                            }
                        }
                    }

                    // decrease the value of n by 1
                    n--;


                    // If there is no pathway for the computer to win the game, and there is no pathway for the other player to win the game, then 
                    // Check the rows and columns for an empty cells, then make an entry in the first empty cell you find.
                    if(i == 2)
                    {
                        if(iMatchFound == true)
                        {
                            //reset 
                            computerPathwayToWin == true;
                            break;
                        }
                        else
                        {
                            int rowColDia[] = {0, 0, 0, 0, 0, 0, 0, 0};

                            //Tracker for when a cell has been selected and filled. 
                            bool cellFilled = false;
                            
                            // Set the rowColDia[] array value to 1 where row, col or diagonal is found to be filled with entries from both player and computer. 
                            //Rows
                            if(row1FilledNoMatch == true)
                            {
                                rowColDia[0] = 1;
                            }
                            if(row2FilledNoMatch == true)
                            {
                                rowColDia[1] = 1;
                            }
                            if(row3FilledNoMatch == true)
                            {
                                rowColDia[2] = 1;
                            }

                            //Cols
                            if(col1FilledNoMatch == true)
                            {
                                rowColDia[3] = 1;
                            }
                            if(col2FilledNoMatch == true)
                            {
                                rowColDia[4] = 1;
                            }
                            if(col3FilledNoMatch == true)
                            {
                                rowColDia[5] = 1;
                            }

                            //Dias
                            if(lDiagonalFilledNoMatch == true)
                            {
                                rowColDia[6] = 1;
                            }
                            if(rDiagonalFilledNoMatch == true)
                            {
                                rowColDia[7] = 1;
                            }

                            // Do nothing for rows containing mixed entries from user and computer. Given the aformentioned, 
                            // for next move/play, check first if the cell is empty. If empty, insert computer move/entry there, 
                            // else keep trying until an empty cell is found. 
                            for(int i = 0; i < 8; i++)
                            {
                                if(rowColDia[i] == 1)
                                {
                                    // Do Nothing
                                }
                                else
                                {
                                    //ROW 1
                                    if(i == 0)
                                    {
                                        for(int j = 0; j < 3; j++)
                                        {
                                            if(cellEntry[0][j] == ' ')
                                            {
                                                cellEntry[0][j] = 'O';
                                                
                                                cellFilled = true;
                                                //break out of 1st loop
                                                break;
                                            }
                                            else
                                            {
                                                // Do Nothing.
                                            }
                                        }

                                        if (cellFilled == true)
                                        {
                                            //reset 
                                            computerPathwayToWin == true;   

                                            //break out of 2nd loop
                                            break;
                                        }
                                    }
                                    
                                    //ROW 2
                                    if(cellFilled == false)
                                    {
                                        
                                        if(i == 1)
                                        {
                                            for(int j = 0; j < 3; j++)
                                            {
                                                if(cellEntry[1][j] == ' ')
                                                {
                                                    cellEntry[1][j] = 'O';
                                                    
                                                    cellFilled = true;
                                                    //break out of 1st loop
                                                    break;
                                                }
                                                else
                                                {
                                                    // Do Nothing.
                                                }
                                            }

                                            if (cellFilled == true)
                                            {
                                                //reset 
                                                computerPathwayToWin == true;

                                                //break out of 2nd loop
                                                break;
                                            }
                                        }
                                    }

                                    //ROW 3
                                    if(cellFilled == false)
                                    {
                                        if(i == 2)
                                        {
                                            for(int j = 0; j < 3; j++)
                                            {
                                                if(cellEntry[2][j] == ' ')
                                                {
                                                    cellEntry[2][j] = 'O';
                                                    
                                                    cellFilled = true;
                                                    //break out of 1st loop
                                                    break;
                                                }
                                                else
                                                {
                                                    // Do Nothing.
                                                }
                                            }

                                            if (cellFilled == true)
                                            {
                                                //reset 
                                                computerPathwayToWin == true;

                                                //break out of 2nd loop
                                                break;
                                            }
                                        }
                                    }

                                    //COL 1
                                    if(cellFilled == false)
                                    {
                                        if(i == 3)
                                        {
                                            for(int j = 0; j < 3; j++)
                                            {
                                                if(cellEntry[j][0] == ' ')
                                                {
                                                    cellEntry[j][0] = 'O';
                                                    
                                                    cellFilled = true;
                                                    //break out of 1st loop
                                                    break;
                                                }
                                                else
                                                {
                                                    // Do Nothing.
                                                }
                                            }

                                            if (cellFilled == true)
                                            {
                                                //reset 
                                                computerPathwayToWin == true;   

                                                //break out of 2nd loop
                                                break;
                                            }
                                        }
                                    }

                                    //COL 2
                                    if(cellFilled == false)
                                    {
                                        if(i == 4)
                                        {
                                            for(int j = 0; j < 3; j++)
                                            {
                                                if(cellEntry[j][1] == ' ')
                                                {
                                                    cellEntry[j][1] = 'O';
                                                    
                                                    cellFilled = true;
                                                    //break out of 1st loop
                                                    break;
                                                }
                                                else
                                                {
                                                    // Do Nothing.
                                                }
                                            }

                                            if (cellFilled == true)
                                            {
                                                //reset 
                                                computerPathwayToWin == true;

                                                //break out of 2nd loop
                                                break;
                                            }
                                        }
                                    }

                                    //COL 3
                                    if(cellFilled == false)
                                    {
                                        if(i == 5)
                                        {
                                            for(int j = 0; j < 3; j++)
                                            {
                                                if(cellEntry[j][2] == ' ')
                                                {
                                                    cellEntry[j][2] = 'O';
                                                    
                                                    cellFilled = true;
                                                    //break out of 1st loop
                                                    break;
                                                }
                                                else
                                                {
                                                    // Do Nothing.
                                                }
                                            }

                                            if (cellFilled == true)
                                            {
                                                //reset 
                                                computerPathwayToWin == true;

                                                //break out of 2nd loop
                                                break;
                                            }
                                        }
                                    }

                                    //LEFT DIA
                                    if(cellFilled == false)
                                    {
                                        if(i == 6)
                                        {
                                            for(int j = 0; j < 3; j++)
                                            {
                                                if(cellEntry[j][j] == ' ')
                                                {
                                                    cellEntry[j][j] = 'O';
                                                    
                                                    cellFilled = true;
                                                    //break out of 1st loop
                                                    break;
                                                }
                                                else
                                                {
                                                    // Do Nothing.
                                                }
                                            }

                                            if (cellFilled == true)
                                            {
                                                //reset 
                                                computerPathwayToWin == true;

                                                //break out of 2nd loop
                                                break;
                                            }
                                        }
                                    }

                                    //RIGHT DIA
                                    if(cellFilled == false)
                                    {
                                        if(i == 7)
                                        {
                                            int k = 2;
                                            for(int j = 0; j < 3; j++)
                                            {
                                                if(cellEntry[j][k] == ' ')
                                                {
                                                    cellEntry[j][k] = 'O';
                                                    
                                                    cellFilled = true;
                                                    //break out of 1st loop
                                                    break;
                                                }
                                                else
                                                {
                                                    // Do Nothing.
                                                }

                                                k--;
                                            }

                                            if (cellFilled == true)
                                            {
                                                //reset 
                                                computerPathwayToWin == true;

                                                //break out of 2nd loop
                                                break;
                                            }
                                            
                                        }
                                    }
                                }
                            }

                        }

                    }
                }
                
                // Reset
                computerPathwayToWin = true;
            } 
        }

        printf("\n\n      CURRENT GAME");
        printf("\n\n       |       |       \n");
        printf("   %c   |   %c   |   %c  \n", cellEntry[0][0], cellEntry[0][1], cellEntry[0][2]);
        printf("-------|-------|-------\n");
        printf("       |       |       \n");
        printf("   %c   |   %c   |   %c  \n", cellEntry[1][0], cellEntry[1][1], cellEntry[1][2]);
        printf("       |       |       \n");
        printf("-------|-------|-------\n");
        printf("   %c   |   %c   |   %c  \n", cellEntry[2][0], cellEntry[2][1], cellEntry[2][2]);
        printf("       |       |       \n");
    }

    if(pToPlay)
    {
        //Player's turn to play

        if (cNumber == '1')
        {
            cellEntry[0][0] = 'X';
        }
        else if (cNumber == '2')
        {
            cellEntry[0][1] = 'X';
        }
        else if (cNumber == '3')
        {
            cellEntry[0][2] = 'X';
        }
        else if (cNumber == '4')
        {
            cellEntry[1][0] = 'X';
        }
         else if (cNumber == '5')
        {
            cellEntry[1][1] = 'X';
        }
         else if (cNumber == '6')
        {
            cellEntry[1][2] = 'X';
        }
         else if (cNumber == '7')
        {
            cellEntry[2][0] = 'X';
        }
         else if (cNumber == '8')
        {
            cellEntry[2][1] = 'X';
        }
        else
        {
            cellEntry[2][2] = 'X';
        }
        
        printf("\n\n      CURRENT GAME");
        printf("\n\n       |       |       \n");
        printf("   %c   |   %c   |   %c  \n", cellEntry[0][0], cellEntry[0][1], cellEntry[0][2]);
        printf("-------|-------|-------\n");
        printf("       |       |       \n");
        printf("   %c   |   %c   |   %c  \n", cellEntry[1][0], cellEntry[1][1], cellEntry[1][2]);
        printf("       |       |       \n");
        printf("-------|-------|-------\n");
        printf("   %c   |   %c   |   %c  \n", cellEntry[2][0], cellEntry[2][1], cellEntry[2][2]);
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

void PrintResult(char pName[30])
{
    //Print out the Result
   
    printf("\n************ RESULT SHEET ************\n\n");
    printf("No. of games played: %d\n\n", oddEvenGame + 1);
    printf("%s(X)       VS         COMPUTER(O)\n\n", pName);
    printf("%d wins       %d draws      %d wins\n\n", pNoWins, noDraws, cNoWins);
}

void Result(bool pToPlay, bool cToPlay, char playerName[30])
{
    //First check if it's the player's turn or the computer's turn to play and then check if the Player or Computer won
    if(pToPlay)
    {
        if(isGameWon == false)
        {
            //does column 1 match
            if (cellEntry[0][0] == ' '|| cellEntry[1][0] == ' ' || cellEntry[2][0] == ' ')
            {
                //Do nothing
            }
            else
            {
                if(cellEntry[0][0] == 'O'|| cellEntry[1][0] == 'O' || cellEntry[2][0] == 'O')
                {
                    //Do Nothing
                }
                else
                {
                    
                    pNoWins++;
                    isGameWon = true;
                    printf("\n\nYou Won!\n\n");
                    PrintResult(playerName);
                }
                
            }
        }
        
        if(isGameWon == false)
        {
            //does column 2 match
            if (cellEntry[0][1] == ' '|| cellEntry[1][1] == ' ' || cellEntry[2][1] == ' ')
            {
                // Do nothing
            }
            else
            {
                if (cellEntry[0][1] == 'O'|| cellEntry[1][1] == 'O' || cellEntry[2][1] == 'O')
                {
                    // Do Nothing
                }
                else
                {
                    pNoWins++;
                    isGameWon = true;
                    printf("\n\nYou Won!\n\n");
                    PrintResult(playerName);
                }
            }
        }
        
        if(isGameWon == false)
        {
            //does column 3 match
            if (cellEntry[0][2] == ' '|| cellEntry[1][2] == ' ' || cellEntry[2][2] == ' ')
            {
                //Do nothing
            }
            else
            {
                if (cellEntry[0][2] == 'O'|| cellEntry[1][2] == 'O' || cellEntry[2][2] == 'O')
                {
                    // Do Nothing
                }
                else
                {
                    pNoWins++;
                    isGameWon = true;
                    printf("\n\nYou Won!\n\n");
                    PrintResult(playerName);
                }
            }
        }

        if(isGameWon == false)
        {
            //does row 1 match
            if (cellEntry[0][0] == ' '|| cellEntry[0][1] == ' ' || cellEntry[0][2] == ' ')
            {
                //Do nothing
            }
            else
            {
                if (cellEntry[0][0] == 'O'|| cellEntry[0][1] == 'O' || cellEntry[0][2] == 'O')
                {
                    // Do Nothing
                }
                else
                {
                    pNoWins++;
                    isGameWon = true;
                    printf("\n\nYou Won!\n\n");
                    PrintResult(playerName);                  
                }
            }
        }

        if(isGameWon == false)
        {
            //does row 2 match
            if (cellEntry[1][0] == ' '|| cellEntry[1][1] == ' ' || cellEntry[1][2] == ' ')
            {
                //Do nothing
            }
            else
            {
                if (cellEntry[1][0] == 'O'|| cellEntry[1][1] == 'O' || cellEntry[1][2] == 'O')
                {
                    // Do Nothing
                }
                else
                {
                    pNoWins++;
                    isGameWon = true;
                    printf("\n\nYou Won!\n\n");
                    PrintResult(playerName);
                }  
            }
        }

        if(isGameWon == false)
        {
            //does row 3 match
            if (cellEntry[2][0] == ' '|| cellEntry[2][1] == ' ' || cellEntry[2][2] == ' ')
            {
                //Do nothing
            }
            else
            {
                if (cellEntry[2][0] == 'O'|| cellEntry[2][1] == 'O' || cellEntry[2][2] == 'O')
                {
                    // Do Nothing
                }
                else
                {
                    pNoWins++;
                    isGameWon = true;
                    printf("\n\nYou Won!\n\n");
                    PrintResult(playerName);
                }
            }
        }
        
        if(isGameWon == false)
        {
            //does left diagonal match
            if (cellEntry[0][0] == ' '|| cellEntry[1][1] == ' ' || cellEntry[2][2] == ' ')
            {
                //Do nothing
            }
            else
            {
                if (cellEntry[0][0] == 'O'|| cellEntry[1][1] == 'O' || cellEntry[2][2] == 'O')
                {
                    // Do Nothing
                }
                else
                {
                    pNoWins++;
                    isGameWon = true;
                    printf("\n\nYou Won!\n\n");
                    PrintResult(playerName);
                }
            }
        }

        if(isGameWon == false)
        {
            //does right diagonal match
            if (cellEntry[0][2] == ' '|| cellEntry[1][1] == ' ' || cellEntry[2][0] == ' ')
            {
                //Do nothing
            }
            else
            {
                if (cellEntry[0][2] == 'O'|| cellEntry[1][1] == 'O' || cellEntry[2][0] == 'O')
                {
                    // Do Nothing
                }
                else
                {
                    pNoWins++;
                    isGameWon = true;
                    printf("\n\nYou Won!\n\n");
                    PrintResult(playerName);
                }
            }
        }

        if(isGameWon == false)
        {
            if(cellEntry[0][0] == ' ' || cellEntry[0][1] == ' ' || cellEntry[0][2] == ' ' || cellEntry[1][0] == ' ' || cellEntry[1][1] == ' ' || cellEntry[1][2] == ' ' || cellEntry[2][0] == ' ' || cellEntry[2][1] == ' ' || cellEntry[2][2] == ' ')
            {
                // Do Nothing
            }
            else
            {
                noDraws++;
                printf("\n\nDraw!\n\n");
                PrintResult(playerName);
            }
        }
    
    }

    else if(cToPlay)
    {
        if(isGameWon == false)
        {
            //does column 1 match
            if (cellEntry[0][0] == ' '|| cellEntry[1][0] == ' ' || cellEntry[2][0] == ' ')
            {
                //Do nothing
            }
            else
            {
                if (cellEntry[0][0] == 'X'|| cellEntry[1][0] == 'X' || cellEntry[2][0] == 'X')
                {
                    // Do Nothing
                }
                else
                {
                    cNoWins++;
                    isGameWon = true;
                    printf("\n\nComputer Won!\n\n");
                    PrintResult(playerName);
                }
            }
        }
        
        if(isGameWon == false)
        {
            //does column 2 match
            if (cellEntry[0][1] == ' '|| cellEntry[1][1] == ' ' || cellEntry[2][1] == ' ')
            {
                //Do nothing
            }
            else
            {
                if (cellEntry[0][1] == 'X'|| cellEntry[1][1] == 'X' || cellEntry[2][1] == 'X')
                {
                    // Do Nothing
                }
                else
                {
                    cNoWins++;
                    isGameWon = true;
                    printf("\n\nComputer Won!\n\n");
                    PrintResult(playerName);
                }
            }
        }
        
        if(isGameWon == false)
        {
            //does column 3 match
            if (cellEntry[0][2] == ' '|| cellEntry[1][2] == ' ' || cellEntry[2][2] == ' ')
            {
                //Do nothing
            }
            else
            {
                if (cellEntry[0][2] == 'X'|| cellEntry[1][2] == 'X' || cellEntry[2][2] == 'X')
                {
                    // Do Nothing
                }
                else
                {
                    cNoWins++;
                    isGameWon = true;
                    printf("\n\nComputer Won!\n\n");
                    PrintResult(playerName);
                }
            }
        }

        if(isGameWon == false)
        {
            //does row 1 match
            if (cellEntry[0][0] == ' '|| cellEntry[0][1] == ' ' || cellEntry[0][2] == ' ')
            {
                //Do nothing
            }
            else
            {
                if (cellEntry[0][0] == 'X'|| cellEntry[0][1] == 'X' || cellEntry[0][2] == 'X')
                {
                    // Do Nothing
                }
                else
                {
                    cNoWins++;
                    isGameWon = true;
                    printf("\n\nComputer Won!\n\n");
                    PrintResult(playerName);
                }
            }
        }
        
        if(isGameWon == false)
        {
            //does row 2 match
            if (cellEntry[1][0] == ' '|| cellEntry[1][1] == ' ' || cellEntry[1][2] == ' ')
            {
                //Do nothing
            }
            else
            {
                if (cellEntry[1][0] == 'X'|| cellEntry[1][1] == 'X' || cellEntry[1][2] == 'X')
                {
                    //Do nothing
                }
                else
                {
                    cNoWins++;
                    isGameWon = true;
                    printf("\n\nComputer Won!\n\n");
                    PrintResult(playerName);
                }
            }
        }
        
        if(isGameWon == false)
        {
            //does row 3 match
            if (cellEntry[2][0] == ' '|| cellEntry[2][1] == ' ' || cellEntry[2][2] == ' ')
            {
                //Do nothing
            }
            else
            {
                if (cellEntry[2][0] == 'X'|| cellEntry[2][1] == 'X' || cellEntry[2][2] == 'X')
                {
                    // Do Nothing
                }
                else
                {
                    cNoWins++;
                    isGameWon = true;
                    printf("\n\nComputer Won!\n\n");
                    PrintResult(playerName);
                }
            }
        }

        if(isGameWon == false)
        {
            //does left diagonal match
            if (cellEntry[0][0] == ' '|| cellEntry[1][1] == ' ' || cellEntry[2][2] == ' ')
            {
                //Do nothing
            }
            else
            {
                if (cellEntry[0][0] == 'X'|| cellEntry[1][1] == 'X' || cellEntry[2][2] == 'X')
                {
                    // Do Nothing
                }
                else
                {
                    cNoWins++;
                    isGameWon = true;
                    printf("\n\nComputer Won!\n\n");
                    PrintResult(playerName);
                }
            }
        }
    
        if(isGameWon == false)
        {
            //does right diagonal match
            if (cellEntry[0][2] == ' '|| cellEntry[1][1] == ' ' || cellEntry[2][0] == ' ')
            {
                //Do nothing
            }
            else
            {
                if (cellEntry[0][2] == 'X'|| cellEntry[1][1] == 'X' || cellEntry[2][0] == 'X')
                {
                    // Do Nothing
                }
                else
                {
                    cNoWins++;
                    isGameWon = true;
                    printf("\n\nComputer Won!\n\n");
                    PrintResult(playerName);
                }
            }
        }

        if(isGameWon == false)
        {
            if(cellEntry[0][0] == ' ' || cellEntry[0][1] == ' ' || cellEntry[0][2] == ' ' || cellEntry[1][0] == ' ' || cellEntry[1][1] == ' ' || cellEntry[1][2] == ' ' || cellEntry[2][0] == ' ' || cellEntry[2][1] == ' ' || cellEntry[2][2] == ' ')
            {
                // Do Nothing
            }
            else
            {
                noDraws++;
                printf("\n\nDraw!\n\n");
                PrintResult(playerName);
                
            }
        }
    }       
}