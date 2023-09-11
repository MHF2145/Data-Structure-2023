// Source code for Graph


//  Adjacency Matrix

/*
	int main()
	{
	    // n is the number of vertices
	    // m is the number of edges
	    int n, m;
	    cin >> n >> m;
	    int adjMat[n + 1][n + 1];
	    for (int i = 0; i < m; i++) {
	        int u, v;
	        cin >> u >> v;
	        adjMat[u][v] = 1;
	        adjMat[v][u] = 1;
	        // for a directed graph with an edge pointing from u
	        // to v,we just assign adjMat[u][v] as 1
	    }
	 
	    return 0;
	}

*/

//  Adjacency List

/*
	
	// A simple representation of graph using STL
	#include <bits/stdc++.h>
	using namespace std;
	 
	// A utility function to add an edge in an
	// undirected graph.
	void addEdge(vector<int> adj[], int u, int v)
	{
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	 
	// A utility function to print the adjacency list
	// representation of graph
	void printGraph(vector<int> adj[], int V)
	{
	    for (int v = 0; v < V; ++v) {
	        cout << "\n Adjacency list of vertex " << v
	             << "\n head ";
	        for (auto x : adj[v])
	            cout << "-> " << x;
	        cout << endl;
	    }
	}
	 
	// Driver code
	int main()
	{
	    int V = 5;
	    vector<int> adj[V];
	    addEdge(adj, 0, 1);
	    addEdge(adj, 0, 4);
	    addEdge(adj, 1, 2);
	    addEdge(adj, 1, 3);
	    addEdge(adj, 1, 4);
	    addEdge(adj, 2, 3);
	    addEdge(adj, 3, 4);
	    printGraph(adj, V);
	    return 0;
	}
*/

//  Depth First Search (DFS)

/*
		void dfs(vector<long> &result, long start)
		{
	    vector<bool> visited(vertex, false);
	    stack<long> st;
	
	    st.push(start);
	    visited[start] = true;
	    result.push_back(start);
	
	    while(!st.empty()){
	        long temp = st.top();
	        st.pop();
	
	        if(!visited[temp]){
	            result.push_back(temp);
	            visited[temp] = true;
	        }
	
	        for(auto it:adjList[temp]){
	            if (!visited[it.first])
	                st.push(it.first);
	        }
	    }
	}

*/

//  Breadth First Search (BFS)

/*
	void bfs(vector<long> &result, long start)
	{
	    vector<bool> visited(vertex, false);
	    queue<long> q;
	
	    q.push(start);
	    visited[start] = true;
	    result.push_back(start);
	
	    while(!q.empty()){
	        long temp = q.front();
	        q.pop();
	
	        for(auto it:adjList[temp]){
	            if (!visited[it.first]){
	                q.push(it.first);
	                visited[it.first] = true;
	                result.push_back(it.first);
	            }
	        }
	    }
	}
*/

