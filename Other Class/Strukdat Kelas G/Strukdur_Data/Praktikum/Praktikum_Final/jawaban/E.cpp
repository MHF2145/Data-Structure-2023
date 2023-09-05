#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Hubung
{
    int ke;
    int bahaya;

    Hubung(int tujuan, int LvLbahaya)
    {
        ke = tujuan;
        bahaya = LvLbahaya;
    }
};

int mencariMax(vector<vector<Hubung>> &graf, int asal, int akhir)
{
    int n = graf.size();

    vector<int> lvl_bahaya(n, 99999);
    lvl_bahaya[asal] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> atur;
    atur.push({0, asal});

    while (!atur.empty())
    {
        int sekarang = atur.top().second;
        int sek_bahaya = atur.top().first;
        atur.pop();

        if (sekarang == akhir)
            break;

        for (Hubung langkah : graf[sekarang])
        {
            int lanjut = langkah.ke;
            int bahaya = max(sek_bahaya, langkah.bahaya);

            if (bahaya < lvl_bahaya[lanjut])
            {
                lvl_bahaya[lanjut] = bahaya;
                atur.push({bahaya, lanjut});
            }
        }
    }

    return lvl_bahaya[akhir];
}

int main()
{
    int a, b, x, y, z;
    cin >> a >> b;

    vector<vector<Hubung>> graf(a + 1);
    for (int i = 0; i < b; i++)
    {
        cin >> x >> y >> z;
        graf[x].push_back(Hubung(y, z));
        graf[y].push_back(Hubung(x, z));
    }

    int ans = mencariMax(graf, 1, a);
    cout << ans << endl;
}