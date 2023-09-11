#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "1\n";
        } else if (n <= 3) {
            cout << "-1\n";
        } else {
            vector<int> a(n);
            for (int i = 0; i < n; i++) {
                a[i] = i + 1;
            }
            swap(a[0], a[2]);
            for (int i = 3; i < n; i += 2) {
                swap(a[i], a[i - 1]);
            }
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
