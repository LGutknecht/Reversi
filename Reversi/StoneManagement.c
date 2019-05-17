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
    if(PlacementValid((*gameData), column, row)){
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
    ///Checking Every Direction
    if(CheckStoneLeft(gameData, column, row) == 1){
        ///Marking Stones to be flipped
        MarkStoneLeft(gameData, column, row);
    }
    if(CheckStoneRight(gameData, column, row) == 1){
        MarkStoneRight(gameData, column, row);
    }
    if(CheckStoneUp(gameData, column, row) == 1){
        MarkStoneUp(gameData, column, row);
    }
    if(CheckStoneDown(gameData, column, row) == 1){
        MarkStoneDown(gameData, column, row);
    }
    if(CheckStoneUpLeft(gameData, column, row) == 1){
        MarkStoneUpLeft(gameData, column, row);
    }
    if(CheckStoneUpRight(gameData, column, row) == 1){
        MarkStoneUpRight(gameData, column, row);
    }
    if(CheckStoneDownLeft(gameData, column, row) == 1){
        MarkStoneDownLeft(gameData, column, row);
    }
    if(CheckStoneDownRight(gameData, column, row) == 1){
        MarkStoneDownLeft(gameData, column, row);
    }
}

///--------------------///
///STONE CHECKING LOGIC///
///--------------------///
/**
*   Checks Position in the direction given in the function Name
*   Returns:
*   0: Not Valid in this Direction
*   1: Valid in this Direction
**/
int CheckStoneUp(struct SaveFile gameData, int column, int row){
    if(CheckUp(gameData, column, row) == 1){
        row -= 2;
        while(PositionValid == 1){
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
    row--;
    if(PositionValid(column, row) == 1){
        if(gameData.GameField[row][column] == gameData.Turn){
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
    row--;
    while(gameData.GameField[row][column] != gameData.Turn){
        FlipBoard[row][column] = 1;
        row--;
    }
}

///--Checking Down--///

int CheckStoneDown(struct SaveFile gameData, int column, int row){
    if(CheckDown(gameData, column, row) == 1){
        row += 2;
        while(PositionValid == 1){
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
        if(gameData.GameField[row][column] == gameData.Turn){
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
        while(PositionValid == 1){
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
        if(gameData.GameField[row][column] == gameData.Turn){
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
        while(PositionValid == 1){
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
        if(gameData.GameField[row][column] == gameData.Turn){
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
        while(PositionValid == 1){
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
        if(gameData.GameField[row][column] == gameData.Turn){
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
        while(PositionValid == 1){
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
        if(gameData.GameField[row][column] == gameData.Turn){
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
        while(PositionValid == 1){
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
        if(gameData.GameField[row][column] == gameData.Turn){
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
        while(PositionValid == 1){
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
        if(gameData.GameField[row][column] == gameData.Turn){
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
    for(int i = 0; i < 8; i++){
        for(int k = 0; k < 8; k++){
            if(FlipBoard[i][k] == 1){
                if((*gameData).GameField[i][k] == 1){
                    (*gameData).GameField[i][k] = 2;
                }
                if((*gameData).GameField[i][k] == 2){
                    (*gameData).GameField[i][k] = 1;
                }
            }
        }
    }
}
/**
*   Checks if row and column used in the current function is inside the allowed range
*   Returns:
*   0: Outside Range
*   1: Inside Range
**/
int PositionValid(int column, int row){
    int x = row;
    int y = column;
    if(x < 0 || x > 8){
        return 0;
    }
    if(y < 0 || y > 8){
        return 0;
    }
    return 1;
}
/**
*   This function Resets the FlipBoard
**/
void ResetFlipBoard(){
    for(int i = 0; i < 8; i++){
        for(int k = 0; k < 8; k++)
            FlipBoard[i][k] = 0;
    }
}
