#include "Reversi.h"
/**THIS FILE HANDLES THE GAMEBOARD INPUT AND THE GRAPHICS*/
/**
*   Declaring Function Prototypes
**/

/**
Function:draw of the gamefield, drawing game with gamefield data
Input: struct gameData, globales struct
Output: /
*/
void drawGameBoard(struct SaveFile gameData) {
    system("cls");
    for(int i = 0; i < 8; i++) {
        for(int k = 0; k < 8; k++) {
            switch(gameData.GameField[i][k]) {
                case 0: printf("%2c", '-'); break;
                case 1: printf("%2c" , 'O'); break;
                case 2: printf( "%2c" , 'X'); break;
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
