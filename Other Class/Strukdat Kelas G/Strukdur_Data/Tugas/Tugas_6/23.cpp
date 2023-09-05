#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int ngacak_dadu()
{
    return (rand() % 6) + 1; // Ngacak dadu antara 1 sampe 6
}

int ngacak_kartu()
{
    return (rand() % 13) + 1; // ngacak kartu As = 1, Jack = 11, Queen = 12, King = 13, sisanya sesuai angk
}

// #Dealer tidak pernah rugi (Pemain dirugikan disini)
int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    const int jumlah_game = 20;
    int Total_cuan = 0;

    for (int i = 0; i < jumlah_game; i++)
    {
        int dadu_1 = ngacak_dadu();
        int dadu_2 = ngacak_dadu();
        int jumlah = dadu_1 + dadu_2;

        if (jumlah % 2 == 0)
        {
            // Kalau jumlah dadu genap = kalah
            Total_cuan -= 5;
        }
        else
        {
            // kalau jumlah dadu ganjil = lanjut main
            int angka_kartu = ngacak_kartu();

            if (angka_kartu == 1 || angka_kartu == 3 || angka_kartu == 5 || angka_kartu == 7 || angka_kartu == 9)
            {
                // Jika dapet 1 (As) atau 3 atau 5 atau 7 atau 9 dia dapet uang sebanyak angka yang didapet + $5
                Total_cuan += angka_kartu + 5;
            }
            else
            {
                // Kalau dapet selain itu kalah lagi
                Total_cuan -= 5;
            }
        }
    }

    double rata_rata = static_cast<double>(Total_cuan) / jumlah_game;

    cout << "Rata - rata uang yang dimenangkan setiap game: $" << rata_rata << endl;

    return 0;
}
