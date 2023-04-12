#include <stdio.h>

// fx untuk menghitung faktorial
void hitung_fakto(long long int faktorial[], long long int o)
{
    faktorial[0] = 1;
    for (long long int i = 1; i < o; i++)
    {
        faktorial[i] = faktorial[i - 1] * i;
    }
}

// fx untuk menghitung kombinasi
long long int oCp(long long int faktorial[], long long int o, long long int P)
{
    if (P > o)
        return 0;

    long long int res = faktorial[o] / faktorial[P];
    res /= faktorial[o - P];

    return res;
}

// fx untuk menghitung jumlah struktur pohon biner pencarian yang berbeda
long long int hitungbst(long long int arr[], long long int o, long long int faktorial[], long long int kiriSubTree[], long long int kananSubTree[])
{
    if (o <= 2)
    {
        return 1;
    }

    long long int root = arr[0];
    long long int ukuran_kiri = 0;
    long long int ukuran_kanan = 0;

    for (long long int i = 1; i < o; i++)
    {
        if (arr[i] < root)
        {
            kiriSubTree[ukuran_kiri++] = arr[i];
        }
        else
        {
            kananSubTree[ukuran_kanan++] = arr[i];
        }
    }

    long long int countkiri = hitungbst(kiriSubTree, ukuran_kiri, faktorial, kiriSubTree+ukuran_kiri, kananSubTree);
    long long int countkanan = hitungbst(kananSubTree, ukuran_kanan, faktorial, kiriSubTree+ukuran_kiri+1, kananSubTree+ukuran_kanan);

    long long int res = oCp(faktorial, o - 1, ukuran_kiri) * countkiri * countkanan;

    return res;
}

int main()
{
    long long int o;
    scanf("%lld", &o);

    long long int arr[o];
    for (long long int i = 0; i < o; i++)
    {
        scanf("%lld", &arr[i]);
    }

    long long int faktorial[o];
    hitung_fakto(faktorial, o);

    long long int kiriSubTree[o], kananSubTree[o];

    printf("%lld", (hitungbst(arr, o, faktorial, kiriSubTree, kananSubTree) - 1) % 1234567890);

    return 0;
}
