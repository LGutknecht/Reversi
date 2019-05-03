#ifndef REVERSI_H_INCLUDED
#define REVERSI_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> ///Needed for getch() function
#include <windows.h>/** Needed for COORD structure*/
#include <pthread.h>///Using a parallel thread for the stopwatch
#include <time.h>
#include <stdbool.h>

///defining the colors for the gamefield
//#define ANSI_COLOR_RED     "\x1b[31m" ///RED
//#define ANSI_COLOR_BLUE    "\x1b[34m" ///BLUE
//#define ANSI_COLOR_RESET   "\x1b[0m"  ///RESET = WHITE

///Declaration of the struct in the program
struct SaveFile{
    int GameField[9][9];
    int Turn;
    int Time;
    int Mode;
};

bool playerWin, gamePaused;

/// Function Prototypes from main.c
int mainMenu(struct SaveFile *Save);
void openSettings(struct SaveFile *Save);
void setGameMode(struct SaveFile *Save, bool playerAgainstPlayer);
void openManual();

/**  Function Prototypes from SaveManagement.c */
void InitSave(struct SaveFile *Save);

/** Function Prototypes from GameField.c */
void drawGameBoard(struct SaveFile *Save);

/** Function Prototypes from GamePlay.c */
void setGameStone(struct SaveFile *Save);
void goToXY(int column, int row);
void whichPlayerTurn(struct SaveFile *Save);
void checkNumberOfPlayerStones(struct SaveFile *Save);
int ValidateAndWriteStonePosition(struct SaveFile *Save, int column, int row);
void stopWatch(struct SaveFile *Save);

#endif /* REVERSI_H_INCLUDED*/
