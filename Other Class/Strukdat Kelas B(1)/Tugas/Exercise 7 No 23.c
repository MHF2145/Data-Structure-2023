#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

int main() {
    int games = 20; // number of games to play
    int bet = 5; // amount paid to play each game
    int total_winnings = 0; // total amount won across all games

    srand(time(NULL)); // set random seed using current time

    for (int i = 0; i < games; i++) {
        int die1 = rand() % 6 + 1; // generate random number between 1 and 6
        int die2 = rand() % 6 + 1; // generate random number between 1 and 6
        int sum = die1 + die2; // compute sum of dice

        if (sum % 2 == 0) { // if sum is even, gambler loses bet
            total_winnings -= bet;
        } else { // if sum is odd, gambler draws a card
            int card = rand() % 52; // generate random number between 0 and 51
            int value = card % 13 + 1; // compute value of card (ace counts as 1)

            if (value == 1 || value == 3 || value == 5 || value == 7 || value == 9) {
                total_winnings += value + bet; // if card is an ace, 3, 5, 7, or 9, gambler wins card value plus bet
            } else {
                total_winnings -= bet; // if card is anything else, gambler loses bet
            }
        }
    }

    double average_winnings = (double) total_winnings / games; // compute average winnings per game

    printf("The average amount won by the gambler per game is: $%.2f\n", average_winnings);

    return 0;
}