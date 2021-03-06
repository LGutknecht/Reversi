#ifndef REVERSI_H_INCLUDED
#define REVERSI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>      ///Needed for getch() function
#include <windows.h>    ///Needed for COORD structure*/
#include <process.h>    ///Using for a parallel thread for the stopwatch
#include <time.h>
#include <stdbool.h>

///Struct the gamelogic is based on
struct SaveFile{
    int GameField[8][8];
    int Turn;
    int Time;
    int Player1Passed;
    int Player2Passed;
};

///Declaring Variables
bool playerWin, gamePaused, GameEnd;

///Function Prototypes
int mainMenu(struct SaveFile *gameData);
void openSettings(struct SaveFile *gameData);
void setGameMode(struct SaveFile *gameData, bool playerAgainstPlayer);
void openManual();
void openControls();
void WichPlayerWonMessage(struct SaveFile gameData);
int EndGame();


#endif // REVERSI_H_INCLUDED
