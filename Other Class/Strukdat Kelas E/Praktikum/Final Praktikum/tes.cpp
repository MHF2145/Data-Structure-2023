#include <iostream>
#include <map>
#include <cmath>

using namespace std;

void drawBox(int num, int count) {
    cout << "  " << num << endl;
    cout << " ----" << endl;
    cout << "|    |" << endl;
    cout << "| " << count << "  |" << endl;
    cout << "|    |" << endl;
    cout << " ----" << endl;
    cout << endl;
}

void drawPairing(int num1, int num2) {
    cout << "Pairing: " << num1 << " - " << num2 << endl;
    cout << endl;
}

int calculateValue(const map<int, int>& price) {
    if (price.size() == 1) {
        return 0;
    } else if (price.size() == 2) {
        auto it1 = price.begin();
        auto it2 = next(it1);
        if (it1->second != it2->second) {
            drawBox(it1->first, it1->second);
            drawBox(it2->first, it2->second);
            drawPairing(it1->first, it2->first);
            return std::abs(it1->second - it2->second);
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<int, int> price;

        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            price[p]++;
        }

        int result = calculateValue(price);
        
        if (result != -1) {
            cout << "Output: " << result << endl;
        } else {
            int maxCount = 0;
            for (const auto& pair : price) {
                maxCount = max(maxCount, pair.second);
                drawBox(pair.first, pair.second);
            }

            if (maxCount > n / 2) {
                cout << "Output: " << 2 * maxCount - n << endl;
            } else {
                cout << "Output: " << n % 2 << endl;
            }
        }
    }

    return 0;
}
