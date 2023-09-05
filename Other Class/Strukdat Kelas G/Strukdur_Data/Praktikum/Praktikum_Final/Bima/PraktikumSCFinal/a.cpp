#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

int main() {
    int n, q, i, j, k, from, to;
    fastio;
    cin >> n >> q;
    vector<vector<vector<string> > > out(q + 5, vector<vector<string> >(q + 5, vector<string>(1005)));
    vector<vector<string> > s(q + 5, vector<string>(2));
    string a, b, c;
    vector<vector<int> > count(q + 10, vector<int>(q + 10, 0));

    for (i = 0; i < n; i++) {
        cin >> s[i][0] >> s[i][1];
    }

    bool swapped, tofound, fromfound;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (s[j][0] > s[j + 1][0]) {
                swap(s[j][0], s[j + 1][0]);
                swap(s[j][1], s[j + 1][1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }

    for (i = 0; i < q; i++) {
        cin >> a >> b;
        cin.ignore();
        getline(cin, c);
        tofound = false;
        fromfound = false;

        for (j = 0; j < n; j++) {
            if (a == s[j][0]) {
                fromfound = true;
                from = j;
                break;
            }
        }

        for (j = 0; j < n; j++) {
            if (b == s[j][0]) {
                tofound = true;
                to = j;
                break;
            }
        }

        if (!(tofound) || !(fromfound)) {
            continue;
        }

        out[to][from][count[to][from]] = c;
        count[to][from] += 1;
    }

    for (i = 0; i < n; i++) {
        bool ada = false;
        for (j = 0; j < n; j++) {
            if (count[i][j] != 0) {
                ada = true;
            }
        }
        if (!ada) {
            continue;
        }

        cout << "===========" << endl;
        cout << "Mail: " << s[i][1] << endl;

        for (j = 0; j < n; j++) {
            if (count[i][j] == 0 || i == j) {
                continue;
            }

            cout << "From: " << s[j][1] << endl;

            for (k = 0; k < count[i][j]; k++) {
                cout << ">> " << out[i][j][k] << endl;
            }
        }
    }

    return 0;
}
