#include <stdio.h>
#include <ctype.h>

typedef struct
{
    char ch;
} StackData;

#include "stack.h"

int readConvert(char[]);
void printPostfix(char[], int);