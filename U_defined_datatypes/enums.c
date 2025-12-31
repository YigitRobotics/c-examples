#include <stdio.h>

enum players { 
    PLAYER,
    SPECTATOR,
    ADMINISTRATOR
};

enum age {
    YIGIT = 14,
    YUNUS = 14, 
    SERDAR // 15
};

enum players yigit1 = ADMINISTRATOR;
enum players serdar1 = PLAYER; 
enum players spect1 = SPECTATOR;
enum age yunus = YUNUS;
enum age yigit = YIGIT;
enum age serdar = SERDAR;

int main() {
    printf("%d", yigit1);
    printf("\n");
    printf("%d", serdar1);
    printf("\n");
    printf("%d", spect1);
    printf("\n");
    printf("%s", "Age List: \n");

    printf("%d", yunus);
    printf("\n");
    printf("%d", yigit);
    printf("\n");
    printf("%d", serdar);
    return 0;
}