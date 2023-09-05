#include <bits/stdc++.h>
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
         cout << "YES!" << endl;
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
   unordered_map<char, int> index;
   char test = 'A';
   for (int i = 0; i < 26; i++)
   {
      index[test] = i;
      test++;
      // cout << index[i] << " ";
   }

   int a, b;
   cin >> a >> b;
   cin.ignore();

   int beda[a] = {0};

   vector<vector<int>> matrix(a);

   for (int i = 0; i < a; i++)
   {
      string inp;
      getline(cin, inp);
      vector<int> sambungan;
      int ind = index[inp[0]];
      // cout << ind << endl;
      auto cari = inp.find('>');
      for (int j = cari + 2; j < (int)inp.size(); j++)
      {
         if (inp[j] != ' ' && inp[j] != ',')
         {

            sambungan.push_back(index[inp[j]]);
            // matrix[ind].push_back(k);
            // cout << (int)inp[j] << " ";
         }
      }
      // cout << endl;
      if (sambungan.size())
      {
         for (auto masuk : sambungan)
         {
            // cout << masuk << " ";
            matrix[ind].push_back(masuk);
         }
         // cout << endl;
      }
   }

   if (!ngecek_beda(matrix, b, 0, beda, a))
   {
      cout << "NO!" << endl;
   }
   return 0;
}