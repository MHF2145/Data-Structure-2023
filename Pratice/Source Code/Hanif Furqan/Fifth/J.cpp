// Bismillah ngga WA lagi
#include <bits/stdc++.h>
#define MODX 1000000009LL

long long dikali(long long a, long long b);
long long dipangkat(long long a, long long b);

int main() {
    unsigned long long m, n;

    std::cin >> m;
    for (unsigned long long i = 0; i < m; i++) {
        std::cin >> n;
        unsigned long long powVal = (n * (n - 1)) / 2;
        long long res = dipangkat(2, powVal);
        std::cout << "Zodiak found: " << res << " signs" << std::endl;
    }

    return 0;
}


long long dikali(long long a, long long b)
{
    return ((a % MODX) * (b % MODX)) % MODX;
}

long long dipangkat(long long a, long long b)
{
    if (b == 0)
        return 1;

    long long stngh = dipangkat(a, b / 2);
    long long hsl = dikali(stngh, stngh);

    if (b % 2 == 1)
        hsl = dikali(hsl, a);

    return hsl;
}