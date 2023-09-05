#include <stdio.h>
#include <ctype.h>

typedef struct
{
    int num;
} StackData;

#include "stack.h"

int eval(char post[], int n)
{
    int i;
    char token;
    StackData temp, op1, op2;
    Stack S = initStack();

    for (i = 0; i < n; i++)
    {
        token = post[i];
        if (isdigit(token))
        {
            temp.num = token - '0'; // convert char to int
            push(S, temp);
        }
        else
        {
            op2 = pop(S);
            op1 = pop(S);
            switch (token)
            {
            case '+':
                temp.num = op1.num + op2.num;
                break;
            case '-':
                temp.num = op1.num - op2.num;
                break;
            case '*':
                temp.num = op1.num * op2.num;
                break;
            case '/':
                temp.num = op1.num / op2.num;
                break;
            }
            push(S, temp);
        }
    }
    return pop(S).num;
}
