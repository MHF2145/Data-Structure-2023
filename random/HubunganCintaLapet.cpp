#include <bits/stdc++.h>

using namespace std;

int SetHubungan[10][10];
vector<int> visited, VectorDFS;
vector<vector<int>> AdjList;

// Di inisialisasi hubungan untuk setiap node yang terhubung dengan dirinya sendiri
void InitialisasiHubungan()
{
    for (int i = 0; i < 10; i++)
    {
        SetHubungan[0][i] = 1;
        SetHubungan[i][0] = 1;
        SetHubungan[i][i] = 1;
    }
}

int Angka(char a, char b)
{
    if (a == 'A' && b == '1')
        return 1;
    else if (a == 'B' && b == '1')
        return 2;
    else if (a == 'C' && b == '1')
        return 3;
    else if (a == 'A' && b == '2')
        return 4;
    else if (a == 'B' && b == '2')
        return 5;
    else if (a == 'C' && b == '2')
        return 6;
    else if (a == 'A' && b == '3')
        return 7;
    else if (a == 'B' && b == '3')
        return 8;
    else
        return 9;
}

void dfs(size_t u)
{
    visited[u] = 1;
    VectorDFS.push_back(u);
    for (size_t i = 0; i < VectorDFS.size(); i++)
    {
        SetHubungan[VectorDFS[i]][u] = 1;
        SetHubungan[u][VectorDFS[i]] = 1;
    }
    for (size_t i = 0; i < AdjList[u].size(); i++)
    {
        int v = AdjList[u][i];
        if (visited[v] == -1)
            dfs(v);
    }
}

int main()
{
    bool broken = false;
    visited.assign(10, -1);
    AdjList.assign(10, vector<int>());
    memset(SetHubungan, 0, sizeof(SetHubungan));
    InitialisasiHubungan();

    int n;
    cin >> n;
    string Input;
    getline(cin, Input);
    for (int i = 0; i < n; i++)
    {
        getline(cin, Input);
        int a = Angka(Input[0], Input[1]);
        int b = Angka(Input[7], Input[8]);
        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }

    /*  cout << "SetHubungan sebelum dfs" << endl;
     for (int i = 0; i <= 9; i++)
     {
         for (int j = 0; j <= 9; j++)
         {

             cout << SetHubungan[i][j];
         }
         cout << endl;
     } */

    int Hasil = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (visited[i] == -1)
        {
            dfs(i);
            VectorDFS.clear();
        }
    }

    /* cout << "\nSetHubungan setelah dfs" << endl;
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {

            cout << SetHubungan[i][j];
        }
        cout << endl;
    } */

    if (SetHubungan[7][6] == 0 && SetHubungan[8][6] == 0)
        broken = true;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (!SetHubungan[i][j] && !SetHubungan[j][i])
            {
                Hasil++;
                SetHubungan[i][j] = 1;
                SetHubungan[j][i] = 1;
            }
        }
    }

    /* cout << "\nSetHubungan setelah Hasil" << endl;
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {

            cout << SetHubungan[i][j];
        }
        cout << endl;
    } */
    /*  if (Hasil == 21 && broken)
     {
         Hasil = 15;
     } */
    cout << Hasil << endl;
    return 0;
}
