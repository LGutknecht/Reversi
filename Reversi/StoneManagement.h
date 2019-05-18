#ifndef STONEMANAGEMENT_H_INCLUDED
#define STONEMANAGEMENT_H_INCLUDED

///Declaring Function Prototypes
int CheckStoneRight(struct SaveFile gameData, int column, int row);
void MarkStoneRight(struct SaveFile gameData, int column, int row);
int CheckRight(struct SaveFile gameData, int column, int row);

int CheckStoneLeft(struct SaveFile gameData, int column, int row);
void MarkStoneLeft(struct SaveFile gameData, int column, int row);
int CheckLeft(struct SaveFile gameData, int column, int row);

int CheckStoneUp(struct SaveFile gameData, int column, int row);
void MarkStoneUp(struct SaveFile gameData, int column, int row);
int CheckUp(struct SaveFile gameData, int column, int row);

int CheckStoneDown(struct SaveFile gameData, int column, int row);
void MarkStoneDown(struct SaveFile gameData, int column, int row);
int CheckDown(struct SaveFile gameData, int column, int row);

int CheckStoneUpRight(struct SaveFile gameData, int column, int row);
void MarkStoneUpRight(struct SaveFile gameData, int column, int row);
int CheckUpRight(struct SaveFile gameData, int column, int row);

int CheckStoneUpLeft(struct SaveFile gameData, int column, int row);
void MarkStoneUpLeft(struct SaveFile gameData, int column, int row);
int CheckUpLeft(struct SaveFile gameData, int column, int row);

int CheckStoneDownRight(struct SaveFile gameData, int column, int row);
void MarkStoneDownRight(struct SaveFile gameData, int column, int row);
int CheckDownRight(struct SaveFile gameData, int column, int row);

int CheckStoneDownLeft(struct SaveFile gameData, int column, int row);
void MarkStoneDownLeft(struct SaveFile gameData, int column, int row);
int CheckDownLeft(struct SaveFile gameData, int column, int row);

int PositionValid(int column, int row);
int PlacementValid(struct SaveFile gameData, int column, int row);
int SetStone(struct SaveFile *gameData, int column, int row);
void FlipStones(struct SaveFile *gameData);
void ResetFlipBoard();
#endif // STONEMANAGEMENT_H_INCLUDED

