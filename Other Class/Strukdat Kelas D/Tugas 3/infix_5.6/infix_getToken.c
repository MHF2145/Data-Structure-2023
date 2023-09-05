char getToken()
{
    char ch;
    while ((ch = getchar()) == ' ')
        ; // empty body
    return ch;
} // end getToken