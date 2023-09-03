#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MOD = 1e9 + 9;

ll modex(ll a, ll b, ll MOD) {
    ll res = 1;
    while(b > 0) {
        if(b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n;

    while(n--) {
        cin >> m;
        cout << "Zodiak found: " << modex(2ll, m * (m - 1ll) / 2ll, MOD) << " signs" << endl;
    }

    return 0;
}