#include <iostream>
#include <vector>
#include <map>

using namespace std;

void insertEdge(map<string, vector<pair<string, int>>> myGraph, int u, int v)
{
    return;
}

int main()
{
    map<string, vector<pair<string, int>>> myGraph;
    int n;
    cin >> n;
    string city_name[n];

    // vertices input
    for (int i = 0; i < n; i++)
    {
        cin >> city_name[i];
    }

    // edges and weights input
    for (int i = 0; i < n; i++)
    {
        int neighbor;
        cin >> neighbor;
        vector<pair<string, int>> myVect;
        for (int j = 0; j < neighbor; j++)
        {
            string kota;
            int weight;
            cin >> kota;
            cin >> weight;
            myVect.push_back(make_pair(kota, weight));
        }
        myGraph.insert(make_pair(city_name[i], myVect));
    }

    map<string, vector<pair<string, int>>>::iterator it;

    string target;
    cin >> target;
    if (myGraph.count(target))
    {
        if (myGraph[target].size() == 0)
            cout << "TIDAK TERSEDIA" << endl;
        else
        {
            for (int i = 0; i < myGraph[target].size(); i++)
                cout << "(" << myGraph[target][i].first << ", " << myGraph[target][i].second << ") ";
            cout << endl;
        }
    }
    else
        cout << "TIDAK TERSEDIA" << endl;

    return 0;
}