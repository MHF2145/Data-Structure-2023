#include <bits/stdc++.h> 
using namespace std;

long long mod = 1000000009;

long long calculateZodiac(long long x, long long y) 
{
	//Geeks for Geeks Modex
    long long res = 1;
 
    while (y > 0) 
	{

        if (y % 2 == 1)
        {
        	res = (res * x);
            res %= mod;
		}
            
 	    x *= x;
 	    x %= mod;
 	    y /= 2;
    }
    return res;
}

int main ()
{
	long long m;
	cin >> m;
	
	for(int i = 0; i < m; i++)
	{
		long long n;
		cin >> n;
		
		long long result = calculateZodiac(2, n*(n - 1) / 2);
		cout << "Zodiak found: " << result << " signs" << endl;
	}
	return 0;
}

