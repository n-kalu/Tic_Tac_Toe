#ifndef OPERATIONS_H
#define OPERATIONS_H


#include <stdbool.h>

extern char cellEntry[3][4];
//Tracker for number of times the Player and the Computer won or had a draw. 
extern int pNoWins;
extern int cNoWins;
extern int noDraws;

//Bool Variable to confirm win or lose
extern bool isGameWon;

//Variable to track when the computer has a pathway to win
extern bool computerPathwayToWin;

//Tracks current game being played to determine if it's odd or even. E.g. First game is even, second game is odd, etc. 
extern int oddEvenGame;

void WelcomeIntro(char Iname[30]);
void MainOp(char mName[30], char mReady, char mLwrReady, bool mPTurnToPlay, bool mCTurnToPlay, bool mPlay, int mCurPlay);
void ClearStdinBuffer();
void PrintCellNumbers();
char RegisterPlayedCell(int currentPlay, char cNumber, bool pToPlay, bool cToPlay);
void DisplayEmptyCells();
void Result(bool pToPlay, bool cToPlay, char playerName[30]);
void PrintResult(char pName[30]);


#endif