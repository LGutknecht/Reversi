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

    for(int i = 0; i < 8; i++) {
        for(int k = 0; k < 8; k++) {
            PrintField[i][k] = gameData.GameField[i][k];
        }
    }

    for(int j = 0; j < 8; j++) {
        for(int l = 0; l < 8; l++) {
            MovePossible = 0;
            if(PrintField[j][l] == 0){
                if(CheckStoneUp(gameData,l,j) == 1){
                    PrintField[j][l] = 3;
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
        if(MovePossible >= 1){
            PossibleMoves++;
        }
        }
    }


    system("cls");

    for(int i = 0; i < 8; i++) {
        for(int k = 0; k < 8; k++) {
            switch(PrintField[i][k]) {
                case 0: printf("%2c", '-'); break;
                case 1: printf("%2c" , 'O'); break;
                case 2: printf( "%2c" , 'X'); break;
                case 3: printf( "%2c" , '?'); break;
            }
        }
    printf("\n");
    }
    goToXY(19, 8);
    printf("Moegliche Zuege: %i", PossibleMoves);
    checkNumberOfPlayerStones(gameData);
    drawScoreArea();
}

/**
Function: draws a border around the Score Area
Input: /
Output: /
*/
void drawScoreArea() {

    for(int i = 19; i < 40; i++) {
        goToXY(i, 0);
        printf("#");
        goToXY(i, 7);
        printf("#");
    }
    for(int i = 1; i < 7; i++) {
        goToXY(19, i);
        printf("#");
        goToXY(39, i);
        printf("#");
    }

}

int BoardFull(struct SaveFile gameData){
    for(int j = 0; j < 8; j++) {
        for(int l = 0; l < 8; l++) {
            if(gameData.GameField[j][l] == 0){
                return 0;
            }
        }
    }
    return 1;
}
/**
Function: checks the number of the PlayerStones immediatly after a turn
Input: struct gameData, column and row of the cursor on the field
*/
void checkNumberOfPlayerStones(struct SaveFile gameData) {
    int numberPOne = 0, numberPTwo = 0;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(gameData.GameField[i][j] == 1) {
                numberPOne++;
            }
            else if(gameData.GameField[i][j] == 2) {
                numberPTwo++;
            }
        }
    }
    goToXY(27, 3);
    printf("SCORE");
    if(gameData.Turn == 1){
       goToXY(21, 4);
       printf("->");
    }
    if(gameData.Player1Passed >= 1){
        goToXY(37, 4);
        printf("P");
    }
    goToXY(23, 4);
    printf("Spieler O: %2i", numberPOne);
    if(gameData.Turn == 2){
       goToXY(21, 5);
       printf("->");
    }
    if(gameData.Player2Passed >= 1){
        goToXY(37, 5);
        printf("P");
    }
    goToXY(23, 5);
    printf("Spieler X: %2i", numberPTwo);
}

