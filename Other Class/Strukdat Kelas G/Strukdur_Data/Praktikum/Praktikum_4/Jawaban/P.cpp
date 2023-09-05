#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    cin >> a;
    while (a--)
    {
        int b, c;
        cin >> b >> c;
        char inp, peta[b][c];
        vector<pair<int, int>> letak;
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> inp;
                peta[i][j] = (int)inp - (int)'0';
                // cout << peta[i][j] << " ";
                if (peta[i][j] == 1)
                {
                    letak.push_back(make_pair(i, j));
                }
            }
        }

        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int terdekat = 9999, jarak;
                for (const auto &iter : letak)
                {
                    jarak = abs(i - iter.first) + abs(j - iter.second);
                    jarak <= terdekat ? terdekat = jarak : terdekat = terdekat;
                }
                j == c - 1 ? cout << terdekat : cout << terdekat << " ";
            }
            cout << endl;
        }
    }
}