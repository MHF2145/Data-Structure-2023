#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b, c;
    int e, q;
    cin >> e >> q;
    
    map<string, pair<string, map<string, vector<string>>>> m;
    
    while(e--) {
        cin >> a >> b;
        map<string, vector<string>> tem;
        m[a] = make_pair(b, tem);
    }

    cin.ignore();

    while(q--) {
        cin >> a >> b;
        cin.ignore();
        getline(cin, c);

        if(m.find(a) != m.end() && m.find(b) != m.end()) m[b].second[a].push_back(c);
    }
    
    for(const auto& entry : m) {
        if (entry.second.second.empty()) continue;

        cout << "===========" << endl << "Mail: " << entry.second.first << endl;

        for(const auto& i : entry.second.second) {
            cout << "From: " << m[i.first].first << endl;
            for (const auto& j : i.second) {
                cout << ">> " << j << endl;
            }
        }
    }

    return 0;
}
