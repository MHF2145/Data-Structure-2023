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
    if (n > 0)
    {
        printPostfix(post, n);
    }
} // end main

int readConvert(char post[])
{
    char getToken(void), token, c;
    int precedence(char);
    StackData temp;
    int h = 0;
    int brackets = 0; // keep track of number of opening brackets
    Stack S = initStack();
    printf("Type an infix expression and press Enter\n");
    token = getToken();

    while (token != '\n')
    {
        if (isdigit(token))
            post[h++] = token;
        else if (token == '(')
        {
            brackets++;
            temp.ch = token;
            push(S, temp);
        }
        else if (token == ')')
        {
            if (brackets > 0)
            {
                brackets--;
                while ((c = pop(S).ch) != '(')
                    post[h++] = c;
            }
            else
            {
                printf("Error: Mismatched closing bracket.\n");
                return -1;
            }
        }
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
    {
        if (brackets > 0)
        {
            printf("Error: Mismatched opening bracket.\n");
            return -1;
        }
        post[h++] = pop(S).ch;
    }
    if (brackets > 0)
    {
        printf("Error: Mismatched opening bracket.\n");
        return -1;
    }
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