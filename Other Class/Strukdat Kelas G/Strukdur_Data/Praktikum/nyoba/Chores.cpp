#include <iostream>
#include <list>
using namespace std;

int main()
{
    int e, n;
    cin >> e >> n;
    list<pair<int, string>> data;
    for (int i = 0; i < n; i++)
    {
        int pr;
        string nama;
        cin >> pr >> nama;
        data.push_back(make_pair(pr, nama));
    }

    data.sort();
    for (int i = 0; i < n; i++)
    {
        pair<int, string> temp = data.front();
        if (temp.first <= e && e >= 0)
        {
            e -= temp.first;
            data.pop_front();
            cout << temp.second << endl;
        }
        else break;
    }

    if (data.size() == n)
    {
        puts("Pak Aya will do the rest");
    }
}
