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
};

///Declaring Variables
bool playerWin, gamePaused;

///Function Prototypes
int mainMenu(struct SaveFile *gameData);
void openSettings(struct SaveFile *gameData);
void setGameMode(struct SaveFile *gameData, bool playerAgainstPlayer);
void openManual();
void openControls();

#endif // REVERSI_H_INCLUDED
