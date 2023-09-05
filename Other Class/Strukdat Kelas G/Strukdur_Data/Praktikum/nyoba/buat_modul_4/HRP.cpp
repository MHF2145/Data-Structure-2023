#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int n;
int m[43][43];

void dfs(int x, int y)
{
    m[x][y] = 1;
    if (x - 1 >= 0 && m[x - 1][y] == 0 || m[x - 1][y] == 2 || m[x - 1][y] == 3)
        dfs(x - 1, y);
    if (y - 1 >= 0 && m[x][y - 1] == 0 || m[x][y - 1] == 2 || m[x][y - 1] == 3)
        dfs(x, y - 1);
    if (x + 1 < n && m[x + 1][y] == 0 || m[x + 1][y] == 2 || m[x + 1][y] == 3)
        dfs(x + 1, y);
    if (y + 1 < n && m[x][y + 1] == 0 || m[x][y + 1] == 2 || m[x][y + 1] == 3)
        dfs(x, y + 1);
}

int main()
{
    pii awal, akhir;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
            if (m[i][j] == 2)
                awal = mp(i, j);
            if (m[i][j] == 3)
                akhir = mp(i, j);
        }
    }
    dfs(awal.first, awal.second);
    if (m[akhir.first][akhir.second] == 1)
        cout << "yey" << endl;
    else
        cout << "yah" << endl;
    return 0;
}