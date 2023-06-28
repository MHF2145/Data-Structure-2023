#include <bits/stdc++.h>
using namespace std;


void baca_tepi(vector<int> &ttnga);
void findttngaMinMax(const vector<int> &ttnga, int N, int &minNode, int &maxNode);
void printing(int minNode, int maxNode);

int main()
{
    int N;
    cin >> N;


    vector<int> ttnga(N + 1, 0);

    baca_tepi(ttnga);

    int minNode = -1;
    int maxNode = -1;

    findttngaMinMax(ttnga, N, minNode, maxNode);


    printing(minNode, maxNode);

    return 0;
}

void baca_tepi(vector<int> &ttnga)
{
    int a, b;

    while (cin >> a >> b)
    {
        if (a == -1 && b == -1)
        {
            break;
        }
        ttnga[a]++;
        ttnga[b]++;
    }
}

void findttngaMinMax(const vector<int> &ttnga, int N, int &minNode, int &maxNode)
{
    int minttnga = INT_MAX;
    int maxttnga = INT_MIN;


    for (int i = 1; i <= N; i++)
    {
        if (ttnga[i] < minttnga || (ttnga[i] == minttnga && i > minNode))
        {
            minttnga = ttnga[i];
            minNode = i;
        }
        if (ttnga[i] > maxttnga || (ttnga[i] == maxttnga && i < maxNode))
        {
            maxttnga = ttnga[i];
            maxNode = i;
        }
    }
}

void printing(int minNode, int maxNode)
{
    cout << minNode << " Targetnya" << endl;
    cout << maxNode << " Paling Bahaya" << endl;
}
