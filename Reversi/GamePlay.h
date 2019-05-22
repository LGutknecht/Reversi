#ifndef GAMEPLAY_H_INCLUDED
#define GAMEPLAY_H_INCLUDED

///Function Prototypes
void setGameStone(struct SaveFile *gameData);
void goToXY(int column, int row);
void whichPlayerTurn(struct SaveFile *gameData);
void checkNumberOfPlayerStones(struct SaveFile gameData);
void stopWatch(struct SaveFile *gameData);
void saveGame(struct SaveFile *gameData);

#endif // GAMEPLAY_H_INCLUDED
