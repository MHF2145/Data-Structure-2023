#include <iostream>
#include <vector>
using namespace std;

bool amankah(const vector<int> &board, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        // ngecek diagonal sama kolom
        if (board[i] == col || board[i] - col == i - row || col - board[i] == i - row)
        {
            return false;
        }
    }
    return true;
}

void ngerjain(vector<int> &board, int row, int n, int &count)
{
    if (row == n)
    {
        count++;
        cout << "Solusi ke " << count << ":\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i] == j)
                {
                    cout << "Q ";
                }
                else
                {
                    cout << "- ";
                }
            }
            cout << '\n';
        }
        cout << '\n';
    }
    else
    {
        for (int col = 0; col < n; col++)
        {
            if (amankah(board, row, col))
            {
                board[row] = col;
                ngerjain(board, row + 1, n, count);
                board[row] = -1;
            }
        }
    }
}

void buatpapan(int n)
{
    // buat papan catur
    vector<int> board(n, -1);

    int total = 0;
    ngerjain(board, 0, n, total);

    cout << "Banyak solusi: " << total << '\n';
}

int main()
{
    buatpapan(8);

    return 0;
}
