#include <iostream>
#include <vector>
using namespace std;

void printSolution(int color[], int a)
{
    cout << "Solution Exists:"
            " Following are the assigned colors \n";
    for (int i = 0; i < a; i++)
        cout << "  " << color[i];
    cout << "\n";
}

bool aman_kah(vector<vector<int>> &matrix, int color[], int a)
{
    for (int i = 0; i < a; i++)
    {
        for (int k : matrix[i])
        {
            if (color[i] == color[k])
            {
                return false;
            }
        }
    }
    return true;
}

bool ngecek_beda(vector<vector<int>> &matrix, int b, int i, int color[], int a)
{
    if (i == a)
    {
        if (aman_kah(matrix, color, a))
        {
            // printSolution(color, a);
            // cout << "YES!" << endl;
            // cout << "Tidak ada yang aneh, kak!" << endl;
            return true;
        }
        return false;
    }
    for (int j = 1; j <= b; j++)
    {
        color[i] = j;
        if (ngecek_beda(matrix, b, i + 1, color, a))
        {
            return true;
        }
        color[i] = 0;
    }
    return false;
}

int main()
{
    int a, sifat = 2, ke = 1;
    cin >> a;
    while (a--)
    {
        int b, c;
        cin >> b >> c;
        vector<vector<int>> inp(b);
        while (c--)
        {
            int d, e;
            cin >> d >> e;

            if (d > (int)inp.size())
            {
                inp.resize(d);
            }

            inp[d - 1].push_back(e - 1);
        }

        cout << "Penelitian #" << ke << ":" << endl;

        int color[b] = {0};
        ngecek_beda(inp, sifat, 0, color, b) ? cout << "Tidak ada yang aneh, kak!" << endl : cout << "Kak, aku menemukan ketidaksesuaian dengan hipotesis!" << endl;

        ke++;
        if (a != 0)
        {
            cout << endl;
        }
    }
}