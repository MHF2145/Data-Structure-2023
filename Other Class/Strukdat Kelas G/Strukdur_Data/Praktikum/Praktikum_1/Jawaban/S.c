#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int count = 1;

void menghitung(int input, int uang[])
{
    int top = -999999, bottom = 999999, middle;
    for (int i = 0; i < input; i++)
    {
        if (uang[i] > top)
        {
            top = uang[i];
        }
        if (uang[i] < bottom)
        {
            bottom = uang[i];
        }
    }
    if ((top - bottom) % 2 == 0)
    {
        middle = (top - bottom) / 2;
        for (int i = 0; i < input; i++)
        {
            if (uang[i] == top)
            {
                uang[i] -= middle;
            }
            if (uang[i] == bottom)
            {
                uang[i] -= middle;
            }
        }
    }
    else if((top - bottom) % 2 == 1)
    {
        uang[0] = -1;
    }
}

void ngecek(int input, int uang[])
{
    menghitung(input, uang);
    printf("%d\n", uang[0]);
    for (int j = 0; j < input; j++)
    {
        if (uang[j] == uang[j + 1])
        {
            continue;
        }
        else if (uang[0] == -1)
        {
            break;
        }
        else
        {
            count++;
            menghitung(input, uang);
        }
    }
    if (count > 1)
    {
        printf("%d\n", count);
    }
    else
    {

        printf("-1");
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int input;
        int uang[input];
        scanf("%d", &input);
        for (int i = 0; i < input; i++)
        {
            scanf("%d", &uang[i]);
        }
        ngecek(input, uang);
    }
}