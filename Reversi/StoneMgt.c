#include "Reversi.h"

int SetStone(struct SaveFile *gameData, int column, int row);

int CheckForNearStone(struct SaveFile gameData, int column, int row);
int CheckForPlayerStone(struct SaveFile gameData, int column, int row);
int CheckCoordinates(int column, int row);

int CheckStoneRight(struct SaveFile gameData, int column, int row);
int CheckStoneLeft(struct SaveFile gameData, int column, int row);
int CheckStoneUp(struct SaveFile gameData, int column, int row);
int CheckStoneDown(struct SaveFile gameData, int column, int row);
int CheckStoneUpRight(struct SaveFile gameData, int column, int row);
int CheckStoneUpLeft(struct SaveFile gameData, int column, int row);
int CheckStoneDownRight(struct SaveFile gameData, int column, int row);
int CheckStoneDownLeft(struct SaveFile gameData, int column, int row);

void WriteStoneRight(struct SaveFile *gameData, int column, int row);
void WriteStoneLeft(struct SaveFile *gameData, int column, int row);
void WriteStoneUp(struct SaveFile *gameData, int column, int row);
void WriteStoneDown(struct SaveFile *gameData, int column, int row);
void WriteStoneUpRight(struct SaveFile *gameData, int column, int row);
void WriteStoneUpLeft(struct SaveFile *gameData, int column, int row);
void WriteStoneDownRight(struct SaveFile *gameData, int column, int row);
void WriteStoneDownLeft(struct SaveFile *gameData, int column, int row);

///This function Checks for possible directions to place Stones and places the Stones. Returns the No. of Placed directions
int SetStone(struct SaveFile *gameData, int column, int row){
    ///Initialising Stone Counter
    int CountDirections = 0;

    ///Checking and Writing to the right
    if(CheckStoneRight(*gameData, column, row)){
        WriteStoneRight(&(*gameData), column, row);
        CountDirections++;
    }
    ///Checking and Writing to the left
    if(CheckStoneLeft(*gameData, column, row)){
        WriteStoneLeft(&(*gameData), column, row);
        CountDirections++;
    }
    ///Checking and Writing up
    if(CheckStoneUp(*gameData, column, row)){
        WriteStoneUp(&(*gameData), column, row);
        CountDirections++;
    }
    ///Checking and Writing down
    if(CheckStoneDown(*gameData, column, row)){
        WriteStoneDown(&(*gameData), column, row);
        CountDirections++;
    }
    ///Checking and Writing upwards-left
    if(CheckStoneUpLeft(*gameData, column, row)){
        WriteStoneUpLeft(&(*gameData), column, row);
        CountDirections++;
    }
    ///Checking and Writing upwards-right
    if(CheckStoneUpRight(*gameData, column, row)){
        WriteStoneUpRight(&(*gameData), column, row);
        CountDirections++;
    }
    ///Checking and Writing downwards-left
    if(CheckStoneDownLeft(*gameData, column, row)){
        WriteStoneDownLeft(&(*gameData), column, row);
        CountDirections++;
    }
    ///Checking and Writing downwards-right
    if(CheckStoneDownRight(*gameData, column, row)){
        WriteStoneDownRight(&(*gameData), column, row);
        CountDirections++;
    }
    goToXY(0,25);
    printf("%i", CountDirections);
    Sleep(2000);
    if(CountDirections > 0){
        return 1;
    }else{
        return 0;
    }
}

///This function Checks for a Stone of the current Player. Stone found: return 1. No Stone found: return 0.
int CheckForNearStone(struct SaveFile gameData, int column, int row){
    ///Checking for Stones of Player 1
    if(gameData.Turn == 1){
        if(gameData.GameField[row][column] == 1){
            return 1;
        }
        return 0;
    }
    ///Checking for Stones of Player 2
    if(gameData.Turn == 2){
        if(gameData.GameField[row][column] == 2){
            return 1;
        }
        return 0;
    }
    return 0;
}

///This function Checks for a Stone of the current player or if the search can continue. Stone found: return 1. No Stone found: return 0.
int CheckForPlayerStone(struct SaveFile gameData, int column, int row){
    ///Checking for Stones of Player 1
    if(gameData.Turn == 1){
        if(gameData.GameField[row][column] == 0){
            return 0;
        }
        if(gameData.GameField[row][column] == 1){
            return 1;
        }
        if(gameData.GameField[row][column] == 2){
            return 2;
        }
    }
    ///Checking for Stones of Player 2
    if(gameData.Turn == 2){
        if(gameData.GameField[row][column] == 0){
            return 0;
        }
        if(gameData.GameField[row][column] == 2){
            return 1;
        }
        if(gameData.GameField[row][column] == 1){
            return 2;
        }
    }
    return 0;
}

