#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, hasil = 0;
    cin >> n >> k;
    vector<int> a(n), panjang(n), p(11);
    map<int, int> ukuran[11];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    p[0] = 1;
    for (int i = 1; i <= 10; i++) {
        p[i] = (p[i - 1] * 10) % k;
    }

    for (int i = 0; i < n; i++) {
        int x = a[i];
        while (x > 0) {
            panjang[i]++;
            x /= 10;
        }
        ukuran[panjang[i]][a[i] % k]++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 10; j++) {
            int r = (a[i] * p[j]) % k;
            int xr = (k - r) % k;
            hasil += ukuran[j][xr];
            if (panjang[i] == j && (r + a[i] % k) % k == 0)
                hasil--;
        }
    }

    cout << hasil;

    return 0;
}
