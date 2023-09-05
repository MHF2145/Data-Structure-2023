#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Buat()
{
    vector<int> set;
    int count = 0;

    while (count < 7)
    {
        // rumus untuk random antara 1-40
        int num = rand() % 40 + 1;

        if (find(set.begin(), set.end(), num) == set.end())
        {
            set.push_back(num);
            count++;
        }
    }

    return set;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < 5; i++)
    {
        vector<int> set = Buat();

        cout << "Set ke " << i + 1 << ": ";
        for (int num : set)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
