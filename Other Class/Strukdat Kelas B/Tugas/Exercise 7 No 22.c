#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

double f(double x) {
    return x * x;
}

int main() {
    int n = 100000; // number of points to generate
    double sum = 0.0; // sum of values of f(x) at generated points

    // set random seed using current time
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        // generate random x and y between 0 and 1
        double x = (double) rand() / RAND_MAX;
        double y = (double) rand() / RAND_MAX;

        // if the point (x, y) is below the curve of f(x), add its contribution to the sum
        if (y < f(x)) {
            sum += f(x);
        }
    }

    // estimate the area under the curve of f(x) as the sum divided by the total number of points
    double area = sum / n;

    // estimate the integral of f(x) from 0 to 1 as the area times the width of the interval [0, 1]
    double integral = area * 1.0;

    printf("The estimated integral of f(x) from 0 to 1 is: %f\n", integral);

    return 0;
}