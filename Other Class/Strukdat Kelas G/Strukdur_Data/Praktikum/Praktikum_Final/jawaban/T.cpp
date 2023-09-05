#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool BFS(int start, int target);
void pathcheck(int start, int target);

const int seta = 100001;
vector<int> AdjL[seta];
int atas[seta];
bool check[seta];
int jarak[seta];

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < b; i++)
    {
        int c, d;
        cin >> c >> d;
        AdjL[c].push_back(d);
        AdjL[d].push_back(c);
    }

    memset(check, 0, sizeof(check));
    memset(jarak, -1, sizeof(jarak));
    memset(atas, -1, sizeof(atas));
    check[1] = 1;
    jarak[1] = 0;

    if (BFS(1, a) == 0)
    {
        cout << "RIP LAPET 2023" << endl;
    }

    return 0;
}

void pathcheck(int cari, int tujuan)
{
    vector<int> jalur;
    int sekarang = tujuan;
    while (sekarang != cari)
    {
        jalur.push_back(sekarang);
        sekarang = atas[sekarang];
    }

    cout << jarak[tujuan] + 1 << endl;
    jalur.push_back(cari);
    int x = jalur.size();

    for (int i = x - 1; i >= 0; i--)
    {
        cout << jalur[i];
        if (i != 0)
        {
            cout << " ";
        }
    }
    cout << endl;
}

bool BFS(int cari, int tujuan)
{
    queue<int> z;
    z.push(cari);
    while (!z.empty())
    {
        int temp = z.front();
        z.pop();

        if (temp == tujuan)
        {
            pathcheck(cari, tujuan);
            return true;
        }

        for (vector<int>::iterator i = AdjL[temp].begin(); i != AdjL[temp].end(); i++)
        {
            int tetangga = *i;
            if (!check[tetangga])
            {
                z.push(tetangga);
                check[tetangga] = 1;
                jarak[tetangga] = jarak[temp] + 1;
                atas[tetangga] = temp;
            }
        }
    }
    return false;
}
