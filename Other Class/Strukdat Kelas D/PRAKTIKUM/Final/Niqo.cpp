#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int destination;
    int weight;
};

struct Vertex {
    string name;
    int price;
};

struct Graph {
    vector<vector<Edge>> adjacencyList;
    vector<Vertex> vertices;
};

void dijkstra(const Graph& graph, int start, int maxDistance) {
    int numVertices = graph.adjacencyList.size();

    vector<int> distance(numVertices, numeric_limits<int>::max());
    vector<bool> visited(numVertices, false);

    distance[start] = 0;

    auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
    pq.push(make_pair(start, 0));

    while (!pq.empty()) {
        int current = pq.top().first;
        pq.pop();

        if (visited[current]) {
            continue;
        }

        visited[current] = true;

        for (const Edge& edge : graph.adjacencyList[current]) {
            int next = edge.destination;
            int weight = edge.weight;

            if (!visited[next] && distance[current] + weight < distance[next]) {
                distance[next] = distance[current] + weight;
                pq.push(make_pair(next, distance[next]));
            }
        }
    }

    int minPrice = numeric_limits<int>::max();
    int bestRestaurant = -1;

    for (int i = 1; i < numVertices; i++) {
        if (distance[i] <= maxDistance && graph.vertices[i].price < minPrice) {
            minPrice = graph.vertices[i].price;
            bestRestaurant = i;
        }
    }

    if (bestRestaurant != -1) {
        cout << "hari ini makan di " << graph.vertices[bestRestaurant].name << endl;
    }
}

int main() {
    int restaurant;
    cin >> restaurant;

    Graph graph;
    graph.adjacencyList.resize(restaurant + 1);
    graph.vertices.resize(restaurant + 1);

    for (int i = 1; i <= restaurant; i++) {
        cin >> graph.vertices[i].name >> graph.vertices[i].price;
    }

    int numEdges;
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph.adjacencyList[source].push_back({destination, weight});
        graph.adjacencyList[destination].push_back({source, weight});
    }

    int maxDistance;
    cin >> maxDistance;

    dijkstra(graph, 0, maxDistance);

    return 0;
}
