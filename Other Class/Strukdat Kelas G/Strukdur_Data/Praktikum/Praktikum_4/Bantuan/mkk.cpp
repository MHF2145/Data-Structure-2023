#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void Display(int color[], int V)
{
    cout << "Solution Exists\nThe colors given to vertices are:" << endl;
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i + 1 << " is given color: " << color[i] << endl;
    cout << endl;
}

// Function to check constraints
bool satisfyConstraints(vector<vector<int>> &adjList, int color[], int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int j : adjList[i])
        {
            if (color[j] == color[i])
                return false;
        }
    }
    return true;
}

// Function for m-coloring problem
bool m_Coloring(vector<vector<int>> &adjList, int m, int i, int color[], int V)
{
    // If current index reached the end
    if (i == V)
    {
        // If constraints are satisfied
        if (satisfyConstraints(adjList, color, V))
        {
            Display(color, V);
            cout << "YES!" << endl;
            return true;
        }
        return false;
    }

    // Assign each color from 1 to m
    for (int j = 1; j <= m; j++)
    {
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
    map<char, int> map;

    int start = 65;

    for (int i = 0; i < 26; i++)
    {
        map[char(start)] = i;
        start++;
    }

    int number, m;

    cin >> number >> m;

    vector<vector<int>> adjList(number);
    cin.ignore(); // Add this line to clear the newline character

    for (int i = 0; i < number; i++)
    {
        string str;

        getline(cin, str);

        int before_arrow;
        vector<int> after;

        before_arrow = map[str[0]];
        auto index = str.find('>');

        for (auto i = index + 1; i < str.size(); i++)
        {
            if (str[i] != ' ' && str[i] != ',')
            {
                after.push_back(map[str[i]]);
            }
        }

        cout << before_arrow << endl;
        if (after.size() != 0)
        {
            for (auto c : after)
            {
                cout << c << " ";
                adjList[before_arrow].push_back(c);
            }
            cout << endl;
        }
    }

    int color[number] = {0};

    if (!m_Coloring(adjList, m, 0, color, number))
        cout << "NO!" << endl;

    return 0;
}
