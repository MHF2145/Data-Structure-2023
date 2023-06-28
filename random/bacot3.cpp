#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> bt;

    while (n--)
    {
        int t;
        cin >> t;
        bt.push_back(t);
    }

    int sum;
    cin >> sum;

    sort(bt.begin(), bt.end());
    queue<int> smntr;
    int calc = 0;
    int status = 0;
    for (int i = 0; i < bt.size(); i++)
    {
        if (smntr.size() == 3)
        {
            calc -= smntr.front();
            smntr.pop();
        }

        smntr.push(bt[i]);
        calc += smntr.back();

        if (calc == sum)
        {
            status = 1;
            break;
        }
    }

    if (status == 1)
    {
        cout << "Monggo Lewat...";
    }
    else
    {
        cout << "Wani Piro?";
    }
    return 0;
}