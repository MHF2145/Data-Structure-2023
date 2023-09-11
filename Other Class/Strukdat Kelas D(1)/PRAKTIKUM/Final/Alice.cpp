#include <bits/stdc++.h>
using namespace std;

map<int, int> rem[11];
int countPairs(vector<int> a, int n, int k)
{
    vector<int> len(n);
    vector<int> p(11);
    p[0] = 1;
    for (int i = 1; i <= 10; i++)
    {
        p[i] = (p[i - 1] * 10) % k;
    }

    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        while (x > 0)
        {
            len[i]++;
            x /= 10;
        }
        rem[len[i]][a[i] % k]++;
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = 1; j <= 10; j++)
        {
            int r = (a[i] * p[j]) % k;
            int xr = (k - r) % k;
            ans += rem[j][xr];
            if (len[i] == j && (r + a[i] % k) % k == 0)
                ans--;
        }
    }

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << countPairs(a, n, k);
}
