#include <iostream>

int main()
{
    int n;
    std::cout << "Masukkan sebuah bilangan bulat positif: ";
    std::cin >> n;

    unsigned long long faktorial = 1;   //menghindari overflow
    for (int i = 1; i <= n; ++i)
    {
        faktorial *= i;
    }

    std::cout << "Faktorial dari " << n << " adalah " << faktorial << std::endl;
    return 0;
}
