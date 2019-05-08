#include "Reversi.h"
///THIS FILE HANDLES THE COURSE OF THE GAME

/**
*   Declaring Function Prototypes
**/
void setGameStone(struct SaveFile *gameData);
void goToXY(int column, int row);
void whichPlayerTurn(struct SaveFile *gameData);
void checkNumberOfPlayerStones(struct SaveFile *gameData);
int ValidateAndWriteStonePosition(struct SaveFile *gameData, int column, int row);
void stopWatch(struct SaveFile *gameData);
void saveGame(struct SaveFile *gameData);

/**
Function: navigate over the gamefield with W-A-S-D Buttons and set the stone with 'y'-Button, you can not move out of the gamefield
Input: struct Save
Output: /
*/
void setGameStone(struct SaveFile *gameData) {
    int column = 1, row = 0; ///always starting turn in top left corner
    char input;

    goToXY(column, row);
    do {
        input = getch();
        if(!gamePaused) {
            if(input == 'w') {
                if(row > 0) {
                    row--;
                }
            }
            else if(input == 'a') {
                if(column > 1) {
                    column = column - 2;
                }
            }
            else if(input == 's') {
                if(row < 7) {
                    row++;
                }
            }
            else if(input == 'd') {
                if(column < 15) {
                    column = column + 2;
                }
            }
            goToXY(column, row); ///setting the stone at the choosen place of the field
            if(input == 'y') {
                if(ValidateAndWriteStonePosition(&(*gameData), column, row) == 1) {
                    if((*gameData).Turn == 1) {
                        (*gameData).GameField[row][column / 2] = 1;
                    }
                    else {
                        (*gameData).GameField[row][column / 2] = 2;
                    }
                }
                else {
                    system("cls");
                    goToXY(1, 20);
                    printf("Der Stein kann nicht an die aktuelle Position gesetzt werden!");
                    Sleep(1000);
                }
            }
            if(input == 'o') {
                ///Save the whole gamestate in a file
                saveGame(&(*gameData));
            }
        }
        if(input == 'w' || input == 'a' || input == 's' || input == 'd' || input == 'y') {
          checkNumberOfPlayerStones(&(*gameData));
        }
        if(input == 'p') {
            gamePaused = !gamePaused;
            if(!gamePaused) {
                goToXY(1, 9);
                printf("               ");
            }
        }
        goToXY(column, row); ///going back to the coordinate where the cursor has been stand
    } while(input != 'y');
}
/**
Function: sets the position of the cursor to a specific coordinate
Input: column coordinate of the console window, row coordinate of the console window
Output: /
*/
void goToXY(int column, int row) {

    COORD coord; ///specific Coordinate struct with 2 Paramters: X for the columns, Y for the rows
    coord.X = column;
    coord.Y = row;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/**
Function: changes the player turn, if player one was at turn, player two is now on turn, same at opposite situation
Input: struct Save
Output: /
*/
void whichPlayerTurn(struct SaveFile *gameData) {
    if((*gameData).Turn == 1) {
        (*gameData).Turn = 2;
    }
    else {
        (*gameData).Turn = 1;
    }
}
/**
Function: checks the number of the PlayerStones immediatly after a turn
Input: struct Save, column and row of the cursor on the field
Output: /
*/
void checkNumberOfPlayerStones(struct SaveFile *gameData) {
    int numberPOne = 0, numberPTwo = 0;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if((*gameData).GameField[i][j] == 1) {
                numberPOne++;
            }
            else if((*gameData).GameField[i][j] == 2) {
                numberPTwo++;
            }
        }
    }
    goToXY(27, 3);
    printf("SCORE");
    goToXY(22, 4);
    printf("Spieler BLAU: %2i", numberPOne);
    goToXY(22, 5);
    printf("Spieler ROT:  %2i", numberPTwo);
}
/**
Funciton: shows the gametime parallel to the gameplay, realised in a separate thread
Input: struct Save to write the time in it
Output: /
*/
void stopWatch(struct SaveFile *gameData) {
    int minutes = 0, hours = 0, seconds = 0;

    while(1) {
        Sleep(1000);
        if(!gamePaused) {
            seconds++;
            (*gameData).Time++;
        }
        else {
            goToXY(1, 9);
            printf("Spiel pausiert!");
        }
        if(seconds == 60) {
            seconds = 0;
            minutes++;
            if(minutes == 60) {
                minutes = 0;
                hours++;
                if(hours == 99) {
                    printf("Maximale Spielzeit erreicht!");
                    break;
                }
            }
        }
        goToXY(21, 1);
        printf("Zeit: %02ih:%02im:%02is", hours, minutes, seconds);
    }
}

void saveGame(struct SaveFile *gameData) {
    FILE *filepointer;
    char

    filepointer = fopen("gameState.txt", "w");

    if(filepointer == NULL) {
        goToXY(1, 10);
        printf("Die Datei kann nicht geöffnet werden!");
    }
    else {
        ///write data in the file
        for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
                    fprintf(filepointer, "%i, ", gameData.GameField[i][j]);
                }
            fprintf(filepointer, "\n");
        }
        fprintf(filepointer, "%i\n", gameData.Mode);
        fprintf(filepointer, "%i\n", gameData.Time);
        fprintf(filepointer, "%i\n", gameData.Turn);
    }
}
