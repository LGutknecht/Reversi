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
    int PossiblePosition;

    for(int i = 0; i < 8; i++) {
        for(int k = 0; k < 8; k++) {
            PrintField[i][k] = gameData.GameField[i][k];
        }
    }

    for(int j = 0; j < 8; j++) {
        for(int l = 0; l < 8; l++) {
            if(PrintField[j][l] == 0){
                if(CheckStoneUp(gameData,l,j) == 1){
                    PrintField[j][l] = 3;
                    PossiblePosition = 1;
                }
                if(CheckStoneDown(gameData,l,j) == 1){
                    PrintField[j][l] = 3;
                    PossiblePosition = 1;
                }
                if(CheckStoneLeft(gameData,l,j) == 1){
                    PrintField[j][l] = 3;
                    PossiblePosition = 1;
                }
                if(CheckStoneRight(gameData,l,j) == 1){
                    PrintField[j][l] = 3;
                    PossiblePosition = 1;
                }
                if(CheckStoneUpLeft(gameData,l,j) == 1){
                    PrintField[j][l] = 3;
                    PossiblePosition = 1;
                }
                if(CheckStoneUpRight(gameData,l,j) == 1){
                    PrintField[j][l] = 3;
                    PossiblePosition = 1;
                }
                if(CheckStoneDownLeft(gameData,l,j) == 1){
                    PrintField[j][l] = 3;
                    PossiblePosition = 1;
                }
                if(CheckStoneDownRight(gameData,l,j) == 1){
                    PrintField[j][l] = 3;
                    PossiblePosition = 1;
                }
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

