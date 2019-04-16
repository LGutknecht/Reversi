#ifndef REVERSI_H_INCLUDED
#define REVERSI_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>/** Needed for COORD structure*/
#include <time.h>
#include <stdbool.h>
struct SaveFile{
    int GameField[9][9];
    int Turn;
    int Time;
};

bool playerWin;
/**  Function Prototypes from SaveManagement */
void InitSave(struct SaveFile *Save);

/** Function Prototypes from GameBoard */
void DrawGameBoard(struct SaveFile Save);

/** Function Prototypes from GamePlay.c */
void setGameStone(struct SaveFile *Save);
void goToXY(int column, int row);
void whichPlayerTurn(struct SaveFile *Save);

#endif /* REVERSI_H_INCLUDED*/
