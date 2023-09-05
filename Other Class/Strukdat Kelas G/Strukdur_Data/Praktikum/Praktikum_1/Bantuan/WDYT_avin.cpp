
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (ll i = 1; i <= h; i++)
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5;

void solve()
{
    int n;
    cin >> n;
    vector<int> v;
    map<int, int> mp;
    //    for(int i=-10000;i<100000; i++) mp[i]=0;
    loop(i, n)
    {
        int x;
        cin >> x;
        if (mp[x] == 0)
            v.pb(x);
        mp[x]++;
    }
    sort(all(v));
    // v sudah terurut ascending order

    // hitung dari kiri
    int si = v.size(), count = 1, ans = n, f = 0, id = 0;
    // mp[v[0]]--;
    for (int i = 1; i < si;)
    {
        if (v[i] ==
                v[i - 1] + 1 and
            mp[v[i]] >= mp[v[i - 1]])
        {
            count++;
            i++;
        }
        else
        {
            ans = min(ans, count);
            count = 1;

            for (int j = id; j < i; j++)
            {
                mp[v[j]]--;
                if (mp[v[j]] > 0 and f == 0)
                {
                    id = j;
                    f++;
                }
            }
            if (f == 0)
                id = i;
            f = 0;
            i = id + 1;
            // cout << v[i] << " ";
        }
        if (i == si)
        {
            // cout << count << endl;
            ans = min(ans, count);
            count = 1;
            for (int j = id; j < i; j++)
            {
                mp[v[j]]--;
                if (mp[v[j]] > 0 and f == 0)
                {
                    id = j;
                    f++;
                }
            }
            if (f == 0)
                id = i;
            i = id + 1;
            f = 0;
        }
    }
    //   loop(i, si) cout << mp[v[i]] << " ";
    cout << ans << endl;
}

/*
2
9 -5 -4 -3 -3 -2 2 3 4 5
5 5 4 3 2 1
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}