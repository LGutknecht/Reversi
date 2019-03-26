#include <stdio.h>
#include <stdlib.h>

/**
*   Defining placeholders for the color codes
**/
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"

/**
*   Initialising Function Prototypes
**/
void DrawBoard();
void DrawHeader();
void DrawIndexTop();
void ClearBoard();

/**
*   Initialising Global Variables
**/
char GameState[8][8];
char IndexSide[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int main()
{
    //Clearing the Game Board
    ClearBoard();
    //Drawing the Game Board
    DrawBoard(GameState);
}

/**
*   This function draws the game board of "Reversi".
*   It gets passed the GameState as a char Array of 8x8
*   The function also displays the current time and the points of each player
**/
void DrawBoard(){
    //Drawing the Game Board Header
    DrawHeader();

    //Drawing the Top Index
    DrawIndexTop();

    for(int i = 0; i < 8; i++){
        printf("%3c", IndexSide[i]);
        for(int k = 0; k < 8; k++){
            printf("%3c", GameState[i][k]);
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
            GameState[i][k] = 'X';
        }
    }
}
