#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 998244353

using namespace std;

ll M = 1e9 + 7;
const ll N = 1e4 + 5;
const ll vertex = 1e6 + 5;
ll MM = 1e18;

void solve()
{
    int n;
    cin >> n;
    loop(_, n)
    {
        vector<vector<int>> v(200);
        vector<int> cek(200, -1);
        int a, b;
        cin >> a >> b;
        loop(i, b)
        {
            int x, y;
            cin >> x >> y;
            x--, y--;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        int f = 1;
        loop(i, a)
        {
            if (v[i].size() > 0)
            {
                if (cek[i] == -1)
                    cek[i] = 0;
                for (auto j : v[i])
                {
                    if (cek[j] == -1)
                        cek[j] = (1 ^ cek[i]);
                    else if (cek[j] == cek[i])
                    {
                        f = 0;
                        break;
                    }
                }
            }
        }
        // loop(i, a) {
        //     cout << cek[i] << " ";
        // }
        // cout << endl;
        cout << "Penelitian #" << _ + 1 << ":" << endl;
        if (!f)
        {
            cout << "Kak, aku menemukan ketidaksesuaian dengan hipotesis!" << endl
                 << endl;
        }
        else
        {
            cout << "Tidak ada yang aneh, kak!" << endl
                 << endl;
        }
    }
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(0);
    // ll t; cin>>t;
    // while(t--)
    solve();
    return 0;
}
