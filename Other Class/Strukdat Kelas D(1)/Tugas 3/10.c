#include <stdio.h>
#include <ctype.h>

typedef struct
{
    double data;
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
    StackData temp;
    int h = 0;
    Stack S = initStack();
    printf("Type an infix expression and press Enter\n");
    token = getToken();

    while (token != '\n')
    {
        if (isdigit(token))
        {
            double value = token - '0'; // convert char to double
            token = getToken();
            while (isdigit(token))
            {
                value = value * 10 + (token - '0');
                token = getToken();
            }
            post[h++] = ' '; // add space to separate numbers
            sprintf(post + h, "%.2f", value); // add number to postfix expression
            while (post[h] != '\0')
                h++;
        }
        else if (token == '(')
        {
            temp.data = token;
            push(S, temp);
        }
        else if (token == ')')
            while ((c = pop(S).data) != '(')
            {
                post[h++] = ' ';
                post[h++] = c;
            }
        else
        {
            while (!empty(S) && precedence(peek(S).data) >= precedence(token))
            {
                post[h++] = ' ';
                post[h++] = pop(S).data;
            }
            temp.data = token;
            push(S, temp);
        }
        token = getToken();
    } // end while

    while (!empty(S))
    {
        post[h++] = ' ';
        post[h++] = pop(S).data;
    }
    post[h] = '\0'; // add null terminator to postfix expression
    return h; // the size of the expression
} // end readConvert

void printPostfix(char post[], int n)
{
    printf("\nThe postfix form is \n%s\n", post);
} // end printPostfix

char getToken()
{
    char ch;
    while ((ch = getchar()) == ' ')
        ; // empty body
    return ch;
} // end getToken

int precedence(double c)
{
    if (c == '(')
        return 0;
    if (c == '+' || c == '-')
        return 3;
    if (c == '*' || c == '/')
        return 5;
} // end precedence