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

    ///Reset Game Mode
    ///(*gameData).Mode = 0; Mode = 0: Player vs Player, Mode = 1: Player vs Computer
}

int SaveGame(struct SaveFile *gameData) {
    FILE *outfile;

    // open file for writing
    outfile = fopen ("Reversi.dat", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    // write struct to file
    fwrite (&(*gameData), sizeof(struct SaveFile), 1, outfile);

    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");

    // close file
    fclose (outfile);

    return 0;
}

int LoadGame(struct SaveFile *gameData){
    FILE *infile;

    // Open person.dat for reading
    infile = fopen ("Reversi.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    // read file contents
    fread(&(*gameData), sizeof(struct SaveFile), 1, infile);

    // close file
    fclose (infile);

    return 0;
}
