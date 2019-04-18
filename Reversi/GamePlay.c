#include "Reversi.h"
/**THIS FILE HANDLES THE COURSE OF THE GAME*/

/**
*   Declaring Function Prototypes
**/
void setGameStone(struct SaveFile *Save);
void goToXY(int column, int row);
void whichPlayerTurn(struct SaveFile *Save);
void checkStonePositionValidation(struct SaveFile *Save, int column, int row);

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
        //goToXY(1, 10);
        //printf("X: %i, Y: %i, p: %i\n", column / 2, row, (*Save).Turn);
        ///printf("%i", (*Save).GameField);
        goToXY(column, row); ///setting the stone at the choosen place of the field
        if(input == 'y') {
            if(ValidateAndWriteStonePosition(&(*Save), column, row) == 1) {
                if((*Save).Turn == 1) {
                    (*Save).GameField[row][column / 2] = 1;
                }
                else {
                    (*Save).GameField[row][column / 2] = 2;
                }
            }
            else {
                system("cls");
                _sleep(300);
                goToXY(30, 30);
                printf("Der Stein kann nicht an die aktuelle Position gesetzt werden");
            }
        }
        checkNumberOfPlayerStones(&(*Save));
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
/**
Function: changes the player turn, if player one was at turn, player two is now on turn, same at opposite situation
Input: struct Save
Output: /
*/
void whichPlayerTurn(struct SaveFile *Save) {
    if((*Save).Turn == 1) {
        (*Save).Turn = 2;
    }
    else {
        (*Save).Turn = 1;
    }
}
/**
Function: checks, wether the choosen position of the stone is valid
Input: struct Save, the column as Y Coordinate, the row as X Coordinate
Output: returns false, if the position is not valid, true if it is valid
*/
void checkStonePositionValidation(struct SaveFile *Save, int column, int row) {
    if((*Save).GameField[column][row] == 1 || (*Save).GameField[column][row] == 2) {///is there already a stone at the choosen position?
        return false;
    }
    ///is there a stone at the opposite in any direction?
    ///HERR GUTKNECHT, L�SEN SIE DAS MAL
}
