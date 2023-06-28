#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function prototypes
void readInputEdges(vector<int>& neighbors);
void findMinMaxNeighbors(const vector<int>& neighbors, int N, int& minNode, int& maxNode);
void printResults(int minNode, int maxNode);

int main() {
    int N;
    cin >> N;

    // Create a vector to store the number of neighbors for each node
    vector<int> neighbors(N + 1, 0);

    readInputEdges(neighbors);

    int minNode = -1;
    int maxNode = -1;

    findMinMaxNeighbors(neighbors, N, minNode, maxNode);

    // Print the results
    printResults(minNode, maxNode);

    return 0;
}

void readInputEdges(vector<int>& neighbors) {
    int a, b;
    // Read the input edges and update the neighbor count for each node
    while (cin >> a >> b) {
        if (a == -1 && b == -1) {
            break;
        }
        neighbors[a]++;  // Increment the neighbor count for node a
        neighbors[b]++;  // Increment the neighbor count for node b
    }
}

void findMinMaxNeighbors(const vector<int>& neighbors, int N, int& minNode, int& maxNode) {
    int minNeighbors = INT_MAX;
    int maxNeighbors = INT_MIN;

    // Find the node with the fewest and most neighbors
    for (int i = 1; i <= N; i++) {
        if (neighbors[i] < minNeighbors || (neighbors[i] == minNeighbors && i > minNode)) {
            minNeighbors = neighbors[i];  // Update the minimum number of neighbors
            minNode = i;  // Update the node with the fewest neighbors
        }
        if (neighbors[i] > maxNeighbors || (neighbors[i] == maxNeighbors && i < maxNode)) {
            maxNeighbors = neighbors[i];  // Update the maximum number of neighbors
            maxNode = i;  // Update the node with the most neighbors
        }
    }
}

void printResults(int minNode, int maxNode) {
    cout << minNode << " Targetnya" << endl;  // Print the node with the fewest neighbors
    cout << maxNode << " Paling Bahaya" << endl;  // Print the node with the most neighbors
}
