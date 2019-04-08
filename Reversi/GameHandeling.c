#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/**
*   Defining placeholders for color codes
**/
#define C_Reset "\x1B[0m"
#define C_Red "\x1B[31m"
#define C_Green "\x1B[32m"
#define C_Yellow "\x1B[33m"
#define C_White "\x1B[37m"
struct{
    int Turn;
    int GameState[8][8];
    int TimeElapsed;
    int StartTime;
}SaveState;

/**
*   Initialising Function Prototypes
**/
void DrawBoard(struct SaveState Save);
void DrawHeader(struct SaveState Save);
void DrawIndexTop(struct SaveState Save);
void DrawGameState(struct SaveState Save,int row, int colum);
void ClearBoard(struct SaveState Save);


/**
*   Initialising Global Variables
**/
char IndexSide[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};



/**
*   This function draws the game board of "Reversi".
*   It gets passed the GameState as a char Array of 8x8
*   The function also displays the current time and the points of each player
**/
void DrawBoard(struct SaveState Save){
    //Drawing the Game Board Header
    DrawHeader(Save);

    //Drawing the Top Index
    DrawIndexTop(Save);

    for(int i = 0; i < 8; i++){
        printf("%3c", IndexSide[i]);
        for(int k = 0; k < 8; k++){
            DrawGameState(i, k);
        }
        printf("\n");
    }
}

/**
*   This Functions Draws the Game Board Header, including Play Time and the Score Board
**/
void DrawHeader(){
}

/**
*   This Function draws a single color-coded field from the GameState
*   The Functions gets the row and colum of the desired field passed to it
**/
void DrawGameState(struct SaveState Save){
    //Drawing the field int the correct color
    switch(GameState[row][colum]){
        case 0: printf("%3c",'-'); break;
        case 1: printf("%3c",'X'); break;
        case 2: printf("%3c",'O'); break;
    }
}
/**
*   This Function Draws the Top Index Line for the Navigation on the Game Board
**/
void DrawIndexTop(){
    printf("%3c", '/');
    for(int i = 1; i < 9; i++){
        printf("%3i", i);
    }
    printf("\n");
}

/**
*   This Function Clears the Game Board and resets it to its original state
**/
void ClearBoard(){
    //Clearing the Board
    for(int i = 0; i < 8; i++){
        for(int k = 0; k < 8; k++){
            GameState[i][k] = 0;
        }
    }

    //Setting the Starting Area
    GameState[3][3] = 1;
    GameState[4][4] = 1;
    GameState[3][4] = 2;
    GameState[4][3] = 2;
}

