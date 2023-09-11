//getString.h
void getString(FILE *in, char str[])
{
    // stores, in str, the next string within delimiters
    //  the first non-whitespace character is the delimiter
    //  the string is read from the file 'in'
    char ch, delim;
    int n = 0;
    str[0] = '\0';

    // read over white space
    while (isspace(ch = getc(in)))
        ; // empty while body
    if (ch == EOF)
        return;
    delim = ch;

    while (((ch = getc(in)) != delim) && (ch != EOF))
        str[n++] = ch;
    str[n] = '\0';
} // end getString
