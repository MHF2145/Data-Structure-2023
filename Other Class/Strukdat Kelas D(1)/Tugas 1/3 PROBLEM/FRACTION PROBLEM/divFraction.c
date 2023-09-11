#include "header.h"

Fraction divFraction(Fraction a, Fraction b) {
    Fraction c;
    c.num = a.num * b.den;
    c.den = a.den * b.num;
    return c;
}