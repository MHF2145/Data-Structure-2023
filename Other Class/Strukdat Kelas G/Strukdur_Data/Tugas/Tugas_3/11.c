#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nama[50];
    float masukan;
    float biaya;
} Stall;

float UntungBersih(Stall toko)
{
    return toko.masukan - toko.biaya;
}

void ngescan(Stall *toko, int *totaltoko)
{
    int i = 0;
    while (1)
    {
        scanf("%s", toko[i].nama);
        if (strcmp(toko[i].nama, "xxxxxx") == 0)
        {
            break;
        }
        scanf("%f%f", &toko[i].masukan, &toko[i].biaya);
        i++;
    }
    *totaltoko = i;
}

void proses(Stall *toko, int totaltoko)
{
    int i;
    float UntungTotal = 0;
    float ProfitMaks = -1e9;
    char MaxProfitToko[50][50];
    int ProfitTerbanyak = 0;

    // sortting buat nyari untung atau rugi terbanyak
    for (i = 0; i < totaltoko - 1; i++)
    {
        for (int j = 0; j < totaltoko - i - 1; j++)
        {
            if (UntungBersih(toko[j]) < UntungBersih(toko[j + 1]))
            {
                Stall temp = toko[j];
                toko[j] = toko[j + 1];
                toko[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < totaltoko; i++)
    {
        float NetBersih = UntungBersih(toko[i]);
        printf("%s: %.2f\n", toko[i].nama, NetBersih);
        UntungTotal += NetBersih;

        if (NetBersih > ProfitMaks)
        {
            ProfitMaks = NetBersih;
            ProfitTerbanyak = 1;
            strcpy(MaxProfitToko[0], toko[i].nama);
        }
        else if (NetBersih == ProfitMaks)
        {
            strcpy(MaxProfitToko[ProfitTerbanyak], toko[i].nama);
            ProfitTerbanyak++;
        }
    }

    printf("\nBanyak toko adalah: %d\n", totaltoko);
    printf("Total untung/rugi: %.2f\n", UntungTotal);
    printf("Toko dengan profit terbanyak: ");
    for (i = 0; i < ProfitTerbanyak; i++)
    {
        printf("%s", MaxProfitToko[i]);
        if (i < ProfitTerbanyak - 1)
        {
            printf(", ");
        }
    }
}

int main()
{
    Stall toko[50];
    int totaltoko = 0;

    ngescan(toko, &totaltoko);
    proses(toko, totaltoko);

    return 0;
}