///This function checks if coordinates are out of the allowed range
int CheckCoordinates(int column, int row){
    ///Checking for Coordinates out of range
    if((column > 8) || (column < 0)){
        return 0;
    }
    else if((row > 8) || (row < 0)){
        return 0;
    }
    else{
        return 1;
    }
}

/**
*   This function Checks for a possible Placement to the right. Placement Possible: return 1. No Placement Possible: return 0.
*   Also this function serves as a demonstration function and is fully documented.
*   All other function are build nearly the same and just check in different directions
**/
int CheckStoneRight(struct SaveFile gameData, int column, int row){
    ///Checking for Stones from the current Player in the next field. If found, the function gets canceled
    //increasing Coordinates to the next field
    column++;
    goToXY(0,19);
    printf("%i",gameData.GameField[row][column]);
    ///Checking if Coordinates are still in range
    if(CheckCoordinates(column, row) == 0){
        return 0;
    }
    if(CheckForNearStone(gameData, column, row) == 1){
        return 0;
    }
    ///Again increasing to the next field, only fields after the first field are relevant
    column++;
    ///Checking for Stones in of the Same Player to the right
    for(int i = column; i < 9; i++){
        goToXY(0,20);
        printf("%i",gameData.GameField[row][i]);
        Sleep(500);
        ///If no Stone is found at the current Position the Search is stopped with a failure
        if(CheckForPlayerStone(gameData, i, row) == 0){
            return 0;
        }
        ///If a Stone of the current player is found at the current Position the Search is stopped with a succes
        if(CheckForPlayerStone(gameData, i, row) == 1){
            return 1;
        }
    }
    return 0;
}

///This function Checks for a possible Placement to the left. Placement Possible: return 1. No Placement Possible: return 0.
int CheckStoneLeft(struct SaveFile gameData, int column, int row){
    column--;
    if(CheckCoordinates(column, row) == 0){
        return 0;
    }
    if(CheckForNearStone(gameData, column, row) == 1){
        return 0;
    }
    column--;
    for(int i = column; i >= 0; i--){
        if(CheckForPlayerStone(gameData, i, row) == 0){
            return 0;
        }
        if(CheckForPlayerStone(gameData, i, row) == 1){
            return 1;
        }
    }
    return 0;
}

///This function Checks for a possible Placement upwards. Placement Possible: return 1. No Placement Possible: return 0.
int CheckStoneUp(struct SaveFile gameData, int column, int row){
    row--;
    if(CheckCoordinates(column, row) == 0){
        return 0;
    }
    if(CheckForNearStone(gameData, column, row) == 1){
        return 0;
    }
    row--;
    for(int i = row; i >= 0; i--){
        if(CheckForPlayerStone(gameData, column, i) == 0){
            return 0;
        }
        if(CheckForPlayerStone(gameData, column, i) == 1){
            return 1;
        }
    }
    return 0;
}

///This function Checks for a possible Placement upwards. Placement Possible: return 1. No Placement Possible: return 0.
int CheckStoneDown(struct SaveFile gameData, int column, int row){
    row++;
    if(CheckCoordinates(column, row) == 0){
        return 0;
    }
    if(CheckForNearStone(gameData, column, row) == 1){
        return 0;
    }
    row++;
    for(int i = row; i < 8; i++){
        if(CheckForPlayerStone(gameData, column, i) == 0){
            return 0;
        }
        if(CheckForPlayerStone(gameData, column, i) == 1){
            return 1;
        }
    }
    return 0;
}

///This function Checks for a possible Placement upwards-left. Placement Possible: return 1. No Placement Possible: return 0.
int CheckStoneUpLeft(struct SaveFile gameData, int column, int row){
    row--;
    column--;
    if(CheckCoordinates(column, row) == 0){
        return 0;
    }
    if(CheckForNearStone(gameData, column, row) == 1){
        return 0;
    }
    row--;
    column--;
    while(CheckCoordinates(column, row) == 1){
        if(CheckForPlayerStone(gameData, column, row) == 0){
            return 0;
        }
        if(CheckForPlayerStone(gameData, column, row) == 1){
            return 1;
        }
        row--;
        column--;
    }
    return 0;
}

