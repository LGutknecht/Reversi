/**THIS FILE HANDLES THE STONE LOGIC*/

#include "Reversi.h"
#include "GameField.h"
#include "GamePlay.h"
#include "SaveManagement.h"
#include "StoneManagement.h"
///Declaring Global Variables
int FlipBoard[8][8];


/**
*   This Function Places the Stone of the Player
*   Returns:
*   0: Stone can't be placed
*   1: Stone placed
**/
int SetStone(struct SaveFile *gameData, int column, int row){


    ///Clean FlipBoard
    ResetFlipBoard();

    ///Correct Coordinates
    switch(column){
        case 1: column = 0; break;
        case 3: column = 1; break;
        case 5: column = 2; break;
        case 7: column = 3; break;
        case 9: column = 4; break;
        case 11:column = 5; break;
        case 13:column = 6; break;
        case 15:column = 7; break;
    }

    ///Checking if Placement is valid
    if(PlacementValid((*gameData), column, row)){
        ///Flipping all marked stones
        FlipStones(&(*gameData));
        return 1;
    }
    return 0;
}

/**
*   This Function checks if the Placement of the Stone is Valid
*   Returns:
*   0: Invalid Position
*   1: Valid Position
**/
int PlacementValid(struct SaveFile gameData, int column, int row){
    ///Declaring Variables
    int Valid = 0;

    ///If Pace isn't empty, the placement can be aborted
    if(gameData.GameField[row][column] != 0){
        return 0;
    }

    ///Checking Every Direction
    if(CheckStoneLeft(gameData, column, row) == 1){
        ///Marking Stones to be flipped
        MarkStoneLeft(gameData, column, row);
        ///Marking the Desired PLace to be valid
        Valid = 1;
    }
    if(CheckStoneRight(gameData, column, row) == 1){
        MarkStoneRight(gameData, column, row);
        Valid = 1;
    }
    if(CheckStoneUp(gameData, column, row) == 1){
        MarkStoneUp(gameData, column, row);
        Valid = 1;
    }
    if(CheckStoneDown(gameData, column, row) == 1){
        MarkStoneDown(gameData, column, row);
        Valid = 1;
    }
    if(CheckStoneUpLeft(gameData, column, row) == 1){
        MarkStoneUpLeft(gameData, column, row);
        Valid = 1;
    }
    if(CheckStoneUpRight(gameData, column, row) == 1){
        MarkStoneUpRight(gameData, column, row);
        Valid = 1;
    }
    if(CheckStoneDownLeft(gameData, column, row) == 1){
        MarkStoneDownLeft(gameData, column, row);
        Valid = 1;
    }
    if(CheckStoneDownRight(gameData, column, row) == 1){
        MarkStoneDownRight(gameData, column, row);
        Valid = 1;
    }
    ///Checking if a Valid move was found
    if(Valid == 0){
        return 0;
    } else {
        return 1;
    }

}

///--------------------///
///STONE CHECKING LOGIC///
///--------------------///

///THREE EXAMPLE FUNCTIONS, THE REST WORKS THE SAME///

/**
*   Checks Position in the direction given in the function Name
*   Returns:
*   0: Not Valid in this Direction
*   1: Valid in this Direction
**/
int CheckStoneUp(struct SaveFile gameData, int column, int row){
    ///Checking if there is no stone nearby
    if(CheckUp(gameData, column, row) == 1){
        ///Going zo the first field to check
        row -= 2;
        ///Prechecking if there is already a stone of the same color
        if((gameData.GameField[row][column] == gameData.Turn) && (PositionValid(column,row) == 1)){
            return 1;
        }
        ///Looping to ininity, break condition inside loop
        while(1){
            ///If Position is invalid, break
            if(PositionValid(column,row) == 0){
                return 0;
            }
            ///If there is no stone, break
            if(gameData.GameField[row][column] == 0){
                return 0;
            }
            ///If there is a stone of the same colr, return succes;
            if(gameData.GameField[row][column] == gameData.Turn){
                return 1;
            }
            row--;
        }
        return 0;
    }
    return 0;
}

