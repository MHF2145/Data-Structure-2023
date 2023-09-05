#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    int treasureMap[200][200] = {0};
    cin >> n >> t;

    while (t--)
    {
        int x, y;
        cin >> x >> y;
        treasureMap[x][y] = 1;
        for (int j = 1; j <= 3; j++)
        {
            for (int i = 0; i <= j; i++)
            {
                if (treasureMap[x - j + i][y - i] == 0)
                    treasureMap[x - j + i][y - i] = j + 1;
                else
                    treasureMap[x - j + i][y - i] = min(treasureMap[x - j + i][y - i], j + 1);
                if (treasureMap[x - j + i][y + i] == 0)
                    treasureMap[x - j + i][y + i] = j + 1;
                else
                    treasureMap[x - j + i][y + i] = min(treasureMap[x - j + i][y + i], j + 1);
            }

            for (int i = j; i >= 0; i--)
            {
                if (treasureMap[x + j - i][y - i] == 0)
                    treasureMap[x + j - i][y - i] = j + 1;
                else
                    treasureMap[x + j - i][y - i] = min(treasureMap[x + j - i][y - i], j + 1);
                if (treasureMap[x + j - i][y + i] == 0)
                    treasureMap[x + j - i][y + i] = j + 1;
                else
                    treasureMap[x + j - i][y + i] = min(treasureMap[x + j - i][y + i], j + 1);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << treasureMap[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}