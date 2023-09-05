#include <iostream>
#include <queue>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    priority_queue<int> inp;
    while (n--)
    {
        int p;
        cin >> p;
        if (p == 1)
        {
            int x;
            cin >> x;
            inp.push(x);
        }
        else if (p == 2)
        {
            cout << inp.top() << endl;
        }
        else
        {
            inp.pop();
        }
    }
    return 0;
}