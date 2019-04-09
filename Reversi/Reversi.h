#ifndef REVERSI_H_INCLUDED
#define REVERSI_H_INCLUDED
#include <time.h>
struct SaveFile{
    int GameField[8][8];
    int Turn;
    int Time;
};
///Funtion Prototypes from SaveManagement.c
void InitSave(struct SaveFile *Save);

///Funtion Prototypes from GameBoard.c
void DrawGameBoard(struct SaveFile Save);

#endif // REVERSI_H_INCLUDED
