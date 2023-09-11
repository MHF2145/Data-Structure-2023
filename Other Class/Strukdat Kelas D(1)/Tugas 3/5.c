#include <stdio.h>
#include <ctype.h>

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
            // read in multiple digits to form the full operand
            int operand = token - '0';
            while (isdigit(token = getToken()))
            {
                operand = operand * 10 + (token - '0');
            }
            post[h++] = operand + '0'; // convert the integer operand back to a string
            continue;
        }
        else if (token == '(')
        {
            temp.ch = token;
            push(S, temp);
        }
        else if (token == ')')
            while ((c = pop(S).ch) != '(')
                post[h++] = c;
        else
        {
            while (!empty(S) && precedence(peek(S).ch) >= precedence(token))
                post[h++] = pop(S).ch;
            temp.ch = token;
            push(S, temp);
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
    if (c == '(')
        return 0;
    if (c == '+' || c == '-')
        return 3;
    if (c == '*' || c == '/')
        return 5;
} // end precedence