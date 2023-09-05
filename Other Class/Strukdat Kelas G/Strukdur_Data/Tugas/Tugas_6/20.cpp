#include <iostream>
#include <random>
using namespace std;

int simulateCollection()
{
    // Nomer random
    random_device random;
    mt19937 uji(random());

    // Define the probabilities of each letter occurrence
    double Kemungkinan_A = 0.4;
    double Kemungkinan_E = 0.4;
    double Kemungkinan_P = 0.1;
    double Kemungkinan_L = 0.1;

    int Total = 0;

    // simulasi 50 kemungkinan
    for (int i = 0; i < 50; i++)
    {
        int tutup_botol = 0;
        int Hitung_A = 0, Hitung_E = 0, Hitung_L = 0, Hitung_P = 0;

        while (Hitung_A < 40 || Hitung_P < 10 || Hitung_L < 10 || Hitung_E < 40)
        {
            tutup_botol++;

            // random antara 0 dan 1
            double randNum = generate_canonical<double, 10>(uji);

            if (randNum < Kemungkinan_A && Hitung_A < 40)
            {
                Hitung_A++;
            }
            else if (randNum < Kemungkinan_A + Kemungkinan_P && Hitung_P < 10)
            {
                Hitung_P++;
            }
            else if (randNum < Kemungkinan_A + Kemungkinan_P + Kemungkinan_L && Hitung_L < 10)
            {
                Hitung_L++;
            }
            else if (Hitung_E < 40)
            {
                Hitung_E++;
            }
        }

        Total += tutup_botol;
    }

    // hitung total dan cari rata - rata
    return Total / 50;
}

int main()
{
    int Rata_rata = simulateCollection();

    cout << "Rata - rata per simulasi: " << Rata_rata << endl;

    return 0;
}
