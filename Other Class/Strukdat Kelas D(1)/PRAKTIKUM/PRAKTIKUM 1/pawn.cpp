#include <bits/stdc++.h>
using namespace std;

map<char, int> rank_values = {{'6', 0}, {'7', 1}, {'8', 2}, {'9', 3},
                              {'T', 4}, {'J', 5}, {'Q', 6}, {'K', 7}, {'A', 8}};

bool can_beat(const string& trump, const string& card1, const string& card2) {
    if (card1[1] == card2[1]) {
        return rank_values[card1[0]] > rank_values[card2[0]];
    } else if (card1[1] == trump[0]) {
        if (card2[1] == trump[0]) {
            return rank_values[card1[0]] > rank_values[card2[0]];
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        char trump;
        cin >> n >> m >> trump;

        vector<string> hand(n);
        for (int i = 0; i < n; i++) {
            cin >> hand[i];
        }

        vector<string> repelled(m);
        for (int i = 0; i < m; i++) {
            cin >> repelled[i];
        }

        sort(hand.begin(), hand.end(), [](const string& a, const string& b) {
            return rank_values[a[0]] < rank_values[b[0]];
        });

        priority_queue<string, vector<string>, greater<string>> pq(hand.begin(), hand.end());

        bool can_defend = true;
        for (const string& card : repelled) {
            bool found = false;
            while (!pq.empty() && !found) {
                string current_card = pq.top();
                pq.pop();
                if (can_beat(string(1, trump), current_card, card)) {
                    found = true;
                }
            }
            if (!found) {
                can_defend = false;
                break;
            }
        }

        if (can_defend) {
            cout << "YA\n";
        } else {
            cout << "TIDAK\n";
        }
    }

    return 0;
}