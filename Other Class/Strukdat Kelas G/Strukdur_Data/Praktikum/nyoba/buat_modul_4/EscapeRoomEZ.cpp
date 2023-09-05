#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &ruangans, int visited[], int kunci)
{
    visited[kunci] = 1;
    for (int i = 0; i < ruangans[kunci].size(); i++)
    {
        if (visited[ruangans[kunci][i]] == 0)
        {
            dfs(ruangans, visited, ruangans[kunci][i]);
        }
    }
}

bool cek_kunci(vector<vector<int>> &ruangans)
{
    int cek[1005] = {0};
    dfs(ruangans, cek, 0);
    for (int i = 0; i < ruangans.size(); i++)
    {
        if (cek[i] == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int a;
    cin >> a;
    vector<vector<int>> ruangan(a);

    for (int i = 0; i < a; i++)
    {
        int nomor, banyak;
        cin >> nomor >> banyak;
        for (int j = 0; j < banyak; j++)
        {
            int kunci;
            cin >> kunci;
            ruangan[i].push_back(kunci);
        }
    }
    if (cek_kunci(ruangan))
    {
        cout << "berhasil" << endl;
    }
    else
    {
        cout << "gagal" << endl;
    }
}