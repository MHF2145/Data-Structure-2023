#include <stdio.h>
#include <stdlib.h>

void cetak(int max, int x[])
{
    for (int d = 0; d < max; d++)
    {
        printf("%2d", x[d]);
        printf("\t");
    }
}

void swap(int x, int y, int datanya[])
{
    int tmp;
    tmp = datanya[x];
    datanya[x] = datanya[y];
    datanya[y] = tmp;
}

void bubblesort(int max, int a[])
{
    int i, j, k, count = 1;
    bool swapped;
    for (i = 0; i < max; i++)
    {
        swapped = false;
        for (j = max - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(j, j - 1, a);
                printf("\nswap ke %2d \t", count++);
                cetak(max, a);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}


int main()
{
    int data[] = {77, 33, 44, 88, 22, 66, 55};
    int max = 7;
    printf("data awal \t");
    cetak(max, data);
    bubblesort(max, data);
    system("pause");
    return 0;
}
