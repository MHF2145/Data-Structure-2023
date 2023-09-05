#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000009;

long long power(long long base, long long exponent) {
    long long result = 1;
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
    vector<int> n_values(m);
    for (int i = 0; i < m; i++) {
        cin >> n_values[i];
    }

    for (int n : n_values) {
        long long combinations = (1LL * n * (n - 1)) / 2;
        long long zodiacs = power(2, combinations);
        cout << "Zodiak found: " << zodiacs << " signs" << endl;
    }

    return 0;
}
