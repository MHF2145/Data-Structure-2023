
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
#define ull unsigned long long
using namespace std;

ull x(ull i, ull j)
{
    if ((i + j) % 3ull == 1ull)
        return (2 * (i + j) + 1ull) / 3ull * (i + j) * (i + j + 1ull);
    else if ((i + j) % 3ull == 2ull)
        return (i + j + 1ull) / 3ull * (i + j) * (2 * (i + j) + 1ull);
    else
        return (i + j) / 3ull * (i + j + 1ull) * (2 * (i + j) + 1ull);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ull i, j, k, res;
        cin >> k;
        i = 0ull;
        j = 1ull;
        while (x(i, j) <= 1e18)
        {
            // x = i*(i+1ull)*(2*i+1ull)/3ull;
            if (k <= x(i, j))
            {
                res = i + j;
                break;
            }
            if (k <= x(i, 2 * j))
            {
                i += j;
                j = 1ull;
            }
            else
            {
                j *= 2ull;
            }
        }
        cout << res << endl;
    }
    return 0;
}
