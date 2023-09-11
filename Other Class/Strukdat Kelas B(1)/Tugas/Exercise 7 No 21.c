#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
 
#define NUM_SETS 5
#define NUM_NUMBERS_PER_SET 7
#define NUM_TOTAL_NUMBERS 40
 
int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
 
    // Create an array to keep track of which numbers have been used
    int used_numbers[NUM_TOTAL_NUMBERS] = {0};
 
    // Generate and print five sets of seven numbers each
    for (int i = 0; i < NUM_SETS; i++) {
        // Create an array to hold the current set of numbers
        int set[NUM_NUMBERS_PER_SET];
 
        // Generate the first number for the set
        int rand_num = rand() % NUM_TOTAL_NUMBERS + 1;
        while (used_numbers[rand_num - 1]) {
            rand_num = rand_num % NUM_TOTAL_NUMBERS + 1;
        }
        set[0] = rand_num;
        used_numbers[rand_num - 1] = 1;
 
        // Generate the remaining numbers for the set
        for (int j = 1; j < NUM_NUMBERS_PER_SET; j++) {
            rand_num = rand() % NUM_TOTAL_NUMBERS + 1;
            while (used_numbers[rand_num - 1]) {
                rand_num = rand_num % NUM_TOTAL_NUMBERS + 1;
            }
            set[j] = rand_num;
            used_numbers[rand_num - 1] = 1;
        }
 
        // Print the current set of numbers
        for (int j = 0; j < NUM_NUMBERS_PER_SET; j++) {
            printf("%d ", set[j]);
        }
        printf("\n");
    }
 
    return 0;
}