#include <iostream>

using namespace std;

int main()
{
    int m, n, ans;
    cin >> m >> n;
    int inp, first = 0, second = 0;

    while (m--)
    {
        cin >> inp;
        if (!first)
        {
            first += inp;
        }
        else
        {
            first = (first*10) + inp;
        }
        
        
    }
    // cout << endl << first << endl;

    while (n--)
    {
        cin >> inp;
        if (!second)
        {
            second += inp;
        }
        else
        {
            second = (second*10) + inp;
        }
    }
    // cout << second << endl;

    ans = first + second;
    cout << ans << endl;

    return 0;
}