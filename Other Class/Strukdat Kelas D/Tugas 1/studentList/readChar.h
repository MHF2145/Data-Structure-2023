//readChar.h
char readChar(FILE *in)
{
    char ch;
    while (isspace(ch = getc(in)))
        ; // empty while body
    return ch;
} // end readChar