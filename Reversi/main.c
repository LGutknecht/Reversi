/***
*   Project: Game Reversi
*
*   Project Start Date: 09.04.2019
*
*   Project by:
*   Lukas Alte-Bornholt
*   Lukas Gutknecht
**/

#include "Reversi.h"
#include "GameField.h"
#include "GamePlay.h"
#include "SaveManagement.h"
#include "StoneManagement.h"


int main() {
    ///declaration of the struct
    struct SaveFile gameData;
    do{
        ///Intialising Variables
        playerWin = false;
        gamePaused = false;
        GameEnd = false;

        ///Initiating SaveState
        InitSave(&gameData);

        ///Calling Main Menu
        if(mainMenu(&gameData) == 0) {
            ///the game will be closed after pressing 3 for 'beenden' in the Main Menu
            return 0;
        }
        ///Starting Clock
        _beginthread(stopWatch, 0, &gameData);
        ///the players set alternately stones until one losses
        do {
            ///Drawing Game Board
            drawGameBoard(gameData);
            ///Ending game if board is full
            if(BoardFull(gameData) == 1){
                break;
            }
            ///Ending game if booth players passed
            if((gameData.Player1Passed == 1) && (gameData.Player2Passed == 1)){
                break;
            }
            ///Ending game if one player passes 2 times, giving up
            if((gameData.Player1Passed == 2) || (gameData.Player2Passed == 2)){
                break;
            }
            ///Setting the GameStone
            setGameStone(&gameData);
            ///Switching turns
            whichPlayerTurn(&gameData);
        } while(playerWin == false);
        ///Displaying the player Won message
        WichPlayerWonMessage(gameData);

        ///Questioning if the player wants to play another round
        if(GameEnd == 1){
            break;
        }

    } while(GameEnd == false);

}
/**
Function: drawing of MainMenu with printf(), press number-Buttons to navigate, the menu appears again, when no valid button is pressed,you can start the game, go to settings or quit the program
Input: /
Output: /
*/
int mainMenu(struct SaveFile *gameData) {
    ///Declaring Variables
    char input;

    ///Looping Menu
    do {
        ///Clearing Screen
        system("cls");
        ///Start Menu to navigate to the game, to the settings or close the game
        printf("Willkommen zu Reversi!\n");
        printf("Zahlen Druecken um durch das Menue zu navigieren: \n");
        printf("1: Spiel Starten\n");
        printf("2: Spiel Laden\n");
        printf("3: Einstellungen\n");
        printf("4: Beenden\n");

        ///Fetching selection
        input = getch();
        ///Button for loading game
        if(input == '2'){
            LoadGame(&(*gameData));
            break;
        }
        ///Button for Settings
        if(input == '3') {
            system("cls");
            openSettings(&(*gameData));
        }
        ///Button for exit the game
        if(input == '4') {
            return 0;
        }
    } while(input != '1');
    return 1;
}

/**
Function: settings of the program: Modes, who you play against (Computer or other player), look for rules of the game
Input: /
Output: /
*/
void openSettings(struct SaveFile *gameData){
    ///Declaring Variables
    char input;
    ///Looping Menu
    do {
        system("cls");
        ///Settings Menu to set the play style: Player vs player OR Player vs Computer
        printf("Willkommen zu den Einstellungen!\n\n");
        printf("1: Modus: Spieler gegen Spieler\n");
        printf("2: Regeln von Reversi\n");
        printf("3: Steuerung des Spiels\n");
        printf("4: Zurueck\n");
        input = getch();

        ///Opening the Settings
        if (input == '2'){
            system("cls");
            openManual();
        }
        ///Opening the Controls
        if(input == '3') {
            system("cls");
            openControls();
        }
    } while(input != '4');
    ///Clearing Screen
    system("cls");
    ///Go back to the Main Menu
    mainMenu(&(*gameData));
}
/**
Function: rules of the game, press the number 1, to go back to the settings
*/
void openManual() {
    ///Declaring Variables
    char input;
    ///Looping Menu
    do {
        ///Printing Border
        for(int i = 0; i < 52; i++) {
            printf("~");
        }
        ///Printing Header
        printf("Regeln des Spiels");
        for(int i = 0; i < 51; i++) {
            printf("~");
        }
        ///Printing Rules
        printf("\n\n");
        printf(" - Es wird mit 2 Spielern auf einem 8 mal 8 grossen Spielfeld gespielt.\n\n");
        printf(" - Die Spieler setzen abwechselnd immer einen Stein auf das Feld.\n\n");
        printf(" - Um einen Stein zu platzieren, muss der Spieler mit den W-A-S-D Tasten den Cursor zum gewuenschten Feld\n   navigieren und zum setzen 'y' druecken.\n\n");
        printf(" - Man darf den Stein nur da platzieren, wo ausgehend von dem gesetzten Stein in beliebiger Richtung\n   (waagerecht, senkrecht und diagonal) mindestens ein gegnerischer Stein anschliesst und dann wieder ein eigener\n   Stein liegt. Dabei muessen alle Felder zwischen dem eigenen Steinen von gegnerischen Steinen besetzt sein.\n\n");
        printf(" - Alle eingeschlossenen, gegnerischen Steine werden im selben Zug zu den eigenen Steinen.\n\n");
        printf(" - Es hat der Spieler am Ende gewonnen, dessen Anzahl an Steinen auf dem Feld groesser ist.\n\n");
        printf(" - Ein Spieler gibt auf wenn er zwei mal hintereinander passt \n\n");
        printf(" - Das Spiel endet, wenn die Spieler keine Zuege mehr machen koennen, dies ist der Fall, wenn das Spielfeld\n   komplett voll ist oder beide Spieler direkt hintereinander gepasst haben.\n\n");
        printf("1: Zurueck");

        ///Fetching Input
        input = getch();
        ///Clearing Screen
        system("cls");
    } while (input != '1');
}

