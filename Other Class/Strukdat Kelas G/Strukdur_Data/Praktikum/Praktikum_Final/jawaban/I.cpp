#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> itung;
int Cyclebfs(int kalku);

int main()
{
    int inp;
    cin >> inp;

    itung.resize(inp);
    while (1)
    {
        int a, b;
        cin >> a >> b;
        if (b == -1 && a == -1)
        {
            break;
        }
        itung[a].push_back(b);
    }

    for (int i = 0; i < inp; i++)
    {
        int output = Cyclebfs(i);
        if (output == -1)
        {
            cout << "gak bisa pulang mamah" << endl;
            continue;
        }
        cout << output << endl;
    }

    return 0;
}

int Cyclebfs(int kalku)
{
    int z = itung.size();
    vector<int> langkah(z, 0);
    vector<bool> check(z, false);
    queue<int> y;

    check[kalku] = true;
    y.push(kalku);

    while (y.size() != 0)
    {
        int temp = y.front();
        y.pop();

        for (int i = 0; i < (int)itung[temp].size(); i++)
        {
            int j = itung[temp][i];
            if (j == kalku)
            {
                return langkah[temp] + 1;
            }
            if (check[j] == false)
            {
                check[j] = true;
                langkah[j] = langkah[temp] + 1;
                y.push(j);
            }
        }
    }

    return -1;
}