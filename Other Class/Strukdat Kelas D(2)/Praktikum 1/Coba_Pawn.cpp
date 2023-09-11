#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        char r;
        cin >> n >> m >> r;

        set<string> hand;
        for (int i = 0; i < n; i++) {
            string card;
            cin >> card;
            hand.insert(card);
        }

        bool can_win = true;
        for (int i = 0; i < m; i++) {
            string card;
            cin >> card;
            if (hand.count(card) == 0) {
                if (card[1] == r) {
                    continue;
                } else {
                    can_win = false;
                    break;
                }
            } else {
                hand.erase(card);
            }
        }

        if (can_win && hand.size() >= m) {
            cout << "YA\n";
        } else {
            cout << "TIDAK\n";
        }
    }

    return 0;
}

