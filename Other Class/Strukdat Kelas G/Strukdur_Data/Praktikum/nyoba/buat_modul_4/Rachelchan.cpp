#include <vector>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int cycle(vector<int> graf[], int n)
{
    int temp = INT_MAX;

    for (int i = 0; i < n; i++)
    {

        vector<int> dist;
        vector<int> par;

        dist.assign(n, INT_MAX);
        par.assign(n, -1);

        dist.at(i) = 0;

        queue<int> queue;
        queue.push(i);

        while (!queue.empty())
        {
            int nilai_depan = queue.front();

            queue.pop();

            for (auto nilai : graf[nilai_depan])
            {
                bool benar = dist[nilai] == INT_MAX;
                if (benar)
                {
                    dist[nilai] = 1 + dist[nilai_depan];
                    par[nilai] = nilai_depan;
                    queue.push(nilai);
                }
                else if (par[nilai_depan] != nilai && par[nilai] != nilai_depan)
                    temp = min(temp, dist[nilai_depan] + dist[nilai] + 1);
            }
        }
    }

    return (temp != INT_MAX) ? temp : 0;
}

void add(vector<int> graf[], int x, int y)
{
    graf[x].push_back(y);
    graf[y].push_back(x);
}

int main()
{
    int tempat, jalan, A, B;
    cin >> tempat >> jalan;
    vector<int> graf[tempat];
    for (int i = 0; i < jalan; i++)
    {
        cin >> A >> B;
        add(graf, A, B);
    }

    int hasil = cycle(graf, tempat);

    if (hasil)
        cout << hasil;
    else
        cout << "gamau gasuka gelay" << endl;

    return 0;
}