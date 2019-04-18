#include "Reversi.h"
/**THIS FILE HANDLES THE GAMEBOARD INPUT AND THE GRAPHICS*/

/**
*   Declaring Function Prototypes
**/
void DrawGameBoard(struct SaveFile Save);
void checkNumberOfPlayerStones(struct SaveFile Save);
/**
Function:draw of the gamefield, drawing game with gamefield data
Input: struct Save, globales struct
Output: /
*/
void DrawGameBoard(struct SaveFile Save) {
    system("cls");
    for(int i = 0; i < 8; i++) {
        for(int k = 0; k < 8; k++) {
            switch(Save.GameField[i][k]) {
                case 0: printf("%2c", '-'); break;
                case 1: printf("%2c", 'O'); break;
                case 2: printf("%2c", 'X'); break;
            }
        }
    printf("\n");
    }
    ///checkNumberOfPlayerStones(Save);
}
/**
Function: checks the number of the PlayerStones immediatly after a turn
Input: struct Save
Output: /
*/
void checkNumberOfPlayerStones(struct SaveFile Save) {
    int numberPOne = 0, numberPTwo = 0;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(Save.GameField[i][j] == 1) {
                numberPOne++;
            }
            else if(Save.GameField[i][j] == 2) {
                numberPTwo++;
            }
        }
    }
    goToXY(20, 0);
    printf("Spieler 1: %i", numberPOne);
    goToXY(20,1);
    printf("Spieler 2: %i", numberPTwo);
}
