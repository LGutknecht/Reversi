#ifndef REVERSI_H_INCLUDED
#define REVERSI_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> ///Needed for getch() function
#include <windows.h>/** Needed for COORD structure*/
#include <process.h>///Using for a parallel thread for the stopwatch
#include <time.h>
#include <stdbool.h>

///defining the colors for the gamefield
//#define ANSI_COLOR_RED     "\x1b[31m" ///RED
//#define ANSI_COLOR_BLUE    "\x1b[34m" ///BLUE
//#define ANSI_COLOR_RESET   "\x1b[0m"  ///RESET = WHITE

struct SaveFile{
    int GameField[8][8];
    int Turn;
    int Time;
};

bool playerWin, gamePaused;

/// Function Prototypes from main.c
int mainMenu(struct SaveFile *gameData);
void openSettings(struct SaveFile *gameData);
void setGameMode(struct SaveFile *gameData, bool playerAgainstPlayer);
void openManual();

/**  Function Prototypes from SaveManagement.c */
void InitSave(struct SaveFile *gameData);

/** Function Prototypes from GameField.c */
void drawGameBoard(struct SaveFile gameData);
void drawScoreArea();

/** Function Prototypes from GamePlay.c */
void setGameStone(struct SaveFile *gameData);
void goToXY(int column, int row);
void whichPlayerTurn(struct SaveFile *gameData);
void checkNumberOfPlayerStones(struct SaveFile *gameData);
void stopWatch(struct SaveFile *gameData);
void saveGame(struct SaveFile *gameData);
#endif /* REVERSI_H_INCLUDED*/
