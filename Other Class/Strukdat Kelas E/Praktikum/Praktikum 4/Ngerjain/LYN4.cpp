/*
6
X1 <-> Y1
Y1 <-> Z1
Z1 <-> Z2
Z2 <-> Y2
Y2 <-> X2
Z3 <-> Z2
*/

#include <iostream>
#include <vector>

using namespace std;

int count_unconnected_stars(int N, const vector<string>& relations) {
    vector<vector<bool>> matrix(9, vector<bool>(9, false));

    for (const string& relation : relations) {
        int a = relation[0] - 'X';
        int b = relation[5] - 'X';
        matrix[a][b] = true;
        matrix[b][a] = true;
    }

    vector<bool> visited(9, false);
    int unconnected = 0;

    for (int i = 0; i < 9; i++) {
        if (!visited[i]) {
            vector<int> stack;
            stack.push_back(i);

            while (!stack.empty()) {
                int node = stack.back();
                stack.pop_back();
                visited[node] = true;

                for (int j = 0; j < 9; j++) {
                    if (matrix[node][j] && !visited[j]) {
                        stack.push_back(j);
                    }
                }
            }

            unconnected++;
        }
    }

    return unconnected;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    vector<string> relations;
    for (int i = 0; i < N; i++) {
        string relation;
        getline(cin, relation);
        relations.push_back(relation);
    }

    int result = count_unconnected_stars(N, relations);
    cout << "Stars: " << result << " not connected" << endl;

    return 0;
}
