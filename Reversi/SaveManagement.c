
#include <stdio.h>
#include <stdlib.h>
#include "Reversi.h"

/**
*   Declaring Function Prototypes
**/
void InitSave(struct SaveFile *Save);

/**
*   Function to reset the SaveFile to it´s original state
*
*   Parameters:
*   struct SaveFile Save: Gets passed the SaveFile as a VAR to edit it
**/

void InitSave(struct SaveFile *Save){
    ///Clearing the Board
    for(int i = 0; i < 8; i++){
        for(int k = 0; k < 8; k++){
            (*Save).GameField[i][k] = 0;
        }
    }

    ///Setting the initial Stones
    //For Player 1
    (*Save).GameField[3][4] = 1;
    (*Save).GameField[4][3] = 1;

    //For Player 2
    (*Save).GameField[4][4] = 2;
    (*Save).GameField[3][3] = 2;
}
