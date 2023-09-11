#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    deque<int> dq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
        pq.push({x, i});

        if (i >= m - 1) {
            while (!pq.empty() && pq.top().second <= i - m) {
                pq.pop();
            }
            cout << pq.top().first << endl;
            dq.pop_front();
        }
    }

    return 0;
}