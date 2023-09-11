#include "infix_header.h"

int main()
{
    int readConvert(char[]);
    void printPostfix(char[], int);
    char post[50];
    int n = readConvert(post);
    printPostfix(post, n);
} // end main