#include <iostream>
#include <math.h>

#define MODX 1000000009LL

long long power(long long a, long long b)
{
    long long res = 1;
    // a %= MODX;

    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % MODX;
        }
        b >>= 1;
        a = (a * a) % MODX;
        // std:cout << res << std::endl;
    }

    return res % MODX;
}

int main()
{
    unsigned long long m, n;

    std::cin >> m;
    // int res = 0;
    while (m--)
    {
        std::cin >> n;
        unsigned long long powVal = (n * (n - 1)) / 2;
        // std:cout << powVal << std::endl;
        long long res = power(2, powVal) % MODX;
        std::cout << "Zodiak found: " << res << " signs" << std::endl;
    }

    return 0;
}