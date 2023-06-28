#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int k;
    cin >> k;

    if (binary_search(a.begin(), a.end(), k)) {
        cout << "Tree tetap balance" << endl;
    }
    else {
        cout << "Tree tidak balance" << endl;
    }

    return 0;
}
