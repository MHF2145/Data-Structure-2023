int precedence(char c)
{
    if (c == '(')
        return 0;
    if (c == '+' || c == '-')
        return 3;
    if (c == '*' || c == '/')
        return 5;
} // end precedence