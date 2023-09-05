#include <bits/stdc++.h>
using namespace std;

class unweighted_graph
{
private:
    long vertex, edge;
    vector<vector<long>> adjList;
    bool isDirected, hasCircle;
    void depth_first_search(long vertex, vector<bool> &visited, vector<long> &v);
    void breadth_first_search(long vertex, vector<bool> &visited, vector<long> &v);
    void circleCheck(long parent, long vertex, vector<bool> &visited);

public:
    unweighted_graph(long vertex, bool isDirected);
    void addEdge(long vertex1, long vertex2);
    long vertexCount();
    long edgeCount();
    void dfs(long vertex, vector<long> &v);
    void bfs(long vertex, vector<long> &v);
    bool linearCheck();
    bool circleSearch();
};

unweighted_graph::unweighted_graph(long vertex, bool isDirected)
{                                  // this is the class contructor
    this->vertex = vertex;         // initialize how many vertex there will be
    this->edge = 0;                // at first, the graph doesn't have any edge. you may use addEdge
    this->isDirected = isDirected; // to determine the graph is directed or not (directed graph is under development, may unstable)
    this->hasCircle = false;
    for (long i = 0; i < vertex; i++)
    {
        adjList.push_back({}); // adding the vertex into the adjacency list
    }
}

void unweighted_graph::addEdge(long vertex1, long vertex2)
{ // a function to add aditional edge
    if (find(adjList[vertex1].begin(), adjList[vertex1].end(), vertex2) != adjList[vertex1].end())
        return;                          // just to make sure the edge is not present already
    adjList[vertex1].push_back(vertex2); // adding the edge
    if (!isDirected)
        adjList[vertex2].push_back(vertex1); // adding additional edge if the graph is undirected
    edge++;
}

long unweighted_graph::vertexCount()
{                  // a function that tells you how many vertex(s) inside this graph
    return vertex; // may come handy when debugging
}

long unweighted_graph::edgeCount()
{                // a function that tells you how many edge(s) inside this graph
    return edge; // also may come handy when debugging
}

void unweighted_graph::dfs(long vertex, vector<long> &v)
{ // function call for dfs transversal
    // you need a vertex as a starting point and a vector passed into the function
    // the vector will store transversal result
    vector<bool> visited(this->vertex, false); // a vector that marks all visited vertex
    v.clear();
    depth_first_search(vertex, visited, v);
}

void unweighted_graph::depth_first_search(long vertex, vector<bool> &visited, vector<long> &v)
{ // utility function for dfs transversal
    visited[vertex] = true;

    v.push_back(vertex);

    for (auto it : adjList[vertex])
    {
        if (!visited[it])
            depth_first_search(it, visited, v);
    }
}

void unweighted_graph::bfs(long vertex, vector<long> &v)
{ // function call for bfs transversal
    // you need a vertex as a starting point and a vector passed into the function
    // the vector will store transversal result
    vector<bool> visited(this->vertex, false); // a vector that marks all visited vertex
    v.clear();
    breadth_first_search(vertex, visited, v);
}

void unweighted_graph::breadth_first_search(long vertex, vector<bool> &visited, vector<long> &v)
{ // utility function for bfs transversal
    queue<long> q;
    q.push(vertex);
    visited[vertex] = true;

    v.push_back(vertex);

    while (!q.empty())
    {
        long temp = q.front();
        q.pop();
        for (auto it : adjList[temp])
            if (!visited[it])
            {
                q.push(it);
                visited[it] = true;
                v.push_back(it);
            }
    }
}

bool unweighted_graph::linearCheck()
{ // basically a function to check if the graph is linear or not
    for (auto it : adjList)
    {
        if (!(it.size() <= 2 && it.size() > 0))
            return false;
    }
    return true;
}

bool unweighted_graph::circleSearch()
{ // similar to linearCheck but to search a cycle in the graph
    vector<bool> visited(this->vertex, false);
    circleCheck(-1, 0, visited);

    return hasCircle;
}

void unweighted_graph::circleCheck(long parent, long vertex, vector<bool> &visited)
{ // utility function for circleSearch
    visited[vertex] = true;

    for (auto it : adjList[vertex])
    {
        if (!visited[it])
            circleCheck(vertex, it, visited);
        else if (visited[it] && it != parent)
        {
            hasCircle = true;
            return;
        }
    }
}

int main()
{
    int t, v, e, e1, e2;
    cin >> t;

    while (t--)
    {
        cin >> v >> e;
        unweighted_graph g(v, false);
        for (int i = 0; i < e; i++)
        {
            cin >> e1 >> e2;
            g.addEdge(--e1, --e2);
        }
        cout << "Graf ini adalah ";
        if (g.linearCheck())
            cout << "linked list"
                 << "\n";
        else if (!g.circleSearch())
            cout << "tree"
                 << "\n";
        else
            cout << "graf biasa"
                 << "\n";
    }

    return 0;
}