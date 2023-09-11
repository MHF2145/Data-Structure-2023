#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> rank;

int find(int x) {
    if (x != parent[x]) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (rank[x] > rank[y]) {
        parent[y] = x;
    } else {
        parent[x] = y;
        if (rank[x] == rank[y]) {
            rank[y]++;
        }
    }
}

struct CompareConfidence {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
};

struct CompareWeight {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};

void mainFunction() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<set<int>> adj(N + 1);
    vector<map<int, int>> wei(N + 1);
    vector<int> conf(N + 1);
    parent.resize(N + 1);
    rank.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> conf[i];
        parent[i] = i;
        rank[i] = 0;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareConfidence> pqConf;
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareWeight> pqWeight;

    for (int i = 0; i < M; i++) {
        int verA, verB, weight;
        cin >> verA >> verB >> weight;
        adj[verA].insert(verB);
        adj[verB].insert(verA);
        wei[verA][verB] = weight;
        wei[verB][verA] = weight;
        unite(verA, verB);
    }

    for (int i = 1; i <= N; i++) {
        int component = find(i);
        pqConf.push({conf[i], component});
        for (const auto& neighbor : adj[i]) {
            int weight = wei[i][neighbor];
            pqWeight.push({component, weight});
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        char sign;
        cin >> sign;
        if (sign == '!') {
            int num;
            cin >> num;
            if (num == 1) {
                int A, X;
                cin >> A >> X;
                int component = find(A);
                pqConf.push({X, component});
            } else {
                int A, B, X;
                cin >> A >> B >> X;
                int componentA = find(A);
                int componentB = find(B);
                if (componentA != componentB) {
                    unite(A, B);
                    pqWeight.push({componentA, X});
                }
            }
        } else {
            int num;
            cin >> num;
            if (num == 1) {
                int A;
                cin >> A;
                int component = find(A);
                int lowestWei = INT_MAX;
                while (!pqWeight.empty() && pqWeight.top().first == component) {
                    lowestWei = min(lowestWei, pqWeight.top().second);
                    pqWeight.pop();
                }
                cout << (lowestWei == INT_MAX ? 0 : lowestWei) << '\n';
            } else {
                int A, B;
                cin >> A >> B;
                int componentA = find(A);
                int componentB = find(B);
                if (componentA == componentB) {
                    cout << "0\n";
                } else {
                    int maxConfA = 0;
                    int maxConfB = 0;
                    while (!pqConf.empty() && pqConf.top().second == componentA) {
                        maxConfA = max(maxConfA, pqConf.top().first);
                        pqConf.pop();
                    }
                    while (!pqConf.empty() && pqConf.top().second == componentB) {
                        maxConfB = max(maxConfB, pqConf.top().first);
                        pqConf.pop();
                    }
                    cout << (maxConfA + maxConfB) << '\n';
                }
            }
        }
    }
}

int main() {
    mainFunction();
    return 0;
}
