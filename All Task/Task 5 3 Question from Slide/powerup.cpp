#include <iostream>
#include <cmath>


int main() {
    double bil, up;
    std::cout << "Masukkan Angka: ";
    std::cin >> bil;
    std::cout << "Masukkan Pangkat: ";
    std::cin >> up;

    double hasil = pow(bil, up);
    std::cout << bil << " dipangkatkan dengan " << up << " adalah " << hasil << std::endl;

    return 0;
}
