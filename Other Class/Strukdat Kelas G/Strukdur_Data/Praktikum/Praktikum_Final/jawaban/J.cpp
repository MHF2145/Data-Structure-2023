#include <iostream>
#include <vector>
#define ull unsigned long long
using namespace std;

ull bagi = 1000000009;
ull Menghitung(ull asal, ull angka);

int main()
{
    int test;
    cin >> test;

    vector<int> jumlah(test);

    int i = 0, a = 2;

    while (test--)
    {
        cin >> jumlah[i];
        i++;
    }

    for (int hitung : jumlah)
    {
        ull kombinatorika = (1LL * hitung * (hitung - 1)) / 2;
        ull ans = Menghitung(a, kombinatorika);
        cout << "Zodiak found: " << ans << " signs" << endl;
    }
}

ull Menghitung(ull asal, ull angka)
{
    ull hasil = 1;
    while (angka > 0)
    {
        if (angka % 2 == 1)
        {
            hasil = (hasil * asal) % bagi;
        }
        asal = (asal * asal) % bagi;
        angka /= 2;
    }
    return hasil;
}
