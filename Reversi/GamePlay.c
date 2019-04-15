#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> /** Needed for COORD structure*/
#include "Reversi.h"
/**THIS FILE HANDLES THE COURSE OF THE GAME*/

/**
*   Declaring Function Prototypes
**/
void setGameStone(struct SaveFile *Save);
void goToXY(int column, int row);
void whichPlayerTurn(struct SaveFile *Save);

void setGameStone(struct SaveFile *Save) {
    int column = 1, row = 0; ///always starting turn in top left corner
    char input;
    goToXY(column, row);

    do {
        input = getch();
        if(input == 'w') {
            if(row > 0) {
               row--;
            }
        }
        else if(input == 'a') {
            if(column > 1) {
                column = column - 2;
            }
        }
        else if(input == 's') {
            if(row < 7) {
                row++;
            }
        }
        else if(input == 'd') {
            if(column < 15) {
                column = column + 2;
            }
        }
        goToXY(1, 17);
        printf("X: %i, Y: %i, p: %i", column / 2, row, (*Save).Turn);
        goToXY(column, row); ///setting the stone at the choosen place of the field
        if(input == 'y') {
            if((*Save).Turn == 1) {
                (*Save).GameField[row][column / 2] = 1;
            }
            else {
                (*Save).GameField[row][column / 2] = 2;
            }
        }

    } while(input != 'y');
}

void goToXY(int column, int row) {

    COORD coord; ///specific Coordinate struct with 2 Paramters: X for the columns, Y for the rows
    coord.X = column;
    coord.Y = row;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void whichPlayerTurn(struct SaveFile *Save) {
    if((*Save).Turn == 1) {
        (*Save).Turn = 2;
    }
    else {
        (*Save).Turn = 1;
    }
}
