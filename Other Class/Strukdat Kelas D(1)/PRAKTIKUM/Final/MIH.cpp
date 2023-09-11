#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        unordered_map<int, int> count;
        stack<int> prices;

        for (int i = 0; i < n; i++)
        {
            int p;
            cin >> p;
            prices.push(p);
            count[p]++;
        }

        int max_count = 0;
        while (!prices.empty())
        {
            int price = prices.top();
            max_count = max(max_count, count[price]);
            prices.pop();
        }

        int sisa = 0;
        int sizecount = count.size();

        if (sizecount == 1)
        {
            sisa = n;
        }
        else if (sizecount == 2)
        {
            auto it = count.begin();
            int count1 = it->second;
            it++;
            int count2 = it->second;
            sisa = abs(count1 - count2);
        }
        else
        {
            if (max_count <= n / 2)
            {
                sisa = n % 2;
            }
            else
            {
                sisa = max_count - (n - max_count);
            }
        }

        cout << sisa << '\n';
    }

    return 0;
}
