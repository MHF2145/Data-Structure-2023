#include <iostream>
#include <queue>
#include <vector>

using namespace std;


void Display(int color[], int V) {
    cout << "Solution Exists\nThe colors given to vertices are:" << endl;
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i + 1 << " is given color: " << color[i] << endl;
    cout << endl;
}

// Function to check constraints
bool satisfyConstraints(vector<vector<int>>& adjList, int color[], int V) {
    for (int i = 0; i < V; i++) {
        if (!adjList.empty()) {
        for (int j : adjList[i]) {
            if (color[j] == color[i])
                return false;
        }
        }
    }
    return true;
}

// Function for m-coloring problem
bool m_Coloring(vector<vector<int>>& adjList, int m, int i, int color[], int V) {
    // If current index reached the end
    if (i == V) {
        // If constraints are satisfied
        if (satisfyConstraints(adjList, color, V)) {
            cout << "Tidak ada yang aneh, kak!" << endl;
            return true;
        }
        return false;
    }

    // Assign each color from 1 to m
    for (int j = 1; j <= m; j++) {
        color[i] = j;
        // Recursively color the rest of the vertices
        if (m_Coloring(adjList, m, i + 1, color, V))
            return true;
        color[i] = 0;
    }

    return false;
}

int main()
{

    cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);


    int testCase;
    cin >> testCase;

    int y,z;
    int a,b;

    for (int i=0; i<testCase; i++) {

        cin >> y >> z;

        vector<vector<int>> adjList(y);


        while (z--)
        {   
            cin >> a >> b;
            
            if (a > adjList.size()) {
                adjList.resize(a);
            }

            
            adjList[a-1].push_back(b-1);
        }

        cout << "Penelitian #" << i+1 << ":" << endl;

        int color[adjList.size()]={0};
        int m = 2;

        if (!m_Coloring(adjList, m, 0, color,adjList.size())) {
            cout << "Kak, aku menemukan ketidaksesuaian dengan hipotesis!" << endl;
        } 
    
        cout << endl;


    }


	return 0;
}
