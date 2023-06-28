#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    cin.ignore();

    map<string, bool> print;
    map<string, string> temp;
    map<string, vector<vector<string>>> arr;

    while (n--)
    {
        string ip, nama;
        cin >> ip >> nama;
        temp[ip] = nama;
    }
    cin.ignore();
    while (m--)
    {
        string src, des, msg;
        cin >> src >> des;
        cin.ignore();
        getline(cin, msg);
        auto ada1 = temp.find(des);
        auto ada2 = temp.find(src);
        if (ada1 != temp.end() && ada2 != temp.end())
        {
            print[des] = true;
            arr[des].push_back({src, msg});
        }
    }

    for (auto i : print)
    {
        map<string, vector<string>> temp1;
        puts("===========");
        cout << "Mail: " << temp[i.first] << endl;
        for (auto j : arr[i.first])
        {
            temp1[j.front()].push_back(j.back());
        }

        for (auto j : temp1)
        {
            cout << "From: " << temp[j.first] << endl;
            for (auto k : j.second)
            {
                cout << ">> " << k << endl;
            }
        }
    }

    return 0;
}
