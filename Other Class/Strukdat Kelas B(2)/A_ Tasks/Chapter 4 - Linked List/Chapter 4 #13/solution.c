#include <stdio.h>

#include "BigInt.h"

int main() {
    BigInt a, b;
    BigInt* sum;
    init(&a);
    init(&b);

    set(&a, "999");
    set(&b, "9999");
    sum = add(&a, &b);

    printf("A = %s\n", toString(&a));
    printf("B = %s\n", toString(&b));
    printf("A+B = %s\n", toString(sum));
}
