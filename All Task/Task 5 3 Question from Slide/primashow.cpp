#include <iostream>

bool prime(int num)     //mengecek apakah bilangan prima
{
    if (num < 2)
    {
        return false;
    }
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int a, b;
    std::cout << "Masukkan rentang bilangan (A dan B): ";
    std::cin >> a >> b;

    std::cout << "Bilangan prima dalam rentang " << a << " hingga " << b << " adalah: ";
    for (int i = a; i <= b; i++)        //menggunakan a sebagai patokan i yang nanti akan dicek prima atau tidak hingga b, dan jika prima maka akan di print
    {
        if (prime(i))
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
