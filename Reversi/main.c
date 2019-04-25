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
int mainMenu(struct SaveFile *Save);
void openSettings(struct SaveFile *Save);
void setGameMode(struct SaveFile *Save, bool playerAgainstPlayer);
void openManual();

int main() {
    /**Intialising Variables*/
    struct SaveFile Save;

    InitSave(&Save);
    playerWin = false;
    if(mainMenu(&Save) == 0) {
        return 0; ///the game will be closed after pressing 3 for 'beenden' in the Main Menu
    }
    ///the players set alternately stones
    do {
        /**Drawing Game Board*/
        DrawGameBoard(&Save);
        setGameStone(&Save);
        whichPlayerTurn(&Save);
    } while(playerWin == false);
}
/**
Function: drawing of MainMenu with printf(), press number-Buttons to navigate, the menu appears again, when no valid button is pressed,you can start the game, go to settings or quit the program
Input: /
Output: /
*/
int mainMenu(struct SaveFile *Save) {
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
        if(input == '2') {///Button for settings is pressed
            system("cls");
            openSettings(&(*Save));
        }
        if(input == '3') {///Button for exit the game
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
void openSettings(struct SaveFile *Save){

    char input;
    bool playerAgainstPlayer = true;
    do {
        system("cls");
        ///Settings Menu to set the play style: Player vs player OR Player vs Computer
        printf("Willkommen zu den Einstellungen!\n\n");
        printf("2: Regeln des Spiels\n");
        printf("3: Zurueck\n");
        goToXY(0, 1);
        printf("1: Modus: ");
        setGameMode(&(*Save), playerAgainstPlayer);
        input = getch();
        if(input == '1') {
            system("cls");
            playerAgainstPlayer = !playerAgainstPlayer;
            setGameMode(&(*Save), playerAgainstPlayer);
            system("cls");
        }
        else if (input == '2'){
            system("cls");
            openManual();
        }
    } while(input != '3');
    system("cls");

    mainMenu(&(*Save));///Go back to the Main Menu
}
/**
Function: sets the Gamemode between Player vs Player and Player vs Computer
Input: boolean playerAgainstPlayer
Output: /
*/
void setGameMode(struct SaveFile *Save, bool playerAgainstPlayer) {
    if(playerAgainstPlayer == true) {
        printf("Spieler gegen Spieler");
        (*Save).Mode = 0;
    }
    else {
        printf("Spieler gegen Computer");
        (*Save).Mode = 1;
    }
}
/**
Function: rules of the game, press the number 1, to go back to the settings
Input: /
Output: /
*/
void openManual() {

    char input;
    do {
        for(int i = 0; i < 52; i++) {
            printf("~");
        }
        printf("Regeln des Spiels");
        for(int i = 0; i < 51; i++) {
            printf("~");
        }
        printf("\n\n");
        printf(" - Es wird mit 2 Spielern auf einem 8 mal 8 grossen Spielfeld gespielt.\n\n");
        printf(" - Die Spieler setzen abwechselnd immer einen Stein auf das Feld.\n\n");
        printf(" - Um einen Stein zu platzieren, muss der Spieler mit den W-A-S-D Tasten den Cursor zum gewuenschten Feld\n   navigieren und zum setzen 'y' druecken.\n\n");
        printf(" - Man darf den Stein nur da platzieren, wo ausgehend von dem gesetzten Stein in beliebiger Richtung\n   (waagerecht, senkrecht und diagonal) mindestens ein gegnerischer Stein anschliesst und dann wieder ein eigener\n   Stein liegt. Dabei muessen alle Felder zwischen dem eigenen Steinen von gegnerischen Steinen besetzt sein.\n\n");
        printf(" - Alle eingeschlossenen, gegnerischen Steine werden im selben Zug zu den eigenen Steinen.\n\n");
        printf(" - Es hat der Spieler am Ende gewonnen, dessen Anzahl an Steinen auf dem Feld groesser ist.\n\n");
        printf(" - Das Spiel endet, wenn die Spieler keine Zuege mehr machen koennen, dies ist der Fall, wenn das Spielfeld\n   komplett voll ist oder beide Spieler direkt hintereinander gepasst haben.\n\n");
        printf("1: Zurueck");

        input = getch();
        system("cls");
    } while (input != '1');
}
