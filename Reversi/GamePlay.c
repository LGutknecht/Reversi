#include "Reversi.h"
/**THIS FILE HANDLES THE COURSE OF THE GAME*/

/**
*   Declaring Function Prototypes
**/
void setGameStone(struct SaveFile *Save);
void goToXY(int column, int row);
void whichPlayerTurn(struct SaveFile *Save);

/**
Function: navigate over the gamefield with W-A-S-D Buttons and set the stone with 'y'-Button, you can not move out of the gamefield
Input: struct Save
Output: /
*/
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
        goToXY(1, 26);
        printf("X: %i, Y: %i, p: %i\n", column / 2, row, (*Save).Turn);
        ///printf("%i", (*Save).GameField);
        goToXY(column, row); ///setting the stone at the choosen place of the field
        /*if(checkStonePositionValidation((*Save).GameField ,column, row)) {
            if(input == 'y') {
                if((*Save).Turn == 1) {
                    (*Save).GameField[row][column / 2] = 1;
                }
                else {
                    (*Save).GameField[row][column / 2] = 2;
                }
            }
        }*/
    } while(input != 'y');
}

/**
Function: sets the position of the cursor to a specific coordinate
Input: column coordinate of the console window, row coordinate of the console window
Output: /
*/
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
