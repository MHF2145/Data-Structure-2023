#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct UnionFind
{
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n);
    int find(int x);
    void unite(int x, int y);
};

UnionFind::UnionFind(int n)
{
    parent.resize(n);
    rank.resize(n, 0);

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
}

int UnionFind::find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void UnionFind::unite(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY)
    {
        if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int c;
    cin >> c;

    UnionFind uf(n);
    unordered_map<int, int> groups;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int xorResult = nums[i] ^ nums[j];
            if (xorResult % c == 0)
            {
                uf.unite(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int root = uf.find(i);
        groups[root] = 1;
    }

    int groupCount = groups.size();
    cout << groupCount << endl;

    return 0;
}
