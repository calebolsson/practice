#include "dicegame.h"

int getRandomNumber(int min, int max) {
    
    return (rand() % max) + min;
}

ROUNDTYPE getRoundType() {
    //your code goes here
    return REGULAR; //erase this
}

int getRoundPoints(ROUNDTYPE roundType) {
    //your code goes here
    return 0; //erase this
}

void printPlayerPoints(int p1, int p2) {
    //your code goes here
}

void printRoundInfo(ROUNDTYPE t, int dice, int points) {
    //your code goes here
}
