#include "infix_header.h"

void printPostfix(char post[], int n)
{
    printf("\nThe postfix form is \n");
    for (int h = 0; h < n; h++)
        printf("%c ", post[h]);
    printf("\n");
} // end printPostfix