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
/**THIS FILE HANDLES THE GENERAL GAME*/
int mainMenu();
void openSettings();

int main()
{
    /**Intialising Variables*/
    struct SaveFile Save;
    InitSave(&Save);
    playerWin = false;
    if(mainMenu() == 0) {
        return; ///the game will be closed after pressing 3 for 'beenden' in the Main Menu
    }
    ///the players set alternately the stones
    while(playerWin == false) {
        /**Drawing Game Board*/
        DrawGameBoard(Save);
        setGameStone(&Save);
        whichPlayerTurn(&Save);
    }
}

int mainMenu() {
    char input;
    do {
        system("cls");
        ///Start Menu to navigate to the game, to the settings or close the game
        printf("Willkommen zu Reversi!\n");
        printf("Zahlen Druecken um durch das Menue zu navigieren: \n");
        printf("1: Spiel Starten\n");
        printf("2: Einstellungen\n");
        printf("3: Beenden\n");

        input = getch();
        if(input == '2') {
            system("cls");
            openSettings();
        }
        if(input == '3') {
            return 0; ///exit the game
        }
    } while(input != '1');

}

void openSettings(){

    char input;
    bool playerAgainstPlayer = true;
    do {
        ///Settings Menu to set the play style: Player vs player OR Player vs Computer
        printf("Willkommen zu den Einstellungen!\n\n");
        printf("2: Zurueck\n");
        goToXY(0, 1);
        printf("1: Modus: ");
        if(playerAgainstPlayer == true) {
            printf("Spieler gegen Spieler");
        }
        else {
            printf("Spieler gegen Computer");
        }
        input = getch();
        if(input == '1') {
            if(playerAgainstPlayer == true) {
                playerAgainstPlayer = false;
            }
            else {
                playerAgainstPlayer = true;
            }
            system("cls");
        }
    } while(input != '2');
    system("cls");

    mainMenu();///Go back to the Main Menu
}
