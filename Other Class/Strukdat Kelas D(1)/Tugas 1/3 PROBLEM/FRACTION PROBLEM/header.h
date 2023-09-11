#include<stdio.h>

typedef struct {
    int num;
    int den;
} Fraction;

Fraction addFraction(Fraction a, Fraction b);
Fraction subFraction(Fraction a, Fraction b);
Fraction mulFraction(Fraction a, Fraction b);
Fraction divFraction(Fraction a, Fraction b);
void printFraction(Fraction f);