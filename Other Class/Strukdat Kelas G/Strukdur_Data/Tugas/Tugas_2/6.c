#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//untuk mengecek hari yang akan dibandingkan jaraknya berdasarkan hari
int ind = 0;
//untuk mengetahui tanggal tersebut dengan spesifik
typedef struct
{
    int day, month, year;
} date;
//untuk melakukan scan dari file yang diinputkan
void inputfile(FILE *f, date tanggal[])
{
    while (fscanf(f, "%d %d %d", &tanggal[ind].day, &tanggal[ind].month, &tanggal[ind].year) != EOF)
    {
        ind++;
    }
}
//melakukan perbandingan jarak hari menggunakan fungsi berikut
int jarak(date tanggal[])
{
    if (tanggal[1].year > tanggal[0].year || tanggal[1].year == tanggal[0].year && tanggal[1].month > tanggal[0].month || tanggal[1].year == tanggal[0].year && tanggal[1].month == tanggal[0].month && tanggal[1].day > tanggal[0].day)
    {

        if (tanggal[1].year > tanggal[0].year && tanggal[1].month == tanggal[0].month && tanggal[1].day == tanggal[0].day)
        {
            return (tanggal[1].year - tanggal[0].year) * 365;
        }

        else if (tanggal[1].year > tanggal[0].year && tanggal[1].month > tanggal[0].month && tanggal[1].day == tanggal[0].day)
        {
            return ((tanggal[1].year - tanggal[0].year) * 365) + ((tanggal[1].month - tanggal[0].month) * 30);
        }

        else
        {
            return ((tanggal[1].year - tanggal[0].year) * 365) + ((tanggal[1].month - tanggal[0].month) * 30) + (tanggal[1].day - tanggal[0].day);
        }
    }

    else if (tanggal[0].year > tanggal[1].year || tanggal[1].year == tanggal[0].year && tanggal[0].month > tanggal[1].month || tanggal[1].year == tanggal[0].year && tanggal[1].month == tanggal[0].month && tanggal[0].day > tanggal[1].day)
    {

        if (tanggal[1].year > tanggal[0].year && tanggal[1].month == tanggal[0].month && tanggal[1].day == tanggal[0].day)
        {
            return (tanggal[1].year - tanggal[0].year) * 365;
        }

        else if (tanggal[1].year > tanggal[0].year && tanggal[1].month > tanggal[0].month && tanggal[1].day == tanggal[0].day)
        {
            return ((tanggal[1].year - tanggal[0].year) * 365) + ((tanggal[1].month - tanggal[0].month) * 30);
        }

        else
        {
            return ((tanggal[1].year - tanggal[0].year) * 365) + ((tanggal[1].month - tanggal[0].month) * 30) + (tanggal[1].day - tanggal[0].day);
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
    //melakukan deklarasi hal yang akan diperlukan
    date tanggal[3];
    FILE *f;
    f = fopen("input6.txt", "r");
    inputfile(f, tanggal);
    //melakukan pengecekan apakah semua input benar dan akurat
    // for (int i = 0; i < ind; i++)
    // {
    //     printf("%d\n", i);
    //     printf("%d %d %d\n", tanggal[i].day, tanggal[i].month, tanggal[i].year);
    // }
    //mengeluarkan output berupa jarak tanggal 
    //(dengan bernilai positif jika tanggal ke 1 terdapat sebelum tanggal ke 2
    // dan bernilai negatif jika tanggal ke 2 terdapat sebelum tanggal ke 1)
    printf("%d\n", jarak(tanggal));

    return 0;
}