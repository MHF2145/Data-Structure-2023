#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kx[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

int main()
{
    int a, b;
    cin >> a >> b;

    queue<pair<pair<int, int>, int>> simpan;

    vector<vector<int>> isi(a, vector<int>(a, 1000000000));

    for (int i = 0; i < b; i++)
    {
        int c, d;

        cin >> c >> d;

        simpan.push({{--d, --c}, 1});

        isi[d][c] = 1;
    }

    while (simpan.size())
    {
        pair<pair<int, int>, int> curr = simpan.front();
        simpan.pop();
        int c = curr.first.first;
        int r = curr.first.second;
        int d = curr.second;
        for (int i = 0; i < 4; i++)
        {
            int nr = r + kx[i];
            int nc = c + dc[i];
            if (0 <= nr && nr < a && 0 <= nc && nc < a)
            {
                if (d + 1 < isi[nc][nr])
                {
                    isi[nc][nr] = d + 1;
                    if (d + 1 < 4)
                    {
                        simpan.push({{nc, nr}, d + 1});
                    }
                }
            }
        }
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (isi[i][j] == 1000000000)
            {
                cout << 0;
            }
            else
            {
                cout << isi[i][j];
            }

            if (j == a - 1)
            {
                cout << "\n";
            }
            else
            {
                cout << " ";
            }
        }
    }
}