///This function Checks for a possible Placement upwards-right. Placement Possible: return 1. No Placement Possible: return 0.
int CheckStoneUpRight(struct SaveFile gameData, int column, int row){
    row--;
    column++;
    if(CheckCoordinates(column, row) == 0){
        return 0;
    }
    if(CheckForNearStone(gameData, column, row) == 1){
        return 0;
    }
    row--;
    column++;
    while(CheckCoordinates(column, row) == 1){
        if(CheckForPlayerStone(gameData, column, row) == 0){
            return 0;
        }
        if(CheckForPlayerStone(gameData, column, row) == 1){
            return 1;
        }
        row--;
        column++;
    }
    return 0;
}

///This function Checks for a possible Placement downwards-left. Placement Possible: return 1. No Placement Possible: return 0.
int CheckStoneDownLeft(struct SaveFile gameData, int column, int row){
    row++;
    column--;
    if(CheckCoordinates(column, row) == 0){
        return 0;
    }
    if(CheckForNearStone(gameData, column, row) == 1){
        return 0;
    }
    row++;
    column--;
    while(CheckCoordinates(column, row) == 1){
        if(CheckForPlayerStone(gameData, column, row) == 0){
            return 0;
        }
        if(CheckForPlayerStone(gameData, column, row) == 1){
            return 1;
        }
        row++;
        column--;
    }
    return 0;
}

///This function Checks for a possible Placement downwards-right. Placement Possible: return 1. No Placement Possible: return 0.
int CheckStoneDownRight(struct SaveFile gameData, int column, int row){
    row++;
    column++;
    if(CheckCoordinates(column, row) == 0){
        return 0;
    }
    if(CheckForNearStone(gameData, column, row) == 1){
        return 0;
    }
    row++;
    column++;
    while(CheckCoordinates(column, row) == 1){
        if(CheckForPlayerStone(gameData, column, row) == 0){
            return 0;
        }
        if(CheckForPlayerStone(gameData, column, row) == 1){
            return 1;
        }
        row++;
        column++;
    }
    return 0;
}

/**
*   This function writes Stones to the right until a terminating conditions is found.
*   Also this function serves as a demonstration function and is fully documented.
*   All other function are build nearly the same and just check in different directions
**/
void WriteStoneRight(struct SaveFile *gameData, int column, int row){
    ///Going to the next Field
    column++;

    ///Writing Stones until a terminating Status is reached
    while((*gameData).GameField[row][column] != (*gameData).Turn){
        ///Setting Stone to the Current Player
        (*gameData).GameField[row][column] = (*gameData).Turn;
        ///Going to the next Field
        column++;
    }
}

void WriteStoneLeft(struct SaveFile *gameData, int column, int row){
    column--;
    while((*gameData).GameField[row][column] != (*gameData).Turn){
        (*gameData).GameField[row][column] = (*gameData).Turn;
        column--;
    }
}

void WriteStoneUp(struct SaveFile *gameData, int column, int row){
    row--;
    while((*gameData).GameField[row][column] != (*gameData).Turn){
        (*gameData).GameField[row][column] = (*gameData).Turn;
        row--;
    }
}

void WriteStoneDown(struct SaveFile *gameData, int column, int row){
    row++;
    while((*gameData).GameField[row][column] != (*gameData).Turn){
        (*gameData).GameField[row][column] = (*gameData).Turn;
        row++;
    }
}
void WriteStoneUpLeft(struct SaveFile *gameData, int column, int row){
    column--;
    row--;
    while((*gameData).GameField[row][column] != (*gameData).Turn){
        (*gameData).GameField[row][column] = (*gameData).Turn;
        column--;
        row--;
    }
}

void WriteStoneUpRight(struct SaveFile *gameData, int column, int row){
    column++;
    row--;
    while((*gameData).GameField[row][column] != (*gameData).Turn){
        (*gameData).GameField[row][column] = (*gameData).Turn;
        column++;
        row--;
    }
}

void WriteStoneDownRight(struct SaveFile *gameData, int column, int row){
    column++;
    row++;
    while((*gameData).GameField[row][column] != (*gameData).Turn){
        (*gameData).GameField[row][column] = (*gameData).Turn;
        column++;
        row++;
    }
}

void WriteStoneDownLeft(struct SaveFile *gameData, int column, int row){
    column--;
    row++;
    while((*gameData).GameField[row][column] != (*gameData).Turn){
        (*gameData).GameField[row][column] = (*gameData).Turn;
        column--;
        row++;

    }
}
