#include <bits/stdc++.h>

using namespace std;

int openLock(vector<string>& deadends, string target) {
    set<string> dead;
    for (int i=0; i<deadends.size(); i++) {
        dead.insert(deadends[i]);
    }
    
    set<string> visited;
    visited.insert("0000");
    
    queue<string> q;
    q.push("0000");
    
    int ans = 0;
    while(!q.empty()) {
        int n = q.size();
        while(n > 0) {
            string temp = q.front();
            q.pop();
            if (temp == target) {
                return ans;
            }
            if (dead.find(temp) != dead.end()) {
                n--;
                continue;
            }
            for (int i=0; i<4; i++) {
                char c = temp[i];
                string up, down;
                if (c == '9') {
                    up = temp.substr(0, i) + '0' + temp.substr(i + 1);
                }
                else {
                    int new_c = c - '0' + 1;
                    up = temp.substr(0, i) + to_string(new_c) + temp.substr(i + 1);
                }
                if (c == '0') {
                    down = temp.substr(0, i) + '9' + temp.substr(i + 1);
                }
                else {
                    int new_c = c - '0' - 1;
                    down = temp.substr(0, i) + to_string(new_c) + temp.substr(i + 1);
                }
                if (dead.find(up) == dead.end() && visited.find(up) == visited.end()) {
                    q.push(up);
                    visited.insert(up);
                }
                if (dead.find(down) == dead.end() && visited.find(down) == visited.end()) {
                    q.push(down);
                    visited.insert(down);
                }
            }
            n--;
        }
        ans++;
    }
    return -1;
}

int main()
{
    int d;
    cin >> d;
    vector<string> deadend(d);
    for(int i=0; i<d; i++) {
        string s;
        cin >> s;
        deadend.push_back(s);
    }
    string t;
    cin >> t;
    int ans = openLock(deadend, t);
    cout << ans << endl;
}