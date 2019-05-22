///THIS FILE HANDLES THE COURSE OF THE GAME
#include "Reversi.h"
#include "GameField.h"
#include "GamePlay.h"
#include "SaveManagement.h"
#include "StoneManagement.h"

/**
Function: navigate over the gamefield with W-A-S-D Buttons and set the stone with 'y'-Button, you can not move out of the gamefield
Input: struct gameData
*/
void setGameStone(struct SaveFile *gameData) {
    int column = 1, row = 0; ///always starting turn in top left corner
    char input;

    goToXY(column, row);
    do {
        input = getch();
        if(!gamePaused) {
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
            goToXY(column, row); ///setting the stone at the choosen place of the field
            if(input == 'y') {
                if(SetStone(&(*gameData), column, row) == 1) {
                    if((*gameData).Turn == 1) {
                        (*gameData).GameField[row][column / 2] = 1;
                        (*gameData).Player1Passed = 0;
                    }
                    else {
                        (*gameData).GameField[row][column / 2] = 2;
                        (*gameData).Player2Passed = 0;
                    }
                }
                else {
                    goToXY(1, 12);
                    printf("Der Stein kann nicht an die aktuelle Position gesetzt werden!");
                    Sleep(1000);
                    input = 'X';
                }
            }
            if(input == 'o') {
                ///Save the whole gamestate in a file
                SaveGame(&(*gameData));
            }
        }
        if(input == 'p') {
            gamePaused = !gamePaused;
            if(!gamePaused) {
                goToXY(1, 9);
                printf("               ");
            }
        }
        if(input == 'r'){
            switch((*gameData).Turn){
                case 1:
                    (*gameData).Player1Passed++;
                    break;
                case 2:
                    (*gameData).Player2Passed++;
                    break;
            }
            break;
        }
        goToXY(column, row); ///going back to the coordinate where the cursor has been stand
    } while(input != 'y');
}
/**
Function: sets the position of the cursor to a specific coordinate
Input: column coordinate of the console window, row coordinate of the console window
*/
void goToXY(int column, int row) {

    COORD coord; ///specific Coordinate struct with 2 Paramters: X for the columns, Y for the rows
    coord.X = column;
    coord.Y = row;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/**
Function: changes the player turn, if player one was at turn, player two is now on turn, same at opposite situation
Input: struct gameData
*/
void whichPlayerTurn(struct SaveFile *gameData) {
    if((*gameData).Turn == 1) {
        (*gameData).Turn = 2;
    }
    else {
        (*gameData).Turn = 1;
    }
}

/**
Funciton: shows the gametime parallel to the gameplay, realised in a separate thread
Input: struct gameData to write the time in it
*/
void stopWatch(struct SaveFile *gameData) {
    int minutes = 0, hours = 0, seconds = 0;

    while(1) {
        Sleep(1000);
        if(!gamePaused) {
            seconds++;
            (*gameData).Time++;
        }
        else {
            goToXY(1, 9);
            printf("Spiel pausiert!");
        }
        if(seconds == 60) {
            seconds = 0;
            minutes++;
            if(minutes == 60) {
                minutes = 0;
                hours++;
                if(hours == 99) {
                    printf("Maximale Spielzeit erreicht!");
                    break;
                }
            }
        }
        goToXY(21, 1);
        printf("Zeit: %02ih:%02im:%02is", hours, minutes, seconds);
    }
}


