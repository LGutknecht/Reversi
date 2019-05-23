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
    ///Declaring Variables
    ///always starting turn in top left corner
    int column = 1, row = 0;
    char input;

    ///Going to the start Position
    goToXY(column, row);

    ///Looping until a valid Stone is placed or passed
    do {
        ///Catching Input
        input = getch();

        ///Only Entering this Branch if the game is not paused
        if(!gamePaused) {
            ///Going up if Iput is 'w'
            if(input == 'w') {
                ///Only going up if row > 0 else leaving the game field
                if(row > 0) {
                    row--;
                }
            }
            ///Going left if Iput is 'a'
            else if(input == 'a') {
                ///Only going up if column > 0 else leaving the game field
                if(column > 1) {
                    column = column - 2;
                }
            }
            ///Going down if Iput is 's'
            else if(input == 's') {
                ///Only going up if row < 7 else leaving the game field
                if(row < 7) {
                    row++;
                }
            }
            ///Going right if Iput is 'd'
            else if(input == 'd') {
                ///Only going up if column < 7 else leaving the game field
                if(column < 15) {
                    column = column + 2;
                }
            }
            ///setting the stone at the choosen place of the field
            goToXY(column, row);

            ///Trying to place the stone if input = 'y'
            if(input == 'y') {
                ///Testing if Stone is on a valid position for the player and placing the stone
                if(SetStone(&(*gameData), column, row) == 1) {
                    ///If stones in every possible direction are placed, based on the turn the stone is placed
                    if((*gameData).Turn == 1) {
                        ///Placing the stone
                        (*gameData).GameField[row][column / 2] = 1;
                        ///reseting the pass counter
                        (*gameData).Player1Passed = 0;
                    }
                    else {
                        (*gameData).GameField[row][column / 2] = 2;
                        (*gameData).Player2Passed = 0;
                    }
                }
                ///If stone couldn't be placed a error message is displayed
                else {
                    goToXY(1, 12);
                    printf("Der Stein kann nicht an die aktuelle Position gesetzt werden!");
                    Sleep(1000);
                    ///Input is set to X so the loop is not left
                    input = 'X';
                }
            }
            ///if Input is o the current game is saved
            if(input == 'o') {
                goToXY(0, 10);
                ///Save the whole gamestate in a file
                SaveGame(&(*gameData));
            }
        }
        ///If input is 'p' the game is paused
        if(input == 'p') {
            gamePaused = !gamePaused;
            if(!gamePaused) {
                goToXY(1, 9);
                printf("               ");
            }
        }
        ///if input is 'r' the current players pass score is set up and the loop is exited
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
        ///going back to the coordinate where the cursor has been stand
        goToXY(column, row);
    } while(input != 'y');
}
/**
Function: sets the position of the cursor to a specific coordinate
Input: column coordinate of the console window, row coordinate of the console window
*/
void goToXY(int column, int row) {
    ///specific Coordinate struct with 2 Paramters: X for the columns, Y for the rows
    COORD coord;
    coord.X = column;
    coord.Y = row;

    ///Setting the cursor
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/**
Function: changes the player turn, if player one was at turn, player two is now on turn, same at opposite situation
Input: struct gameData
*/
void whichPlayerTurn(struct SaveFile *gameData) {
    ///Switching the turns
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
    ///Deklaring the variables
    int minutes = 0, hours = 0, seconds = 0, sec = 0;

    ///Getting Time from Saved File
    sec = (*gameData).Time;
    hours = sec / 3600;
    sec = sec % 3600;
    minutes =  sec / 60;
    sec = sec % 60;
    seconds = sec;

    ///Looping for infinity because function is in a different threat
    while(1) {
        ///Waiting 1000ms to refresh timer
        Sleep(1000);

        ///Only adding seconds if game isn't paused
        if(!gamePaused) {
            seconds++;
            (*gameData).Time++;
        }
        ///If game is paused printing a message
        else {
            goToXY(1, 9);
            printf("Spiel pausiert!");
        }
        ///Game Ends if Maximum Play Time is reached
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
        ///Printing Time into Score Area
        goToXY(21, 1);
        printf("Zeit: %02ih:%02im:%02is", hours, minutes, seconds);
    }
}


