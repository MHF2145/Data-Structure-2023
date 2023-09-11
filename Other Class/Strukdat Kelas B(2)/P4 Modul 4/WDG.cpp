#include <bits/stdc++.h>
using namespace std;

// template <int count>
class AdjList {
private:
    int vertexCount;
    vector<vector<pair<int, int>>> adjList;

public:
    AdjList(int v) {
        adjList.resize(v);
        vertexCount = v;
    }

    void addEdge(int src, int dest, int weight = 1) {
        adjList[src].push_back(make_pair(dest, weight));
        adjList[dest].push_back(make_pair(src, weight));
    }

    vector<int> dfs(int start) {
        vector<int> outVec;
        vector<bool> visited(vertexCount, false);
        stack<int> st;
        
        st.push(start);
        visited[start] = true;
        outVec.push_back(start);

        while (!st.empty()) {
            int temp = st.top();
            st.pop();

            if (!visited[temp]) {
                outVec.push_back(temp);
                visited[temp] = true;
            }

            for (auto v: adjList[temp]) {
                if (!visited[v.first]) {
                    st.push(v.first);
                }
            }
        }

        return outVec;
    }
};

int charToInt(string str) {
    int out = 0;
    if (str[0] == 'A') {
        out += 0;
    }
    else if (str[0] == 'B') {
        out += 3;
    }
    else if (str[0] == 'C') {
        out += 6;
    }

    out += (int)(str[1] - '0');
    return out;
}

int main() {
    AdjList a(10);
    vector<bool> exist(10, false);
    int N;
    cin >> N;
    while (N--) {
        string src, dst, garbage;
        cin >> src >> garbage >> dst;
        a.addEdge(charToInt(src), charToInt(dst));
        exist[charToInt(src)] = true;
        exist[charToInt(dst)] = true;
    }

    // int unique = 0;
    // for (auto i: exist) {
    //     if (i) unique++;
    // }

    int res = 0;
    for (int i = 1; i < 10; i++) {
        if (exist[i]) {
            vector<int> temp = a.dfs(i);
            cout << temp.size() << " : ";
            for (auto x: temp) {
                cout << x << " ";
            }
            cout << endl;
            
            res += (8 - temp.size());
        }
        else {
            res += 8;
        }
        vector<int> temp = a.dfs(i);
    }

    // cout << unique << endl;

    cout << res << endl;

    return 0;
}