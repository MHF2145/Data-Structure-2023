#include "header.h"

Fraction addFraction(Fraction a, Fraction b) {
    Fraction c;
    c.num = a.num * b.den + a.den * b.num;
    c.den = a.den * b.den;
    return c;
}
