#include "Reversi.h"
///THIS FILE HANDLES THE STONE PLACEMENT AND VALIDATION

///FUNCTION PROTOTYPES
int ValidateAndWriteStonePosition(struct SaveFile *Save, int column, int row);

int CheckStoneRight(struct SaveFile Save, int column, int row);
int CheckStoneLeft(struct SaveFile Save, int column, int row);
int CheckStoneUp(struct SaveFile Save, int column, int row);
int CheckStoneDown(struct SaveFile Save, int column, int row);
int CheckStoneUpRight(struct SaveFile Save, int column, int row);
int CheckStoneUpLeft(struct SaveFile Save, int column, int row);
int CheckStoneDownRight(struct SaveFile Save, int column, int row);
int CheckStoneDownLeft(struct SaveFile Save, int column, int row);

void WriteStoneRight(struct SaveFile *Save, int column, int row);
void WriteStoneLeft(struct SaveFile *Save, int column, int row);
void WriteStoneUp(struct SaveFile *Save, int column, int row);
void WriteStoneDown(struct SaveFile *Save, int column, int row);
void WriteStoneUpRight(struct SaveFile *Save, int column, int row);
void WriteStoneUpLeft(struct SaveFile *Save, int column, int row);
void WriteStoneDownRight(struct SaveFile *Save, int column, int row);
void WriteStoneDownLeft(struct SaveFile *Save, int column, int row);

int ValidateAndWriteStonePosition(struct SaveFile *Save, int column, int row) {
    ///Declaring Variables
    int StoneValidated = 0;

    ///Is the current field occupied by a stone?
    if((*Save).GameField[column][row] == 1 || (*Save).GameField[column][row] == 2) {///is there already a stone at the choosen position?
        return false;
    }
    ///is there a stone at the opposite in any direction?
    if(CheckStoneRight((*Save), column, row) == 1){
        ///Writing Stones in the direction a stone is found
        WriteStoneRight(&(*Save), column, row);
        ///Adding a point to verify a stones have been placed
        StoneValidated += 1;
    }
    if(CheckStoneLeft((*Save), column, row) == 1){
        WriteStoneLeft(&(*Save), column, row);
        StoneValidated += 1;
    }
    if(CheckStoneUp((*Save), column, row) == 1){
        WriteStoneUp(&(*Save), column, row);
        StoneValidated += 1;
    }
    if(CheckStoneDown((*Save), column, row) == 1){
        WriteStoneRight(&(*Save), column, row);
        StoneValidated += 1;
    }
    if(CheckStoneUpRight((*Save), column, row) == 1){
        WriteStoneUpRight(&(*Save), column, row);
        StoneValidated += 1;
    }
    if(CheckStoneUpLeft((*Save), column, row) == 1){
        WriteStoneUpLeft(&(*Save), column, row);
        StoneValidated += 1;
    }
    if(CheckStoneDownRight((*Save), column, row) == 1){
        WriteStoneDownRight(&(*Save), column, row);
        StoneValidated += 1;
    }
    if(CheckStoneDownLeft((*Save), column, row) == 1){
        WriteStoneDownLeft(&(*Save), column, row);
        StoneValidated += 1;
    }
    ///Return of Process Status (1 for Stones placed, 0 for invalid Place)
    if(StoneValidated > 0){
        return 1;
    }
    else{
        return 0;
    }
}

/**
*   THIS NEXT BLOCK OF 4 FUNCTIONS TESTS FOR STONES OF THE OWN COLOUR IN HORIZONTAL AND PERPENDICULAR DIRECTION
**/
///BLOCK START
int CheckStoneRight(struct SaveFile Save, int column, int row){
    ///Searching in the given direction until a stone of the Same color is found or the end of the GameField is reached. Returning 1 if a Stone was found
    for(column+=2; column < 8; column++){
        ///Checking for a Stone of Player 1
        if ((Save.Turn == 1) && (Save.GameField[row][column] == 1)){
            return 1;
        }
        ///Checking for a Stone of Player 2
        else if ((Save.Turn == 2) && (Save.GameField[row][column] == 2)){
            return 1;
        }
    }
    return 0;
}

int CheckStoneLeft(struct SaveFile Save, int column, int row){
    for(column-=2; column >= 0; column--){
        if ((Save.Turn == 1) && (Save.GameField[row][column] == 1)){
            return 1;
        }
        else if ((Save.Turn == 2) && (Save.GameField[row][column] == 2)){
            return 1;
        }
    }
    return 0;
}

int CheckStoneUp(struct SaveFile Save, int column, int row){
    for(row-=2; row >= 0; row--){
        if ((Save.Turn == 1) && (Save.GameField[row][column] == 1)){
            return 1;
        }
        else if ((Save.Turn == 2) && (Save.GameField[row][column] == 2)){
            return 1;
        }
    }
    return 0;
}

