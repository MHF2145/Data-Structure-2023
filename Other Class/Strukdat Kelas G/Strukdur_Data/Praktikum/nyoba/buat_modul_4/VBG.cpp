#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int main()
{
    int v, n, a, b;
    cin >> v >> n;
    map<int, int> vertex, himpunan;
    for (int i = 1; i <= v; i++)
        vertex[i] = i;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (vertex[a] != vertex[b])
        {
            int temp = vertex[b];
            for (auto it = vertex.begin(); it != vertex.end(); it++)
            {
                if (it->second == temp)
                    it->second = vertex[a];
            }
        }
    }
    for (int i = 1; i <= v; i++)
    {
        himpunan[vertex[i]] = 1;
    }
    cout << himpunan.size() - 1 << endl;
    return 0;
}