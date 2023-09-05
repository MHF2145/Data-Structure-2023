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

int m[11][11];
bool visited[11][11];

void dfs(int x, int y)
{
    visited[x][y] = 1;
    if (x - 1 >= 0 && visited[x - 1][y] == 0)
        dfs(x - 1, y);
    if (y - 1 >= 0 && visited[x][y - 1] == 0)
        dfs(x, y - 1);
    if (x + 1 <= 9 && visited[x + 1][y] == 0)
        dfs(x + 1, y);
    if (y + 1 <= 9 && visited[x][y + 1] == 0)
        dfs(x, y + 1);
}

int main()
{
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> m[i][j];
            if (m[i][j] == 1)
                visited[i][j] = 0;
            else
                visited[i][j] = 1;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (visited[i][j] == 0)
            {
                dfs(i, j);
                count++;
                // cout << "i=" << i << ",j=" << j << endl;
            }
        }
    }
    cout << count << endl;

    return 0;
}