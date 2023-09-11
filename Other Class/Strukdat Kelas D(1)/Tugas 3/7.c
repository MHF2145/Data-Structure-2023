#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 50

typedef struct
{
    int val;
} StackData;

#include "stack.h"

int main()
{
    int readConvert(int[]);
    void printPostfix(int[]);
    int post[MAX_SIZE];
    int n = readConvert(post);
    printPostfix(post);
} // end main

int readConvert(int post[])
{
    char getToken(void), token;
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
            int val = 0;
            while (isdigit(token))
            {
                val = val * 10 + (token - '0');
                token = getToken();
            }
            post[h++] = val;
            continue;
        }

        if (token == '(')
        {
            temp.val = token;
            push(S, temp);
        }
        else if (token == ')')
        {
            while ((post[h++] = pop(S).val) != '(')
                ;
        }
        else
        {
            while (!empty(S) && precedence(peek(S).val) >= precedence(token))
                post[h++] = pop(S).val;
            temp.val = token == '+' ? -1 : token == '-' ? -2 : token == '*' ? -3 : -4;
            push(S, temp);
        }
        token = getToken();
    } // end while

    while (!empty(S))
        post[h++] = pop(S).val;

    post[h] = 0;  // Add the end marker
    return h + 1; // the size of the expression including the end marker
} // end readConvert

void printPostfix(int post[])
{
    printf("\nThe postfix form is \n");
    for (int h = 0; post[h] != 0; h++)
    {
        int val = post[h];
        if (val > 0)
        {
            printf("%d ", val);
        }
        else
        {
            switch (val)
            {
            case -1:
                printf("+ ");
                break;
            case -2:
                printf("- ");
                break;
            case -3:
                printf("* ");
                break;
            case -4:
                printf("/ ");
                break;
            }
        }
    }
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
