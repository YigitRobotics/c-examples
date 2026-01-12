/* 
    This is basic example for structs in C language.
    You can edit, copy and distribute this project for free.

    For more information check out the "LICENSE" file.
    
    GitHub: @YigitRobotics
*/

 
#include <stdio.h>
#include <string.h>

struct gameInfo {
    int rank;
    int health;
    char playerName[20];
};

struct gameInfo g_gInfo;

int main(void) {
    char playerName[20];

    printf("Please enter player name: ");
    scanf("%19s", playerName);

    if (strcmp(playerName, "yigit") == 0) {
        g_gInfo.rank = 30;
        g_gInfo.health = 3;
    } else {
        g_gInfo.rank = 15;
        g_gInfo.health = 3;
    }

    strncpy(g_gInfo.playerName, playerName, sizeof(g_gInfo.playerName) - 1);
    g_gInfo.playerName[sizeof(g_gInfo.playerName) - 1] = '\0';

    printf("Player name: %s\n", g_gInfo.playerName);
    printf("Rank: %d\n", g_gInfo.rank);

    return 0;
}
