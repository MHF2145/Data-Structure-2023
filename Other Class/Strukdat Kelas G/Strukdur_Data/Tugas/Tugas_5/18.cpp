#include <iostream>
using namespace std;

int hasil(int m, int n)
{
    // Buat array 2 dimensi
    int grid[m + 1][n + 1];

    // Inisiasi
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                grid[i][j] = 1;
            else
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
        }
    }

    // Hasilnya
    return grid[m][n];
}

int main()
{
    int m, n;
    cout << "input koordinat (m n): ";
    cin >> m >> n;

    int paths = hasil(m, n);
    cout << "Jumlah path: " << paths << std::endl;

    return 0;
}
