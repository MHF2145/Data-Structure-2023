#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    
    vector<int> a(n);
    map<int, int> freq;
    set<int> s;
    for(int &i : a) {
        cin >> i;
        s.insert(i);
        freq[i]++;
    }
    
    priority_queue<pair<int, int>> pq;
    for(int i : s) {
        pq.push({freq[i], i});
    }
    
    while(pq.size() > 1) {
        auto [a, b] = pq.top(); pq.pop();
        auto [x, y] = pq.top(); pq.pop();
        if(a > 1) pq.push({a - 1, b});
        if(x > 1) pq.push({x - 1, y});
    }
    
    int ans = 0;
    while(pq.size()) {
        ans += pq.top().first; pq.pop();
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T; cin >> T;
    while(T--) {
        solve();
    }
}