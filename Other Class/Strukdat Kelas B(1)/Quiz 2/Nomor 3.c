#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

int main() {
    int simulations = 50;
    int caps_per_simulation = 100;
    int AE_per_100_caps = 40;
    int PL_per_100_caps = 10;
    
    srand(time(NULL));
    
    int total_caps = 0;
    for (int i = 0; i < simulations; i++) {
        int AE = 0;
        int PL = 0;
        int caps = 0;
        while (AE < AE_per_100_caps && PL < PL_per_100_caps) {
            caps++;
            int rand_num = rand() % caps_per_simulation + 1;
            if (rand_num <= AE_per_100_caps) {
                AE++;
            } else if (rand_num <= AE_per_100_caps + PL_per_100_caps) {
                PL++;
            }
        }
        total_caps += caps;
        printf("tutup botol simulasi ke %d: %d\n", i + 1, caps);
    }
    double avg_caps = (double)total_caps / simulations;
    printf("rata-rata tutup botol: %.2f\n", avg_caps);
    
    return 0;
}