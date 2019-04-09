/**
*   Project: Game Reversi
*
*   Project Start Date: 09.04.2019
*
*   Project by:
*   Lukas Alte-Bornholt
*   Lukas Gutknecht
**/

#include <stdio.h>
#include <stdlib.h>
#include "Reversi.h"
///THIS FILE HANDLES THE GENERAL GAME

int main()
{
    ///Intialising Variables
    struct SaveFile Save;
    InitSave(&Save);

    ///Drawing Game Board
    DrawGameBoard(Save);
}
