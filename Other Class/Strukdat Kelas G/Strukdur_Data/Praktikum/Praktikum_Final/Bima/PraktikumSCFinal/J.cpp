#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
#define MOD 1000000009
using namespace std; 

int modex(int x, int y, int p){
    int res = 1; 
    x = x % p;
  
    if (x == 0) return 0; 
    while (y > 0){
        if (y & 1){
        	res = (res*x) % p;
		}
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

void solve(){
	int numb; 
	cin >> numb; 
	int ans = modex(2, ((numb*(numb-1))/2), MOD); 
	cout << "Zodiak found: " <<ans % MOD << " signs" <<  endl;
}
	
int main(){
	fastio; 
	int t; 
	cin >> t; 
	while(t--){
		solve();
	}
	return 0; 
}
