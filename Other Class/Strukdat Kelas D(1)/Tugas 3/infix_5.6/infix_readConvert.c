#include "infix_header.h"

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
            post[h++] = token;
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