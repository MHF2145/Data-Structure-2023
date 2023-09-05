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

int main()
{
    ll n, a, b, res = 0ll, derajatMax = 0ll, minSelisih = LONG_LONG_MAX;
    cin >> n;
    vl adjList[n + 5ll];
    for (ll i = 0ll; i < n - 1ll; i++)
    {
        cin >> a >> b;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    for (ll i = 1ll; i <= n; i++)
    {
        ll temp = adjList[i].size();
        res += ceil(log(temp) / log(2ll)) + temp - 1ll;
        derajatMax = max(derajatMax, temp);
        ll selisih = (ceil(log(temp + 1ll) / log(2ll)) + temp) - (ceil(log(temp) / log(2ll)) + temp - 1ll);
        minSelisih = min(minSelisih, selisih);
    }
    res += minSelisih;
    cout << res << endl;
    return 0;
}