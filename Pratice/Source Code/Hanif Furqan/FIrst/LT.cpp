#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        string LT;                                      //input yang akan diberikan berupa string
        cin >> LT;
        int panjang = LT.length(), jwb = 0;             //inisiasi variabel panjang string
        stack<int> stacking;                            //stack untuk identifikasi string satu persatu
        stacking.push(-1);                              //stack di minus kan agar index tidak lgsg 0
        for (int i = 0; i < panjang; i++)
        {
            if (LT[i] == 'F')                           // jika dalam string terdapat F maka akan dimasukkan stack
            {
                stacking.push(i);
            }
            else if (LT[i] == 'B')                      // kalau ada B maka cek perbandingan antara mana string terpanjang lalu yang terpanjang nantinya akan jadi jawaban
            {
                if (!stacking.empty())
                    stacking.pop();
                if (!stacking.empty())
                    jwb = max(jwb, i - stacking.top());
                else
                    stacking.push(i);
            }
        }
        cout << jwb << "\n";
    }
}

