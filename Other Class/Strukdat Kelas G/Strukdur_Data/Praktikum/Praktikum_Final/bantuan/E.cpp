#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

struct Hubung {
    int ke;
    int bahaya;

    Hubung(int destination, int dangerLevel) {
        ke = destination;
        bahaya = dangerLevel;
    }
};

int mencariMax(vector<vector<Hubung> >& graph, int source, int destination) {
    int n = graph.size();

    vector<int> dangerLevel(n, INF); 
    dangerLevel[source] = 0; 

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDanger = pq.top().first;
        pq.pop();

        if (current == destination)
            break;

        for (Hubung road : graph[current]) {
            int next = road.ke;
            int danger = max(currentDanger, road.bahaya);

            if (danger < dangerLevel[next]) {
                dangerLevel[next] = danger;
                pq.push({danger, next});
            }
        }
    }

    return dangerLevel[destination];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Hubung> > graph(n + 1);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(Hubung(b, c));
        graph[b].push_back(Hubung(a, c));
    }

    int source = 1;
    int destination = n;

    int maxDanger = mencariMax(graph, source, destination);
    cout << maxDanger << endl;

    return 0;
}
