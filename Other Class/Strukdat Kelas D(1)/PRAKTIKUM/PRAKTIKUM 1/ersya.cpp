#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, n;
    cin >> x >> y >> n;

    deque<int> animeList;
    for (int i = 0; i < x; i++)
    {
        int num;
        cin >> num;
        animeList.push_back(num);
    }

    if (x <= n)
    {
        cout << "Kasian Ersya\n";
        return 0;
    }

    int i = 0;
    while (i<n)
    {
        animeList.pop_front();
        int m = y;
        if (!animeList.empty() && y >= animeList.size())
        {
            m %= animeList.size();
        }
        for (int i = 0; i < m; i++)
        {
            int front = animeList.front();
            animeList.push_back(front);
            animeList.pop_front();
        }
        i++;
    }
    cout << animeList.front() << endl;
    return 0;
}
