#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ull t, n;
    map<ull, ull> mp;
    cin >> t;
    mp[1ull] = 1ull;
    while (t--)
    {
        cin >> n;
        if (mp.find(n) == mp.end())
        {
            auto ptr = mp.end();
            ptr--;
            while (ptr->first < n)
            {
                ull curr = ptr->first;
                ull next = ptr->first + 1ull;
                // rumus: catalan[n] = catalan[n-1] * 2(2n-1) / (n+1)
                ull pembilang = 4ull * next - 2ull, penyebut = next + 1ull, fpb = gcd(pembilang, penyebut);
                pembilang /= fpb;
                penyebut /= fpb;
                mp[next] = mp[curr] / penyebut * pembilang;
                ptr++;
            }
        }
        cout << mp[n] << endl;
    }
    return 0;
}