#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <iomanip>
using namespace std;

int main()
{
    int T, tc, inp;
    deque<int> genta;
    cin >> T;

    while (T--)
    {
        cin >> tc;
        int temp = 0;
        float temp2 = 0;
        for (int i = 0; i < tc; i++)
        {
            cin >> inp;
            temp2 += (float)inp;
            genta.push_front(inp);
        }

        temp2 /= tc;
        temp = temp2;
        sort(genta.rbegin(), genta.rend());
        // cout << temp2 << " " << temp << endl;

        int ihsan = 0;
        if (temp2 - (float)temp != 0)
        {
            cout << -1 << endl;
        }
        else if (genta.back() == genta.front())
        {
            cout << 0 << endl;
        }
        else
        {
            while (1)
            {
                sort(genta.rbegin(), genta.rend());

                if (genta.back() == genta.front())
                {
                    break;
                }

                int malvin;
                malvin = (genta.front() - genta.back()) / 2;

                int max = genta.front() - malvin, min = genta.back() + malvin;
                genta.pop_front();
                genta.pop_back();
                genta.push_front(max);
                genta.push_back(min);
                ihsan++;
            }

            cout << ihsan << endl;
        }
        genta.clear();
    }
    return 0;
}