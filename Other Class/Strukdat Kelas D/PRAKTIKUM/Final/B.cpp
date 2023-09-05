#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;

struct Circle {
    int x, y, r;
};

struct Edge {
    int u, v;
    double weight;
};

struct CompareEdges {
    bool operator()(const Edge& e1, const Edge& e2) {
        return e1.weight > e2.weight;
    }
};

double calculateDistance(int x1, int y1, int x2, int y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int findParent(int node, vector<int>& parent) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node], parent);
}

void unionSets(int u, int v, vector<int>& parent) {
    int parentU = findParent(u, parent);
    int parentV = findParent(v, parent);
    parent[parentV] = parentU;
}

double calculateMinimumRubberLength(int N, vector<Circle>& circles) {
    vector<int> parent(N);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    priority_queue<Edge, vector<Edge>, CompareEdges> pq;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double distance = calculateDistance(circles[i].x, circles[i].y, circles[j].x, circles[j].y);
            distance -= circles[i].r + circles[j].r;
            pq.push({i, j, distance});
        }
    }

    double minRubberLength = 0.0;
    while (!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();

        int parentU = findParent(edge.u, parent);
        int parentV = findParent(edge.v, parent);

        if (parentU != parentV) {
            minRubberLength += edge.weight;
            unionSets(parentU, parentV, parent);
        }
    }

    return minRubberLength;
}

int main() {
    int N;
    while (cin >> N && N != -1) {
        vector<Circle> circles(N);
        for (int i = 0; i < N; i++) {
            cin >> circles[i].x >> circles[i].y >> circles[i].r;
        }

        double minRubberLength = calculateMinimumRubberLength(N, circles);
        cout << fixed << setprecision(3) << minRubberLength << "\n";
    }

    return 0;
}
