#include <stdio.h>
#include <stdlib.h>
#include "Reversi.h"
/**THIS FILE HANDLES THE GAMEBOARD INPUT AND THE GRAPHICS*/

/**
*   Declaring Function Prototypes
**/

void DrawGameBoard(struct SaveFile Save){
    for(int i = 0; i < 8; i++){
        for(int k = 0; k < 8; k++){
            switch(Save.GameField[i][k]){
                case 0: printf("%2c", '-'); break;
                case 1: printf("%2c", 'O'); break;
                case 2: printf("%2c", 'X'); break;
            }
        }
    printf("\n");
    }
}
