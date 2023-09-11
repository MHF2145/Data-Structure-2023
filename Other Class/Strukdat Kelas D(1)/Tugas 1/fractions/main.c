#include "header.h"

int main(){
    Fraction a, b, c, sum, ans;
    a.num = 2; a.den = 5;
    b.num = 3; b.den = 7;
    c.num = 5; c.den = 8;
    sum = addFraction(b, c);
    ans = mulFraction(a, sum);
    printFraction(ans);
    return 0;
}