/**
*   Checks if there is a stone in the near area blocking placement
*   Returns:
*   0: Blocked Position
*   1: Not Blocked Position
**/
int CheckUp(struct SaveFile gameData, int column, int row){
    ///Going to the nearest field
    row--;
    ///Checking if position is valid
    if(PositionValid(column, row) == 1){
        ///If The field is emptyor has the players colr, return failure, else succes
        if((gameData.GameField[row][column] == gameData.Turn) || (gameData.GameField[row][column] == 0)){
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}

/**
*   Marks Stones to be flipped in the direction given in the function Name
*   Returns:
*   0: Blocked Position
*   1: Not Blocked Position
**/
void MarkStoneUp(struct SaveFile gameData, int column, int row){
    ///Going to the next field
    row--;
    ///Marking all stones to flipped until a stone of the same color is found
    while(gameData.GameField[row][column] != gameData.Turn){
        FlipBoard[row][column] = 1;
        row--;
    }
}

///--Checking Down--///

int CheckStoneDown(struct SaveFile gameData, int column, int row){
    if(CheckDown(gameData, column, row) == 1){
        row += 2;
        if((gameData.GameField[row][column] == gameData.Turn) && (PositionValid(column,row) == 1)){
            return 1;
        }
        while(1){
            if(PositionValid(column,row) == 0){
                return 0;
            }
            if(gameData.GameField[row][column] == 0){
                return 0;
            }
            if(gameData.GameField[row][column] == gameData.Turn){
                return 1;
            }
            row++;
        }
        return 0;
    }
    return 0;
}

int CheckDown(struct SaveFile gameData, int column, int row){
    row++;
    if(PositionValid(column, row) == 1){
        if((gameData.GameField[row][column] == gameData.Turn) || (gameData.GameField[row][column] == 0)){
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}

void MarkStoneDown(struct SaveFile gameData, int column, int row){
    row++;
    while(gameData.GameField[row][column] != gameData.Turn){
        FlipBoard[row][column] = 1;
        row++;
    }
}

///--Checking Left--///

int CheckStoneLeft(struct SaveFile gameData, int column, int row){
    if(CheckLeft(gameData, column, row) == 1){
        column -= 2;
        if((gameData.GameField[row][column] == gameData.Turn) && (PositionValid(column,row) == 1)){
            return 1;
        }
        while(1){
            if(PositionValid(column,row) == 0){
                return 0;
            }
            if(gameData.GameField[row][column] == 0){
                return 0;
            }
            if(gameData.GameField[row][column] == gameData.Turn){
                return 1;
            }
            column--;
        }
        return 0;
    }
    return 0;
}

int CheckLeft(struct SaveFile gameData, int column, int row){
    column--;
    if(PositionValid(column, row) == 1){
        if((gameData.GameField[row][column] == gameData.Turn) || (gameData.GameField[row][column] == 0)){
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}

void MarkStoneLeft(struct SaveFile gameData, int column, int row){
   column--;
    while(gameData.GameField[row][column] != gameData.Turn){
        FlipBoard[row][column] = 1;
        column--;
    }
}

///--Checking Right--///

int CheckStoneRight(struct SaveFile gameData, int column, int row){
    if(CheckRight(gameData, column, row) == 1){
        column += 2;
        if((gameData.GameField[row][column] == gameData.Turn) && (PositionValid(column,row) == 1)){
            return 1;
        }
        while(1){
            if(PositionValid(column,row) == 0){
                return 0;
            }
            if(gameData.GameField[row][column] == 0){
                return 0;
            }
            if(gameData.GameField[row][column] == gameData.Turn){
                return 1;
            }
            column++;
        }
        return 0;
    }
    return 0;
}

int CheckRight(struct SaveFile gameData, int column, int row){
    column++;
    if(PositionValid(column, row) == 1){
        if((gameData.GameField[row][column] == gameData.Turn) || (gameData.GameField[row][column] == 0)){
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}

void MarkStoneRight(struct SaveFile gameData, int column, int row){
   column++;
    while(gameData.GameField[row][column] != gameData.Turn){
        FlipBoard[row][column] = 1;
        column++;
    }
}

///--Checking Up Left--///

int CheckStoneUpLeft(struct SaveFile gameData, int column, int row){
    if(CheckUpLeft(gameData, column, row) == 1){
        column -= 2;
        row -= 2;
        if((gameData.GameField[row][column] == gameData.Turn) && (PositionValid(column,row) == 1)){
            return 1;
        }
        while(1){
            if(PositionValid(column,row) == 0){
                return 0;
            }
            if(gameData.GameField[row][column] == 0){
                return 0;
            }
            if(gameData.GameField[row][column] == gameData.Turn){
                return 1;
            }
            column--;
            row--;
        }
        return 0;
    }
    return 0;
}

int CheckUpLeft(struct SaveFile gameData, int column, int row){
    column--;
    row--;
    if(PositionValid(column, row) == 1){
        if((gameData.GameField[row][column] == gameData.Turn) || (gameData.GameField[row][column] == 0)){
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}

void MarkStoneUpLeft(struct SaveFile gameData, int column, int row){
    column--;
    row--;
    while(gameData.GameField[row][column] != gameData.Turn){
        FlipBoard[row][column] = 1;
        column--;
        row--;
    }
}

///--Checking Up Right--///

int CheckStoneUpRight(struct SaveFile gameData, int column, int row){
    if(CheckUpRight(gameData, column, row) == 1){
        column += 2;
        row -= 2;
        if((gameData.GameField[row][column] == gameData.Turn) && (PositionValid(column,row) == 1)){
            return 1;
        }
        while(1){
            if(PositionValid(column,row) == 0){
                return 0;
            }
            if(gameData.GameField[row][column] == 0){
                return 0;
            }
            if(gameData.GameField[row][column] == gameData.Turn){
                return 1;
            }
            column++;
            row--;
        }
        return 0;
    }
    return 0;
}

int CheckUpRight(struct SaveFile gameData, int column, int row){
    column++;
    row--;
    if(PositionValid(column, row) == 1){
        if((gameData.GameField[row][column] == gameData.Turn) || (gameData.GameField[row][column] == 0)){
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}

void MarkStoneUpRight(struct SaveFile gameData, int column, int row){
    column++;
    row--;
    while(gameData.GameField[row][column] != gameData.Turn){
        FlipBoard[row][column] = 1;
        column++;
        row--;
    }
}

///--Checking Down Left--///

int CheckStoneDownLeft(struct SaveFile gameData, int column, int row){
    if(CheckDownLeft(gameData, column, row) == 1){
        column -= 2;
        row += 2;
        if((gameData.GameField[row][column] == gameData.Turn) && (PositionValid(column,row) == 1)){
            return 1;
        }
        while(1){
            if(PositionValid(column,row) == 0){
                return 0;
            }
            if(gameData.GameField[row][column] == 0){
                return 0;
            }
            if(gameData.GameField[row][column] == gameData.Turn){
                return 1;
            }
            column--;
            row++;
        }
        return 0;
    }
    return 0;
}

int CheckDownLeft(struct SaveFile gameData, int column, int row){
    column--;
    row++;
    if(PositionValid(column, row) == 1){
        if((gameData.GameField[row][column] == gameData.Turn) || (gameData.GameField[row][column] == 0)){
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}

void MarkStoneDownLeft(struct SaveFile gameData, int column, int row){
    column--;
    row++;
    while(gameData.GameField[row][column] != gameData.Turn){
        FlipBoard[row][column] = 1;
        column--;
        row++;
    }
}

///--Checking Down Right--///

int CheckStoneDownRight(struct SaveFile gameData, int column, int row){
    if(CheckDownRight(gameData, column, row) == 1){
        column += 2;
        row += 2;
        if((gameData.GameField[row][column] == gameData.Turn) && (PositionValid(column,row) == 1)){
            return 1;
        }
        while(1){
            if(PositionValid(column,row) == 0){
                return 0;
            }
            if(gameData.GameField[row][column] == 0){
                return 0;
            }
            if(gameData.GameField[row][column] == gameData.Turn){
                return 1;
            }
            column++;
            row++;
        }
        return 0;
    }
    return 0;
}

int CheckDownRight(struct SaveFile gameData, int column, int row){
    column++;
    row++;
    if(PositionValid(column, row) == 1){
        if((gameData.GameField[row][column] == gameData.Turn) || (gameData.GameField[row][column] == 0)){
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}

void MarkStoneDownRight(struct SaveFile gameData, int column, int row){
    column++;
    row++;
    while(gameData.GameField[row][column] != gameData.Turn){
        FlipBoard[row][column] = 1;
        column++;
        row++;
    }
}


///-------------///
///GENERAL LOGIC///
///-------------///

/**
*   Flipping all stones marked on the FlipTable
**/
void FlipStones(struct SaveFile *gameData){
    ///Looping through the Save Board
    for(int i = 0; i < 8; i++){
        for(int k = 0; k < 8; k++){
            ///Only writing if there is a stone to flip
            if(FlipBoard[i][k] == 1){
                if((*gameData).GameField[i][k] == 1){
                    (*gameData).GameField[i][k] = 2;
                } else {
                    (*gameData).GameField[i][k] = 1;
                }
            }
        }
    }
    ///Resetting the FlipBoard
    ResetFlipBoard();
}

/**
*   Checks if row and column used in the current function is inside the allowed range
*   Returns:
*   0: Outside Range
*   1: Inside Range
**/
int PositionValid(int column, int row){
    ///Declaring Variables
    int x = row;
    int y = column;
    ///Checking Position for ROW
    if(x < 0 || x > 8){
        return 0;
    }
    ///Cehcking Position for column
    if(y < 0 || y > 8){
        return 0;
    }
    return 1;
}
/**
*   This function Resets the FlipBoard
**/
void ResetFlipBoard(){
    ///Looping through board
    for(int i = 0; i < 8; i++){
        for(int k = 0; k < 8; k++)
            FlipBoard[i][k] = 0;
    }
}


