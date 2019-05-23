/**THIS FILE HANDLES THE GAMEBOARD INPUT AND THE GRAPHICS*/

#include "Reversi.h"
#include "GameField.h"
#include "GamePlay.h"
#include "SaveManagement.h"
#include "StoneManagement.h"

/**
Function:draw of the gamefield, drawing game with gamefield data
Input: struct gameData, globales struct
*/
void drawGameBoard(struct SaveFile gameData) {
    ///Declaring Variables
    int PrintField[8][8];
    int PossibleMoves = 0;
    int MovePossible = 0;

    ///Passing GameField Array to PrintField
    for(int i = 0; i < 8; i++) {
        for(int k = 0; k < 8; k++) {
            PrintField[i][k] = gameData.GameField[i][k];
        }
    }

    ///Checking for every PLace in the GameField Array if any moves are possible
    for(int j = 0; j < 8; j++) {
        for(int l = 0; l < 8; l++) {
            ///Resetting the MovePossible indicator
            MovePossible = 0;
            ///Only if the place is empty the test is done
            if(PrintField[j][l] == 0){
                ///Checking in Every direction
                if(CheckStoneUp(gameData,l,j) == 1){
                    ///If Direction is valid, Position gets set to 3, equaling a ? when printed
                    PrintField[j][l] = 3;
                    ///Setting the Move to Possible
                    MovePossible += 1;
                }
                if(CheckStoneDown(gameData,l,j) == 1){
                    PrintField[j][l] = 3;
                    MovePossible += 1;
                }
                if(CheckStoneLeft(gameData,l,j) == 1){
                    PrintField[j][l] = 3;
                    MovePossible += 1;
                }
                if(CheckStoneRight(gameData,l,j) == 1){
                    PrintField[j][l] = 3;
                    MovePossible += 1;
                }
                if(CheckStoneUpLeft(gameData,l,j) == 1){
                    PrintField[j][l] = 3;
                    MovePossible += 1;
                }
                if(CheckStoneUpRight(gameData,l,j) == 1){
                    PrintField[j][l] = 3;
                    MovePossible += 1;
                }
                if(CheckStoneDownLeft(gameData,l,j) == 1){
                    PrintField[j][l] = 3;
                    MovePossible += 1;
                }
                if(CheckStoneDownRight(gameData,l,j) == 1){
                    PrintField[j][l] = 3;
                    MovePossible += 1;
                }
            }
        ///Adding a Step to Possible Moves if move for Place is possible
        if(MovePossible >= 1){
            PossibleMoves++;
        }
        }
    }

    ///Clearing the screen
    system("cls");

    ///Printing the game field
    for(int i = 0; i < 8; i++) {
        for(int k = 0; k < 8; k++) {
            ///Deciding wich character to print
            switch(PrintField[i][k]) {
                case 0: printf("%2c", '-'); break;
                case 1: printf("%2c" , 'O'); break;
                case 2: printf( "%2c" , 'X'); break;
                case 3: printf( "%2c" , '?'); break;
            }
        }
    printf("\n");
    }
    ///Printing the number of possible moves to make the orientation easier
    goToXY(19, 8);
    printf("Moegliche Zuege: %i", PossibleMoves);
    ///Printing the Score Area
    drawScoreArea();
    ///Printing the Number of player stones in the Score Area
    checkNumberOfPlayerStones(gameData);

}

/**
Function: draws a border around the Score Area
**/
void drawScoreArea() {
    ///Drawing the horizontal #
    for(int i = 19; i < 40; i++) {
        goToXY(i, 0);
        printf("#");
        goToXY(i, 7);
        printf("#");
    }
    ///Drawing the perpendicular #
    for(int i = 1; i < 7; i++) {
        goToXY(19, i);
        printf("#");
        goToXY(39, i);
        printf("#");
    }

}
/**
Function: Checks if the board has any free places left
Input: struct gameData
Output: 1 for No Places left; 0 for Places Left
*/
int BoardFull(struct SaveFile gameData){
    ///Looping through game field
    for(int j = 0; j < 8; j++) {
        for(int l = 0; l < 8; l++) {
            ///Checking if PLace is free
            if(gameData.GameField[j][l] == 0){
                return 0;
            }
        }
    }
    ///Returning 0 if no free place is found
    return 1;
}
/**
Function: checks the number of the PlayerStones immediatly after a turn
Input: struct gameData, column and row of the cursor on the field
*/

void checkNumberOfPlayerStones(struct SaveFile gameData) {
    ///Declaring Variables
    int numberPOne = 0, numberPTwo = 0;

     ///Looping through game field
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            ///If found Stone is from Player 1 adding a point to his variable
            if(gameData.GameField[i][j] == 1) {
                numberPOne++;
            }
            ///If found Stone is from Player 1 adding a point to his variable
            else if(gameData.GameField[i][j] == 2) {
                numberPTwo++;
            }
        }
    }
    ///Drawing the Turn arrow for player 1
    goToXY(27, 3);
    printf("SCORE");
    if(gameData.Turn == 1){
       goToXY(21, 4);
       printf("->");
    }
    ///Drawing the pass arrow for player 1
    if(gameData.Player1Passed >= 1){
        goToXY(37, 4);
        printf("P");
    }
    ///Drawing the Score of Player 1
    goToXY(23, 4);
    printf("Spieler O: %2i", numberPOne);

    ///Drawing the Turn arrow for player 2
    if(gameData.Turn == 2){
       goToXY(21, 5);
       printf("->");
    }
    ///Drawing the pass arrow for player 2
    if(gameData.Player2Passed >= 1){
        goToXY(37, 5);
        printf("P");
    }
    ///Drawing the Score of Player 2
    goToXY(23, 5);
    printf("Spieler X: %2i", numberPTwo);
}

