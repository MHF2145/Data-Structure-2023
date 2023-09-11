#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int N = 20; 
    const int bet = 5; 
    int win = 0; 

    srand(time(0));

    for (int i = 0; i < N; i++) {
        int diceA = rand() % 6 + 1;
        int diceB = rand() % 6 + 1;

        if ((diceA + diceB) % 2 == 0) {
            win -= bet;
        } 
        else { 
            int card = rand() % 52;
            int value = card % 13 + 1;

            if (value == 1 || value == 3 || value == 5 || value == 7 || value == 9) {
                win += value + bet;
            }
            else {
                win -= bet;
            }
        }
    }

    double avg = (double)win/N;
    if (avg < 0) {
        printf("Loss: $%.2f\n", -avg);
    }
    else {
        printf("Gain: $%.2f\n", avg);
    }

    return 0;
}