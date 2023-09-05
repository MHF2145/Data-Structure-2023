#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//pengerjaan ini menganggap bahwa nomor yang dirujuk oleh nomor 10 adalah nomor 9, bukan nomor 8 
//karena tidak ada korelasi dengan soal nomor 8

//untuk mengetahui berapa orang yang ikut melakukan lompat jauh
int i = 0;
//untuk melakukan pendataan orang yang ikut lompat jauh dengan asumsi menggunakan nama lengkap
//jika nama hanya 1 kata saja maka yang digunakan hanya char nama saja (tidak menggunakan nama2)
typedef struct
{
    char nama[21], nama2[21];
    int m, cm;
} data;
//melakukan scan dari file yang diinputkan
void inputfile(FILE *f, data orang[])
{
    while (fscanf(f, "%s %s %d %d", orang[i].nama, orang[i].nama2, &orang[i].m, &orang[i].cm) != EOF)
    {
        i++;
    }
}
//penggunaan bubble sort untuk mengurutkan lompatan dari yang terjauh hingga yang terpendek
// void swap(data *orang1, data *orang2)
// {
//     data temp = *orang1;
//     *orang1 = *orang2;
//     *orang2 = temp;
// }

// void timetosort(data orang[])
// {
//     for (int k = 0; k < i - 1; k++)
//     {
//         int maxTemp = k, j;
//         for (j = k + 1; j < i; j++)
//         {
//             if (orang[j].m >= orang[maxTemp].m)
//             {
//                 if (orang[j].m == orang[maxTemp].m)
//                 {
//                     if (orang[j].cm > orang[maxTemp].cm)
//                     {
//                         maxTemp = j;
//                     }
//                 }
//                 else
//                 {
//                     maxTemp = j;
//                 }
//             }
//         }
//         swap(&orang[maxTemp], &orang[k]);
//     }
// }

//penggunaan qsort yang lebih efektif dengan memanfaatkan fungsi bawaan dari library c
int compare(const void *a, const void *b)
{
    data *dataA = (data *)a;
    data *dataB = (data *)b;
    return ((dataB->m + dataB->cm) - (dataA->m + dataB->cm));
}

int main()
{
    //deklarasi hal yang akan digunakan, asumsi pemain yang ikut melakukan lompat jauh maksimal 100 orang
    data orang[100];
    FILE *f;
    f = fopen("input10.txt", "r");
    inputfile(f, orang);
    //qsort
    qsort(orang, i, sizeof(data), compare);

    //mengeluarkan output dengan urutan dari lompatan paling jauh hingga lompatan paling dekat
    for (int k = 0; k < i; k++)
    {
        int j = k + 1;
        printf("%d. %s %s %d.%d\n", j, orang[k].nama, orang[k].nama2, orang[k].m, orang[k].cm);
    }
}