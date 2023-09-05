#include <stdio.h>
#include <math.h>
#include <string.h>

void inttostr(char convert[], int count)
{
    int temp, panjang = 0, n;

    n = count;
    while (n != 0)
    {
        panjang++;
        n /= 10;
    }
    for (int k = 0; k < panjang; k++)
    {
        temp = count % 10;
        count /= 10;
        convert[panjang - (k + 1)] = temp + '0';
    }
    convert[panjang] = '\0';
}

int main()
{
    int temp, count = 0;
    char N[20], convert[20];
    scanf("%s", &N);
    for (int i = 0; i < strlen(N); i++)
    {
        temp = N[i] - '0';
        count += temp;
    }
    // printf("%d", count);
    inttostr(convert, count);

    for (int j = 0; j < strlen(convert); j++)
    {
        int a = convert[j] - '0';
        if (a % 2 == 0)
        {
            printf("setiap yang bernyawa pasti akan mati %d\n", a);
        }

        if (a % 2 == 1)
        {
            printf("apa tujuan hidupmu %d\n", a);
        }
        // printf("%c\n", convert[j]);
    }
}