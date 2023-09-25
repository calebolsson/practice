#include <stdio.h>
#include <stdlib.h>
#include "dicegame.h"

int main()
{

    time_t t;
    // Initialize the srand() to start the random generator
    srand((unsigned)time(&t));
    // Initialize the player-1 and player-2 points to 0
    int points[2] = {0, 0};
    // Initialize all other required variables
    int rounds = 0;
    int i;
    ROUNDTYPE roundType;
    int diceRoll;
    int roundPoints;
    int playerTurn;
    int playerWin = 0;
    // scanf the user for the number of rounds to run the game
    scanf("%d", &rounds);
    // Call printPlayerPoints() function to print the initial player points which will be 0
    printPlayerPoints(points[0], points[1]);
    // Determine the starting player randomly
    playerTurn = rand() % 1;
    printf("Player %d will go first.", playerTurn + 1);

    // Set up the loop to go through all the rounds one at a time
    for (i = 1; i <= rounds; i++)
    {
        // Call the corresponding functions to get the information for this round - type, dice, points
        roundType = getRoundType();
        diceRoll = getRandomNumber(1, 6);
        roundPoints = getRoundPoints(roundType);
        // Print round number
        printf("ROUND %d", i);
        // Print current player
        printf("Player %d", playerTurn);
        // Call printRoundInfo() to print the round information
        printRoundInfo(roundType, diceRoll, roundPoints);
        // MAIN GAME LOGIC
        // Write code here to get the main game logic using branches
        // Success: Player-1 (odd player) is the current player and the dice rolled is odd
        // OR Player-2 (even player) is the current player and the dice rolled is even.
        if ((playerTurn == 0 && !(diceRoll % 2)) || (playerTurn == 1 && diceRoll % 2))
        {
            // Current player gains the points, based on the type of the round (see above). The current player’s turn continues in the next round.
            points[playerTurn] += roundPoints;
        }
        // Failure: Player-1 (odd player) is the current player and the dice rolled is even
        // OR Player-2 (even player) is the current player and the dice rolled is odd.
        else
        {
            // Current player incurs penalty of the same number of points, based on the type of the round (see above). In the next round, the current player is changed to the other player.
            points[playerTurn] -= roundPoints;
            playerTurn = (playerTurn + 1) % 2;
        }

        // Call printPlayerPoints() to print the player information at the end of the round
        printPlayerPoints(points[0], points[1]);
    }

    printf("\nGame Over!\n");

    // Compare the final points for player-1 and player-2
    // Print the winner as the one with higher points
    if (points[0] < points[1])
    {
        playerWin = 1;
    }

    printf("Player %d wins with %d points", playerWin, points[playerWin]);

    // Return from the main() function to end the program successfully

    return 0;
}
