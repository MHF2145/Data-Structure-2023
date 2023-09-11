#include <iostream>
#include <vector>
using namespace std;
vector< int > adjList[100];
bool visited[100] = {0};
int max_final = 0;

void dfs(int curVertex, int max_vrtx){
    visited[curVertex] = 1;
    for(auto &i : adjList[curVertex]){
        if (!visited[i]){
            dfs(i, max_vrtx + 1);
        }
    }
    max_final = max(max_vrtx,max_final);
    visited[curVertex] = 0; // backtrack
}

int main()
{
    int V, E, start;
    cin >> V >> E;
    while(E--){
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    cin >> start;
    dfs(start, 0);
    cout << max_final << endl;
    return 0;
}