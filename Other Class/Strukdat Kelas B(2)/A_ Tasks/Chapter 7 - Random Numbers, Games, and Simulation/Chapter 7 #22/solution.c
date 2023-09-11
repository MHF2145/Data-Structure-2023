#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double square(double x) {
    return x * x;
}

int main() {
    const int N = 100000; 
    double total = 0.0;

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        double x = (double) rand() / RAND_MAX;
        double y = (double) rand() / RAND_MAX;

        if (y < square(x)) {
            total += square(x);
        }
    }

    double area = total / N;
    double integral = area * 1.0;

    printf("%lf\n", integral);

    return 0;
}