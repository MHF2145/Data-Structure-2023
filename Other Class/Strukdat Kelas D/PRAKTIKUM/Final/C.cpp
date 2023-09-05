#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            int p;
            cin >> p;
            freq[p]++;
        }

        int max_freq = 0;
        for (auto &f : freq)
        {
            max_freq = max(max_freq, f.second);
        }

        int leftover = 0;
        if (freq.size() == 1)
        {
            leftover = n; // If there is only one frequency, all elements are leftover.
        }
        else if (freq.size() == 2)
        {
            // If there are two frequencies, the difference between the two frequencies gives the number of leftover elements.
            auto it = freq.begin();
            int freq1 = it->second;
            it++;
            int freq2 = it->second;
            leftover = abs(freq1 - freq2);
        }
        else
        {
            if (max_freq <= n / 2)
            {
                leftover = n % 2; // If the maximum frequency is less than or equal to half of the total elements, the leftover is the remainder after dividing by 2.
            }
            else
            {
                leftover = max_freq - (n - max_freq); // Otherwise, the leftover is the difference between the maximum frequency and the number of non-maximum frequencies.
            }
        }

        cout << leftover << '\n';
    }

    return 0;
}

