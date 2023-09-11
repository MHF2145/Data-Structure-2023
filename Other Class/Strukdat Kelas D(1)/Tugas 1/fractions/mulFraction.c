#include "header.h"

Fraction mulFraction(Fraction a, Fraction b) {
    Fraction c;
    c.num = a.num * b.num;
    c.den = a.den * b.den;
    return c;
}