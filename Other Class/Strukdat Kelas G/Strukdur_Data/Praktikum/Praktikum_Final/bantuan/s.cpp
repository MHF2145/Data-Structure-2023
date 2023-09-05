#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                long long concatenated = stoll(to_string(a[i]) + to_string(a[j]));
                if (concatenated % k == 0) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}
