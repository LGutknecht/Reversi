#include <stdio.h>
#include <stdlib.h>

/**
*   Initialising Function Prototypes
**/
void DrawBoard(char GameState[8][8]);
void DrawHeader();
void DrawIndexTop();

/**
*   Initialising Global Variables
**/
char GameState[8][8];
char IndexSide[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int main()
{
    //Drawing the Game Board
    DrawBoard(GameState);
}

/**
*   This function draws the game board of "Reversi".
*   It gets passed the GameState as a char Array of 8x8
*   The function also displays the current time and the points of each player
**/
void DrawBoard(char GameState[8][8]){
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
*   This Function Draws the Top Index Line for the Navigation on the Game Board
**/
void DrawIndexTop(){
    printf("%3c", '/');
    for(int i = 1; i < 9; i++){
        printf("%3i", i);
    }
    printf("\n");
}
