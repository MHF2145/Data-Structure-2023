#include <bits/stdc++.h>

int main()
{
    int t;
    std::cin >> t;

    for (int testcase = 0; testcase < t; testcase++)
    {
        int n;
        std::cin >> n;
        std::unordered_map<int, int> freq;
        int leftover = 0;

        for (int i = 0; i < n; i++)
        {
            int a;
            std::cin >> a;
            freq[a]++;
        }

        int maxFreq = 0;
        int size = freq.size();

        for (auto it = freq.begin(); it != freq.end(); ++it)
        {
            maxFreq = std::max(maxFreq, it->second);
        }

        leftover = (maxFreq <= n / 2 && size != 2 && size != 1) ? ((n % 2 == 0) ? 0 : 1) : (maxFreq - (n - maxFreq));

        std::cout << leftover << std::endl;
    }

    return 0;
}
