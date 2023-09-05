#include <iostream>

const long long MOD = 1e9+9;

long long modularExponentiation(long long base, long long exponent, long long mod) {
    long long result = 1;
    
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    
    return result;
}

long long countZodiacSigns(long long n) {
    long long exponent = (n * (n - 1)) / 2;
    return static_cast<long long>(modularExponentiation(2, exponent, MOD));
}

int main() {
    long long m;
    std::cin >> m;
    
    for (long long i = 0; i < m; i++) {
        long long n;
        std::cin >> n;
        
        long long zodiacSigns = countZodiacSigns(n);
        
        std::cout << "Zodiak found: " << zodiacSigns << " signs" << std::endl;
    }
    
    return 0;
}
