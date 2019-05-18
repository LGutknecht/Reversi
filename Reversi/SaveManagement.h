#ifndef SAVEMANAGEMENT_H_INCLUDED
#define SAVEMANAGEMENT_H_INCLUDED

///Function Prototypes
void InitSave(struct SaveFile *gameData);
int SaveGame(struct SaveFile *gameData);
int LoadGame(struct SaveFile *gameData);

#endif // SAVEMANAGEMENT_H_INCLUDED
