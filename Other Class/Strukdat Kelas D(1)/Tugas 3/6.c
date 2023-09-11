#include <stdio.h>
#include <ctype.h>
#include <math.h>

typedef struct
{
    char ch;
} StackData;

#include "stack.h"

int main()
{
    int readConvert(char[]);
    void printPostfix(char[], int);
    char post[50];
    int n = readConvert(post);
    printPostfix(post, n);
} // end main

int readConvert(char post[])
{
    char getToken(void), token, c;
    int precedence(char);
    StackData temp;
    int h = 0;
    Stack S = initStack();
    printf("Type an infix expression and press Enter\n");
    token = getToken();

    while (token != '\n')
    {
        if (isdigit(token))
        {
            post[h++] = token;
        }
        else if (token == '(')
        {
            temp.ch = token;
            push(S, temp);
        }
        else if (token == ')')
        {
            while ((c = pop(S).ch) != '(')
                post[h++] = c;
        }
        else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '%' || token == '^' || token == 's' || token == 'c' || token == 't' || token == 'l')
        {
            while (!empty(S) && precedence(peek(S).ch) >= precedence(token))
                post[h++] = pop(S).ch;
            temp.ch = token;
            push(S, temp);
        }
        else if (token == ' ')
        {
            // Do nothing
        }
        else // token is an operand
        {
            int operand = token - '0';
            token = getToken();
            while (isdigit(token))
            {
                operand = operand * 10 + (token - '0');
                token = getToken();
            }
            post[h++] = operand + '0';
            continue;
        }
        token = getToken();
    } // end while

    while (!empty(S))
        post[h++] = pop(S).ch;
    return h; // the size of the expression
} // end readConvert

void printPostfix(char post[], int n)
{
    printf("\nThe postfix form is \n");
    for (int h = 0; h < n; h++)
        printf("%c ", post[h]);
    printf("\n");
} // end printPostfix

char getToken()
{
    char ch;
    while ((ch = getchar()) == ' ')
        ; // empty body
    return ch;
} // end getToken

int precedence(char c)
{
    switch (c)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 4;
    case 's':
    case 'c':
    case 't':
    case 'l':
        return 6;
    default:
        return -1;
    }
} // end precedence
