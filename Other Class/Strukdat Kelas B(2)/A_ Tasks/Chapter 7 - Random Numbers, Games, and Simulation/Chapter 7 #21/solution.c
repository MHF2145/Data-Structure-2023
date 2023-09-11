#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define SET 5
#define N 7
#define TOTAL 40
 
int main() {
    srand(time(0));
    int used_numbers[TOTAL] = {0};
 
    for (int i = 0; i < SET; i++) {
        int set[N];

        int rand_num = rand() % TOTAL + 1;
        while (used_numbers[rand_num - 1]) {
            rand_num = rand_num % TOTAL + 1;
        }
        set[0] = rand_num;
        used_numbers[rand_num - 1] = 1;
 
        for (int j = 1; j < N; j++) {
            rand_num = rand() % TOTAL + 1;
            while (used_numbers[rand_num - 1]) {
                rand_num = rand_num % TOTAL + 1;
            }
            set[j] = rand_num;
            used_numbers[rand_num - 1] = 1;
        }
        
        for (int j = 0; j < N; j++) {
            printf("%d ", set[j]);
        }
        printf("\n");
    }
 
    return 0;
}