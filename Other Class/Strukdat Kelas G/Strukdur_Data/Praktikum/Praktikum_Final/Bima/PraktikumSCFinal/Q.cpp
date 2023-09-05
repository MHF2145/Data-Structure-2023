#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define psl pair<string, ll>
using namespace std;

map<int, psl > listRest; 

struct graph{
    int vertexCount, edgeCount;
    vector<vector<pair<int, int> > > adjList;
    
    void init(int v){
        vertexCount = v;
        edgeCount = 0;

        for(int i=0; i<vertexCount; i++){
            adjList.pb({});
        }
    }

    void addEdge(int vertex1, int vertex2, int weight){
        adjList[vertex1].pb(mp(vertex2, weight));
        adjList[vertex2].pb(mp(vertex1, weight));
        edgeCount++;
    }

    void dijkstra(vector<int> &result, int start){
        vector<bool> visited(vertexCount, false);
        priority_queue <pair<int, int>, 
                        vector <pair<int, int>>, 
                        greater <pair<int, int>> > pq;
        result = vector<int>(vertexCount, LONG_MAX);
        
        pq.push(mp(0, start));
        result[start] = 0;

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            visited[temp.second] = true;

            for(auto vertex:adjList[temp.second]){
                int nextVertex = vertex.first;
                int weight = vertex.second;

                if(!visited[nextVertex]){
                    if(temp.first + weight < result[nextVertex]) {
                        result[nextVertex] = temp.first + weight;
                        pq.push(mp(result[nextVertex], nextVertex));
                    }
                }
            }
        }
    }
};

int main(){
	int n; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		string rest; 
		int prc; 
		cin >> rest >> prc; 
		listRest[i] = mp(rest, prc);
	}
	int t;
	cin >> t; 
	graph g; 
	g.init(t + 5); 
	
	while (t--){
		int a, b, c; 
		cin >> a >> b >> c; 
		g.addEdge(a, b, c);
	}
	
	int maxDist; 
	cin >> maxDist; 
	
	vector <int> jikstra; 
	g.dijkstra(jikstra, 0);
	
	vector<int> Nodes;
	int N = jikstra.size();
    for (int i = 0; i < N; i++) {
        if (jikstra[i] <= maxDist) {
            Nodes.pb(i);
        }
    }
    
    Nodes.erase(Nodes.begin()); 
    
    int mins = LLONG_MAX; 
    string str = "";
    for (int i = 0; i < Nodes.size(); i++) {
        int idx = Nodes[i];
        int price = listRest[idx].second;
        if (price < mins) {
            mins = price;
            str = listRest[idx].first;
        }
    }
    cout << "hari ini makan di " << str << endl;
	return 0; 
} 

