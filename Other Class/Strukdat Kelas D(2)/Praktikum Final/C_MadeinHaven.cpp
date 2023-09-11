#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector <int> harga(n);
    
    for (int i =0; i < n; i++)
	{
      cin >> harga[i];
    }

    map<int,int> map;
    int checker = 0, outp = 0;
    for (int i = 0; i < n; i++)
    {
    	map[harga[i]]++;	
	}
      
    for (auto it : map)
    {
    	checker = max(checker, it.second);
	}
      

    int sisaan = n - checker;
    if (checker >= sisaan) cout << n - (2 * sisaan) << endl;
    else cout << n - 2 * (n / 2) << endl;

  }
}
