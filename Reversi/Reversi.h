#ifndef REVERSI_H_INCLUDED
#define REVERSI_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> ///Needed for getch() function
#include <windows.h>/** Needed for COORD structure*/
#include <time.h>
#include <stdbool.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

struct SaveFile{
    int GameField[9][9];
    int Turn;
    int Time;
    int Mode;
};

bool playerWin;
/**  Function Prototypes from SaveManagement */
void InitSave(struct SaveFile *Save);

/** Function Prototypes from GameBoard */
void DrawGameBoard(struct SaveFile *Save);

/** Function Prototypes from GamePlay.c */
void setGameStone(struct SaveFile *Save);
void goToXY(int column, int row);
void whichPlayerTurn(struct SaveFile *Save);

#endif /* REVERSI_H_INCLUDED*/
