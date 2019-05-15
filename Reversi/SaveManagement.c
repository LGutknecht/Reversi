#include "Reversi.h"
/**THIS FILE HANDLES THE SAVESTATE*/

/**
*   Function: reset the SaveFile to it´s original state
*
*   Parameters:
*   struct SaveFile Save: Gets passed the SaveFile as a VAR to edit it
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
