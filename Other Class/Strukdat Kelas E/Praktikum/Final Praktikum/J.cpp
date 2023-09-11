#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

const int MOD = 1000000009;

ll modex(ll base, ll exponent) {
    ll result = 1;
    base %= MOD;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }

    return result;
}

int main() {
    int m;
    cin >> m;

    vector<ll> results;

    for (int i = 0; i < m; i++) {
        int n;
        ll formulapola;
        cin >> n;

        formulapola = modex(2, (ll)n * (n - 1) / 2);

        results.push_back(formulapola);
    }

    for (int i = 0; i < results.size(); i++) {
        cout << "Zodiak found: " << results[i] << " signs" << endl;
    }

    return 0;
}
