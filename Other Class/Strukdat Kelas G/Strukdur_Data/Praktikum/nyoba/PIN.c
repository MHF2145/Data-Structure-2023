#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char pin[8];
    int temp[8];
    scanf("%s", pin);
    int a = strlen(pin);
    for (int i = 0; i < a; i++)
    {
        temp[i] = pin[i];
        // printf("%d\n", temp[i]);
    }

    int check = 1;

    for (int j = 0; j < a; j++)
    {
        int b = 0;
        for (int k = 0; k < a; k++)
        {
            if (temp[j] == temp[k])
            {
                b++;
            }
        }
        if (b >= 3)
        {
            check = 0;
            break;
        }
    }
    if (check == 1)
    {
        printf("Pin is Valid");
    }
    else
    {
        printf("Pin is Invalid");
    }
}