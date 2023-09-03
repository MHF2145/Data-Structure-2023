#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

int main() {
    const int num_simulations = 50;
    const int num_caps_per_simulation = 100;
    const int num_AE_per_100_caps = 40;
    const int num_PL_per_100_caps = 10;
    
    srand(time(NULL));
    
    int total_num_caps = 0;
    for (int i = 0; i < num_simulations; i++) {
        int num_AE = 0;
        int num_PL = 0;
        int num_caps = 0;
        while (num_AE < num_AE_per_100_caps && num_PL < num_PL_per_100_caps) {
            num_caps++;
            int rand_num = rand() % num_caps_per_simulation + 1;
            if (rand_num <= num_AE_per_100_caps) {
                num_AE++;
            } else if (rand_num <= num_AE_per_100_caps + num_PL_per_100_caps) {
                num_PL++;
            }
        }
        total_num_caps += num_caps;
    }
    double avg_num_caps = (double)total_num_caps / num_simulations;
    printf("Average number of caps required to spell apple over %d simulations: %.2f\n", num_simulations, avg_num_caps);
    
    return 0;
}