int CheckStoneDown(struct SaveFile Save, int column, int row){
    for(row+=2; row < 8; row++){
        if ((Save.Turn == 1) && (Save.GameField[row][column] == 1)){
            return 1;
        }
        else if ((Save.Turn == 2) && (Save.GameField[row][column] == 2)){
            return 1;
        }
    }
    return 0;
}
///BLOCK END

/**
*   THIS NEXT BLOCK OF 4 FUNCTIONS TESTS FOR STONES OF THE OWN COLOUR IN DIAGONAL DIRECTION
**/
///BLOCK START
int CheckStoneUpRight(struct SaveFile Save, int column, int row){
    for(row-=2; row >= 0; row--){
        for(column+=2; column <8; column++){
            if ((Save.Turn == 1) && (Save.GameField[row][column] == 1)){
            return 1;
            }
            else if ((Save.Turn == 2) && (Save.GameField[row][column] == 2)){
                return 1;
            }
        }
    }
    return 0;
}

int CheckStoneUpLeft(struct SaveFile Save, int column, int row){
    for(row-=2; row >= 0; row--){
        for(column-=2; column >=0; column--){
            if ((Save.Turn == 1) && (Save.GameField[row][column] == 1)){
            return 1;
            }
            else if ((Save.Turn == 2) && (Save.GameField[row][column] == 2)){
                return 1;
            }
        }
    }
    return 0;
}

int CheckStoneDownLeft(struct SaveFile Save, int column, int row){
    for(row+=2; row < 8; row++){
        for(column-=2; column >=0; column--){
            if ((Save.Turn == 1) && (Save.GameField[row][column] == 1)){
            return 1;
            }
            else if ((Save.Turn == 2) && (Save.GameField[row][column] == 2)){
                return 1;
            }
        }
    }
    return 0;
}

int CheckStoneDownRight(struct SaveFile Save, int column, int row){
    for(row+=2; row < 8; row++){
        for(column+=2; column <8; column++){
            if ((Save.Turn == 1) && (Save.GameField[row][column] == 1)){
            return 1;
            }
            else if ((Save.Turn == 2) && (Save.GameField[row][column] == 2)){
                return 1;
            }
        }
    }
    return 0;
}
///BLOCK END

/**
*   THIS NEXT BLOCK OF 4 FUNCTIONS WRITES STONES OF THE OWN COLOUR IN HORIZONTAL AND PERPENDICULAR DIRECTION
**/
///BLOCK START
void WriteStoneRight(struct SaveFile *Save, int column, int row){
    int PlayerTurn = (*Save).Turn;
    column++;
    do
    {
        (*Save).GameField[row][column] = PlayerTurn;
        column++;
    }while((*Save).GameField[row][column] != PlayerTurn);
}

void WriteStoneLeft(struct SaveFile *Save, int column, int row){
    int PlayerTurn = (*Save).Turn;
    column--;
    do
    {
        (*Save).GameField[row][column] = PlayerTurn;
        column--;
    }while((*Save).GameField[row][column] != PlayerTurn);
}

void WriteStoneUp(struct SaveFile *Save, int column, int row){
    int PlayerTurn = (*Save).Turn;
    row--;
    do
    {
        (*Save).GameField[row][column] = PlayerTurn;
        row--;
    }while((*Save).GameField[row][column] != PlayerTurn);
}

void WriteStoneDown(struct SaveFile *Save, int column, int row){
    int PlayerTurn = (*Save).Turn;
    row++;
    do
    {
        (*Save).GameField[row][column] = PlayerTurn;
        row++;
    }while((*Save).GameField[row][column] != PlayerTurn);
}
///BLOCK END

/**
*   THIS NEXT BLOCK OF 4 FUNCTIONS WRITES STONES OF THE OWN COLOUR IN DIAGONAL DIRECTION
**/
///BLOCK START
void WriteStoneUpLeft(struct SaveFile *Save, int column, int row){
    int PlayerTurn = (*Save).Turn;
    row--;
    column--;
    do
    {
        (*Save).GameField[row][column] = PlayerTurn;
        row--;
        column--;
    }while((*Save).GameField[row][column] != PlayerTurn);
}

void WriteStoneUpRight(struct SaveFile *Save, int column, int row){
    int PlayerTurn = (*Save).Turn;
    row--;
    column++;
    do
    {
        (*Save).GameField[row][column] = PlayerTurn;
        row--;
        column++;
    }while((*Save).GameField[row][column] != PlayerTurn);
}

void WriteStoneDownLeft(struct SaveFile *Save, int column, int row){
    int PlayerTurn = (*Save).Turn;
    row++;
    column--;
    do
    {
        (*Save).GameField[row][column] = PlayerTurn;
        row++;
        column--;
    }while((*Save).GameField[row][column] != PlayerTurn);
}

void WriteStoneDownRight(struct SaveFile *Save, int column, int row){
    int PlayerTurn = (*Save).Turn;
    row++;
    column++;
    do
    {
        (*Save).GameField[row][column] = PlayerTurn;
        row++;
        column++;
    }while((*Save).GameField[row][column] != PlayerTurn);
}
///BLOCK START
