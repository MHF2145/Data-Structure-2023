#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main()
{
    int test, inp;
    cin >> test;
    while (test--)
    {
        cin >> inp;

        priority_queue<pair<int, int>> urut;
        map<int, int> uji;

        while (inp--)
        {
            int angka;
            cin >> angka;

            auto pointer = uji.find(angka);
            if (pointer != uji.end())
            {
                pointer->second++;
            }
            else
            {
                uji.insert(make_pair(angka, 1));
            }
        }

        for (auto j = uji.begin(); j != uji.end(); j++)
        {
            urut.push(make_pair(j->second, j->first));
        }

        while (1)
        {
            int a1, b1, a2, b2;
            if (urut.size() <= 1)
            {
                if (urut.size() == 0)
                {
                    cout << "0" << endl;
                }
                else
                {
                    cout << urut.top().first << endl;
                }
                break;
            }

            a1 = urut.top().first, b1 = urut.top().second;
            a1--;
            urut.pop();

            a2 = urut.top().first, b2 = urut.top().second;
            a2--;
            urut.pop();

            if (a1 != 0)
            {
                urut.push(make_pair(a1, b1));
            }

            if (a2 != 0)
            {
                urut.push(make_pair(a2, b2));
            }
        }
    }
    return 0;
}