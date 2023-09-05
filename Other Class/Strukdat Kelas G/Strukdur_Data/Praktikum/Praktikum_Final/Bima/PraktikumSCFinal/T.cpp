#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
#define pb(x) push_back(x)
using namespace std; 

const int INT_MAKS = 100005;
vector<int> AdjList[INT_MAKS];
bool visited[INT_MAKS];
int distances[INT_MAKS], parent[INT_MAKS];


void init(int start, int target){
	memset(visited, 0, sizeof(visited));
    memset(distances, -1, sizeof(distances));
    memset(parent, -1, sizeof(parent));
    visited[start] = 1;
    distances[start] = 0;
}

void pathcheck(int start, int target) {
    vector<int> path;
    int current = target;
    while (current != start) {
        path.pb(current);
        current = parent[current];
    }
    
	cout << distances[target] + 1 << endl;
    path.pb(start);
    int n = path.size(); 
    
    for (int i = n - 1; i >= 0; i--) {
        cout << path[i];
        if (i != 0){
        	cout << " ";
		}
    }
    cout << endl;
    
}

bool bfs(int start, int target) {
    init(start, target);
	queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int temp = q.front();
        q.pop();

        if (temp == target) {
            pathcheck(start, target);
            return 1;
        }

        for (vector<int>::iterator i = AdjList[temp].begin(); i != AdjList[temp].end(); i++) {
            int neighbor = *i;
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = 1;
                distances[neighbor] = distances[temp] + 1;
                parent[neighbor] = temp;
            }
        }
    }
    return 0;
}

void addGraph(int x, int y){
	AdjList[x].pb(y); 
	AdjList[y].pb(x); 
}

int main() {
    int Node, Edge;
    cin >> Node >> Edge;
    for (int i = 0; i < Edge; i++) {
        int x, y;
        cin >> x >> y;
        addGraph(x, y); 
    }

    if (!bfs(1, Node)) {
        cout << "RIP LAPET 2023" << endl;
    }

    return 0;
}
