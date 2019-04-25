#include "Reversi.h"
/**THIS FILE HANDLES THE GAMEBOARD INPUT AND THE GRAPHICS*/
/**
*   Declaring Function Prototypes
**/
void DrawGameBoard(struct SaveFile *Save);
/**
Function:draw of the gamefield, drawing game with gamefield data
Input: struct Save, globales struct
Output: /
*/
void DrawGameBoard(struct SaveFile *Save) {
    system("cls");
    for(int i = 0; i < 8; i++) {
        for(int k = 0; k < 8; k++) {
            switch((*Save).GameField[i][k]) {
                case 0: printf("%2c", '-'); break;
                case 1: printf(ANSI_COLOR_BLUE "%2c" ANSI_COLOR_RESET, 'O'); break;
                case 2: printf(ANSI_COLOR_RED "%2c" ANSI_COLOR_RESET, 'O'); break;
            }
        }
    printf("\n");
    }
}
