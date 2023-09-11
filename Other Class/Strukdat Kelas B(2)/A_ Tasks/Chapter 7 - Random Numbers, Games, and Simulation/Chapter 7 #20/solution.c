#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N = 50;
    int caps = 100;
    int ae = 40;
    int pl = 10;
    
    srand(time(0));
    
    int total = 0;
    for (int i = 0; i < N; i++) {
        int sumAE = 0;
        int sumPL = 0;
        int sumCaps = 0;
        
        while (sumAE < ae && sumPL < pl) {
            sumCaps++;
            int rand_num = rand() % caps + 1;
            if (rand_num <= ae) {
                sumAE++;
            } 
            else if (rand_num <= ae + pl) {
                sumPL++;
            }
        }

        total += sumCaps;
    }

    printf("Avg cup after %d simulations: %.2f\n", N, (double)total/N);
    return 0;
}