#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

double Function(double x)
{
    // Contoh fungsi f(x)
    return x - (x * 0.1);
}

double ngitung(int Partisi)
{
    int angka_bawah_kurva = 0;

    for (int i = 0; i < Partisi; i++)
    {
        // Randomize antara 0 sampai 1 untuk x
        double x = static_cast<double>(rand()) / RAND_MAX;
        // Randomize antara 0 sampai 1 untuk y
        double y = static_cast<double>(rand()) / RAND_MAX;

        if (y < Function(x))
        {
            angka_bawah_kurva++;
        }
    }

    double area = static_cast<double>(angka_bawah_kurva) / Partisi;

    return area;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    // di integral untuk berapa bagian
    int Partisi = 100;
    double Hasil = ngitung(Partisi);

    cout << "Estimated integral: " << Hasil << endl;

    return 0;
}
