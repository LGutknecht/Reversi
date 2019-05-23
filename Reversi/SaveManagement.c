/**THIS FILE HANDLES THE SAVESTATE*/

#include "Reversi.h"
#include "GameField.h"
#include "GamePlay.h"
#include "SaveManagement.h"
#include "StoneManagement.h"
#include <string.h>

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

    /**Reset Player Pass Counter*/
    (*gameData).Player1Passed = 0;
    (*gameData).Player2Passed = 0;

    ///Reset Game Mode
    ///(*gameData).Mode = 0; Mode = 0: Player vs Player, Mode = 1: Player vs Computer
}
/**
*   Function: Saves the GameState into a file
*   Input: struct SaveFile gameData: Gets passed the SaveFile as a VAR to edit it
*   Output: 1: no succes writing the file; 0: Succes writing the file
*   **/
int SaveGame(struct SaveFile *gameData) {
    ///Declaring Variables
    FILE *outfile;

    /// open file for writing
    outfile = fopen ("Reversi.dat", "w");
    ///If File not openable error
    if (outfile == NULL)
    {
        fprintf(stderr, "\nDatei konnte nicht geöffnet werden\n");
        exit (1);
    }



    ///Writing succes message
    if(fwrite (&(*gameData), sizeof(struct SaveFile), 1, outfile) != 0){
        printf("Spiel wurde erfolgreich gespeichert !\n");
    }else{
        printf("Spiel konnte nicht gespeichert werden !\n");
    }
    // close file
    fclose (outfile);

    return 0;
}

/**
*   Function: Loads the GameState from a file
*   Input: struct SaveFile gameData: Gets passed the SaveFile as a VAR to edit it
*   Output: 1: no succes loading the file; 0: Succes Loading the file
*   **/
int LoadGame(struct SaveFile *gameData){
    ///Declaring Variables
    FILE *infile;

    /// Open person.dat for reading
    infile = fopen ("Reversi.dat", "r");
    ///If File not openable error
    if (infile == NULL)
    {
        fprintf(stderr, "\nDatei konnte nicht geöffnet werden\n");
        exit (1);
    }

    /// read file contents
    fread(&(*gameData), sizeof(struct SaveFile), 1, infile);

    /// close file
    fclose (infile);

    return 0;
}
