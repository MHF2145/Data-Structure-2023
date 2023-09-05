#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main()
{
    int a, b;
    vector<int> c(a);
    cin >> a >> b;

    for (int i = 0; i < a; i++)
    {
        cin >> c[i];
    }

    int ans = 0;
    for (int j = 0; j < a; j++)
    {
        for (int k = 0; k < a; k++)
        {
            if (j != k)
            {
                ull minum = stoll(to_string(c[j]) + to_string(c[k]));
                if (minum % b == 0)
                {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
