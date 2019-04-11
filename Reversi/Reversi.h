#ifndef REVERSI_H_INCLUDED
#define REVERSI_H_INCLUDED
#include <time.h>
struct SaveFile{
    int GameField[8][8];
    int Turn;
    int Time;
};
/**  Function Prototypes from SaveManagement */
void InitSave(struct SaveFile *Save);

/** Function Prototypes from GameBoard */
void DrawGameBoard(struct SaveFile Save);

/** Function Prototypes from GamePlay.c */
void setGameStone(struct SaveFile Save);
void goToXY(int column, int row);
void whichPlayerTurn(struct SaveFile *Save);

#endif /* REVERSI_H_INCLUDED*/
