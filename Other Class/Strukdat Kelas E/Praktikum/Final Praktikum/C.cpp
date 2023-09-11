#include <iostream>
#include <vector>

using namespace std;

int itungsisa(int n, int* prices) {
    vector<int> hitung(101, 0);

    for (int i = 0; i < n; i++) {
        hitung[prices[i]]++;
    }

    int pairs = 0;
    int singles = 0;

    for (int i = 1; i <= 100; i++) {
        pairs += hitung[i] / 2;
        singles += hitung[i] % 2;
    }

    if (pairs <= singles) {
        return pairs;
    } else {
        return singles + (pairs - singles) % 2;
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int prices[n];
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }

        int sisa = itungsisa(n, prices);
        cout << sisa << endl;
    }

    return 0;
}
