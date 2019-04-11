#include <stdio.h>
#include <stdlib.h>
#include <windows.h> /** Needed for COORD structure*/
#include "Reversi.h"
/**THIS FILE HANDLES THE COURSE OF THE GAME*/

/**
*   Declaring Function Prototypes
**/
void setGameStone(struct SaveFile Save);
void goToXY(int column, int row);
void whichPlayerTurn(struct SaveFile *Save);


void setGameStone(struct SaveFile Save) {
    int column = 0, row = 0; /**always starting turn in top left corner*/
    char input;
    goToXY(column, row);


    input = getch();
    while(input != 'y') {
        input = getch();
        if(input == 'w') {
            row--;
        }
        else if(input == 'a') {
            column--;
        }
        else if(input == 's') {
            if(row <= 10) {
                row++;
            }
        }
        else if(input == 'd') {
            if(column <= 10) {
                column++;
            }
        }
        ///setting the stone at the choosen place of the field
        goToXY(column, row);
        if(Save.Turn == 1) {
            Save.GameField[x][y] = 1;
        }
        else {
            Save.GameField[x][y] = 2;
        }
    }
}

void goToXY(int column, int row) {

    COORD coord; /**specific Coordinate struct with 2 Paramters: X for the columns, Y for the rows*/
    coord.X = column;
    coord.Y = row;

    SetConsoleCursorPosition(STD_OUTPUT_HANDLE, coord);
}

void whichPlayerTurn(struct SaveFile *Save) {
    if(Save.Turn == 1) {
        Save.Turn = 2;
    }
    else {
        Save.Turn = 1;
    }
}

