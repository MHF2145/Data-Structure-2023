#include <stdio.h>
#include <math.h>
#include <string.h>

int num, check = 1;

void checkprima()
{
    for (int i = 2; i < sqrt(num); i++)
    {
        if (num % i == 0)
        {
            check = 0;
            break;
        }
    }
}

void strtoint(char s[])
{
    num = 0;
    int n = strlen(s);

    for (int i = 0; i < n; i++)
    {
        num = num * 10 + (s[i] - '0');
    }
}

int main()
{
    int len;
    scanf("%d", &len);
    char inp[len];
    scanf("\n%[^\n]s", inp);
    // printf("%s", inp);
    int a = 0, b = 0;
    for (int m = 0; m < len; m++)
    {
        if (inp[m] >= '0' && inp[m] <= '9')
        {
            a++;
        }
        else
        {
            b++;
        }
    }
    char angka[a], inp2[b];
    int ind = 0, ind2 = 0;
    for (int i = 0; i < len; i++)
    {
        if (inp[i] >= '0' && inp[i] <= '9')
        {
            angka[ind] = inp[i];
            ind++;
        }
        else
        {
            inp2[ind2] = inp[i];
            ind2++;
        }
    }
    // printf("%s\n", angka);
    // printf("%s\n", inp2);
    strtoint(angka);
    checkprima();
    // printf("%d\n", num);
    // printf("%d\n", check);
    int c = num % 26;
    // printf("%d\n", c);
    if (check == 0)
    {
        for (int j = 0; j < b; j++)
        {
            int e = inp2[j];
            if ((e >= 'A' && e <= 'Z') || (e >= 'a' && e <= 'z'))
            {
                if (e >= 'A' && e <= 'Z')
                {

                    if (e - c >= 'A')
                    {
                        e -= c;
                        inp2[j] = e;
                    }
                    else
                    {
                        e = (e - c) + 26;
                        inp2[j] = e;
                    }
                }
                else
                {

                    if (e - c >= 'a')
                    {
                        e -= c;
                        inp2[j] = e;
                    }
                    else
                    {
                        e = (e - c) + 26;
                        inp2[j] = e;
                    }
                }
            }
            else
            {
                continue;
            }
        }
    }

    if (check == 1)
    {
        for (int j = 0; j < b; j++)
        {
            int e = inp2[j];
            if ((e >= 'A' && e <= 'Z') || (e >= 'a' && e <= 'z'))
            {
                if (e >= 'A' && e <= 'Z')
                {

                    if (e + c <= 'Z')
                    {
                        e += c;
                        inp2[j] = e;
                    }
                    else
                    {
                        e = (e + c) - 26;
                        inp2[j] = e;
                    }
                }
                else
                {

                    if (e + c <= 'z')
                    {
                        e += c;
                        inp2[j] = e;
                    }
                    else
                    {
                        e = (e + c) - 26;
                        inp2[j] = e;
                    }
                }
            }
            else
            {
                continue;
            }
        }
    }

    printf("<h1>%s</h1>\n", inp2);
}