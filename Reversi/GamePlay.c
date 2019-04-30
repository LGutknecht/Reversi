#include "Reversi.h"
/**THIS FILE HANDLES THE COURSE OF THE GAME*/

/**
*   Declaring Function Prototypes
**/
void setGameStone(struct SaveFile *Save);
void goToXY(int column, int row);
void whichPlayerTurn(struct SaveFile *Save);
void checkNumberOfPlayerStones(struct SaveFile *Save);
int ValidateAndWriteStonePosition(struct SaveFile *Save, int column, int row);
void stopWatch(struct SaveFile *Save);

/**
Function: navigate over the gamefield with W-A-S-D Buttons and set the stone with 'y'-Button, you can not move out of the gamefield
Input: struct Save
Output: /
*/
void setGameStone(struct SaveFile *Save) {
    int column = 1, row = 0; ///always starting turn in top left corner
    char input;

    _beginthread(stopWatch, 0, &(*Save));

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
        ///goToXY(1, 10);
        ///printf("X: %i, Y: %i, p: %i\n", column / 2, row, (*Save).Turn);
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
                goToXY(1, 20);
                printf("Der Stein kann nicht an die aktuelle Position gesetzt werden!");
                Sleep(1000);
            }
        }
        if(input == 'w' || input == 'a' || input == 's' || input == 'd' || input == 'y') {
          checkNumberOfPlayerStones(&(*Save));
        }
        if(input == 'p') {
            gamePaused = !gamePaused;
        }
        goToXY(column, row); ///going back to the coordinate where the cursor has been stand
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
Function: checks the number of the PlayerStones immediatly after a turn
Input: struct Save, column and row of the cursor on the field
Output: /
*/
void checkNumberOfPlayerStones(struct SaveFile *Save) {
    int numberPOne = 0, numberPTwo = 0;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if((*Save).GameField[i][j] == 1) {
                numberPOne++;
            }
            else if((*Save).GameField[i][j] == 2) {
                numberPTwo++;
            }
        }
    }
    goToXY(27, 3);
    printf("SCORE");
    goToXY(22, 4);
    printf("Spieler BLAU: %2i", numberPOne);
    goToXY(22, 5);
    printf("Spieler ROT:  %2i", numberPTwo);
}

void stopWatch(struct SaveFile *Save) {
    int minutes = 0, hours = 0, seconds = 0;

    while(1) {
        Sleep(1000);
        if(!gamePaused) {
           seconds++;
           (*Save).Time++;
        }
        if(seconds == 60) {
            seconds = 0;
            minutes++;
            if(minutes == 60) {
                hours++;
                if(hours == 99) {
                    printf("Maximale Spielzeit erreicht!");
                    return;
                }
            }
        }
        goToXY(21, 1);
        printf("Zeit: %02ih:%02im:%02is", hours, minutes, seconds);
    }
}
