#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        unordered_map<int, int> freq;
        int sisa = 0;
        int maxFreq = 1;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            freq[a]++;
            if (freq[a] > maxFreq)
            {
                maxFreq = freq[a];
            }
        }
        int size = freq.size();
        // cout << "==>" << size << endl;

        if (maxFreq <= n / 2 && size != 2 && size != 1)
        {
            if (n % 2 == 0)
                sisa = 0;
            else
                sisa = 1;
        }
        else
            sisa = maxFreq + (maxFreq - n);
        cout << sisa << endl;
    }
    return 0;
}