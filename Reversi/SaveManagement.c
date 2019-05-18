/**THIS FILE HANDLES THE SAVESTATE*/

#include "Reversi.h"
#include "GameField.h"
#include "GamePlay.h"
#include "SaveManagement.h"
#include "StoneManagement.h"

/**
*   Function: reset the SaveFile to it�s original state
*   Parameters:
*   struct SaveFile gameData: Gets passed the SaveFile as a VAR to edit it
**/
void InitSave(struct SaveFile *gameData) {
    /**Clearing the Board**/
    for(int i = 0; i < 8; i++) {
        for(int k = 0; k < 8; k++) {
            (*gameData).GameField[i][k] = 0;
        }
    }
    /**Setting the initial Stones
    For Player 1*/
    (*gameData).GameField[3][4] = 1;
    (*gameData).GameField[4][3] = 1;

    /**For Player 2*/
    (*gameData).GameField[4][4] = 2;
    (*gameData).GameField[3][3] = 2;

    /**Reset Game Time*/
    (*gameData).Time = 0;

    /**Reset Player Turn*/
    (*gameData).Turn = 1; /** 1 = Player One, 2 = Player Two*/

    ///Reset Game Mode
    ///(*gameData).Mode = 0; Mode = 0: Player vs Player, Mode = 1: Player vs Computer
}

void saveGame(struct SaveFile *gameData) {
    //FILE *filepointer;


    /*filepointer = fopen("gameState.txt", "w");

    if(filepointer == NULL) {
        goToXY(1, 10);
        printf("Die Datei kann nicht ge�ffnet werden!");
    }
    else {
        ///write data in the file
        for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
                    fprintf(filepointer, "%i, ", gameData.GameField[i][j]);
                }
            fprintf(filepointer, "\n");
        }
        fprintf(filepointer, "%i\n", gameData.Mode);
        fprintf(filepointer, "%i\n", gameData.Time);
        fprintf(filepointer, "%i\n", gameData.Turn);
    }*/
}
