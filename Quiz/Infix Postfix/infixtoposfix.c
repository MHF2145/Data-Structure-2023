#include<stdio.h>
#include<ctype.h>

char tumpuk[100];
int atas = -1;

void masukkan(char x)
{
    tumpuk[++atas] = x;
}

char keluarkan()
{
    if(atas == -1)
        return -1;
    else
        return tumpuk[atas--];
}

int duluan(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("masukkan : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;

    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            masukkan(*e);
        else if(*e == ')')
        {
            while((x = keluarkan()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(duluan(tumpuk[atas]) >= duluan(*e))
                printf("%c ",keluarkan());
            masukkan(*e);
        }
        e++;
    }

    while(atas != -1)
    {
        printf("%c ",keluarkan());
    }return 0;
}