/**
Function: Controlls of the game, press the number 1, to go back to the settings
*/
void openControls() {
    ///Declaring Variables
    char input;
    ///Looping Menu
    do {
        ///Printing Border
        for(int i = 0; i < 50; i++) {
            printf("~");
        }
        ///Printing Header
        printf("Steuerung des Spiels");
        for(int i = 0; i < 50; i++) {
            printf("~");
        }
        ///Printing Rules
        printf("\n\n");
        printf(" Bewegung im Spiel\n\n");
        printf(" W = NACH OBEN\n");
        printf(" S = NACH UNTEN\n");
        printf(" A = NACH LINKS\n");
        printf(" D = NACH RECHTS\n\n");
        printf(" Einloggen/Pausieren\n\n");
        printf(" Y = SPIELSTEIN SETZEN\n");
        printf(" P = SPIEL PAUSIEREN/FORTSETZEN\n");
        printf(" R = ZUG PASSEN\n");
        printf(" O = SPIEL SPEICHER\n\n");
        printf("1: Zurueck");
        ///Fetching Input
        input = getch();
        ///Clearing Screen
        system("cls");
    } while(input != '1');
}
/**
Function: Function prints the winning message
input: struct SaveFile
*/
void WichPlayerWonMessage(struct SaveFile gameData){
    ///Declaring variables
    int numberPOne = 0, numberPTwo = 0;

    ///Checking Score, looping through field
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            ///If Playerstone found increasing the value of his score
            if(gameData.GameField[i][j] == 1) {
                numberPOne++;
            }
            else if(gameData.GameField[i][j] == 2) {
                numberPTwo++;
            }
        }
    }
    ///Checking if Player 1 gave up
    if(gameData.Player1Passed == 2){
        goToXY(0, 15);
        printf("O hat aufgegeben! X hat gegen O mit %i zu %i gewonnen", numberPTwo, numberPOne);
    }
    ///Checking if Player 2 gave up
    else if(gameData.Player2Passed == 2){
        goToXY(0, 15);
        printf("X hat aufgegeben! O hat gegen X mit %i zu %i gewonnen", numberPOne, numberPTwo);
    }
    ///Checking if Player 1 has more points and won
    else if(numberPOne > numberPTwo){
        goToXY(0, 15);
        printf("O hat gegen X mit %i zu %i gewonnen", numberPOne, numberPTwo);
    }
    ///Checking if Player 2 has more points and won
    else if(numberPOne < numberPTwo){
        goToXY(0, 15);
        printf("X hat gegen O mit %i zu %i gewonnen", numberPTwo, numberPOne);
    }
    ///Checking if the game is a draw
    else if(numberPOne == numberPTwo){
        goToXY(0, 15);
        printf("O und X haben unentschieden gespielt");
    }
}

/**
Function: Qustioning the player if he wants to end the game
input: struct SaveFile
*/
int EndGame(){
    ///Declaring variables
    char input;
    ///Looping Menu
    do{
        goToXY(0, 16);
        printf("Neues Spiel? \n y: JA \n \n n: NEIN");
        ///Fetching input
        input = getchar();
        ///Ending Game if input = 'n'
        if(input == 'n'){
            return 1;
        }
    } while(input != ('y' || 'n'));
    return 0;
}
