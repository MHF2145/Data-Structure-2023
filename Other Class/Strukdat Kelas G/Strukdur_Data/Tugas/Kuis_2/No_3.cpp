#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int playGame(const vector<pair<int, int>>& Ular_Atau_Tangga)
{
    int posisi = 0;
    int Langkah_ke = 0;

    while (posisi <= 100 && Langkah_ke <= 100)
    {
        int hasil_dadu = 1 + (rand() % 6);
        Langkah_ke++;
        posisi += hasil_dadu;
        // cout << hasil_dadu << " ";

        for (const auto& sl : Ular_Atau_Tangga)
        {
            if (posisi == sl.first)
            {
                posisi = sl.second;
                break;
            }
        }
    }

    return Langkah_ke;
}

int main()
{
    vector<pair<int, int>> Ular_atau_Tangga =
    {
        // untuk .first < .second maka merupakan tangga
        // untuk .first > .second maka merupakan ular
        {17, 64},
        {99, 28},
        {19, 67},
        {8, 88},
        {53, 27},
        {36, 6},
        {30, 45},
        {78, 99}
    };

    int Total_main = 20;
    int Banyak_game_selesai = 0;
    int Total_langkah = 0;

    for (int i = 0; i < Total_main; i++)
    {
        int Langkah_ke = playGame(Ular_atau_Tangga);
        Total_langkah += Langkah_ke;

        if (Langkah_ke <= 100)
        {
            Banyak_game_selesai++;
        }
        else
        {
            continue;
        }
        
    }

    double Rata_rata = static_cast<double>(Total_langkah) / Banyak_game_selesai;
    // Jumlah permainan yang diselesaikan dalam 100 langkah
    cout << Banyak_game_selesai << endl;
    // Rata^2 jumlah langkah per permainan
    cout << Rata_rata << endl;
    // karena saya menggunakan function rand() untuk pengeluaran dadunya, jadi hasilnya selalu sama
    // bisa saja diacak dengan memberikan input sendiri
    return 0;
}
