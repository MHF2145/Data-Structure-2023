#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int testCase;
    cin >> testCase;

    while (testCase--) {
        int n, m;
        cin >> n >> m;

        int arr[n][m];
        vector<pair<int, int>> v;
        char c;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> c;

                arr[i][j] = int(c) - int('0');
                if (arr[i][j] == 1) {
                    v.push_back(make_pair(i, j));
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int min_path = INT_MAX;

                for (const auto& pair : v) {
                    int result = abs(i - pair.first) + abs(j - pair.second);

                    if (result < min_path) {
                        min_path = result;
                    }
                }

                cout << min_path << " ";
            }

            cout << endl;
        }
    }

    return 0;
}
