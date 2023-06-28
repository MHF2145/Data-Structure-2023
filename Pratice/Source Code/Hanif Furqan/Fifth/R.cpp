#include <iostream>
#include <vector>
#include <string>
using namespace std;

string addLists(vector<int> &list1, vector<int> &list2)
{
    int keri = 0;
    int m = list1.size();
    int n = list2.size();
    int i = m - 1;
    int j = n - 1;
    string result = "";

    while (i >= 0 || j >= 0 || keri > 0)
    {
        int jumlah = keri;
        if (i >= 0)
        {
            jumlah += list1[i];
            i--;
        }
        if (j >= 0)
        {
            jumlah += list2[j];
            j--;
        }
        keri = jumlah / 10;
        int digit = jumlah % 10;
        result = to_string(digit) + result;
    }

    return result;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> list1(m);
    vector<int> list2(n);

    for (int i = 0; i < m; i++)
    {
        cin >> list1[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> list2[i];
    }

    string jumlah = addLists(list1, list2);
    cout << jumlah << endl;

    return 0;
}
