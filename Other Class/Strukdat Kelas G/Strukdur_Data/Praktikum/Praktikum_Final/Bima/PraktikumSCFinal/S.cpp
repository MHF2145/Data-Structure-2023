#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
#define MOD 1000000009
using namespace std; 

map<int, int> mapTemp[11];

int countPerm(vector<int> a, int n, int k){
    vector<int> len(n);
    vector<int> p(11);
    p[0] = 1;
    for (int i = 1; i <= 10; i++) {
        p[i] = (p[i - 1] * 10) % k;
    }
 
    for (int i = 0; i < n; i++) {
        int x = a[i];
        while (x > 0) {
            len[i]++;
            x /= 10;
        }
        mapTemp[len[i]][a[i] % k]++;
    }

    int ans = 0;
 
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 10; j++) {
            int r = (a[i] * p[j]) % k;
            int xr = (k - r) % k;
            ans += mapTemp[j][xr];
            if (len[i] == j && (r + a[i] % k) % k == 0){
				ans--;
			}	
        }
    }
    return ans;
}

int main(){
	fastio; 
	int n, div; 
	cin >> n >> div; 
	
	vector<int> v(n); 
	for(int i = 0; i < n; i++){
		cin >> v[i]; 
	}
	int ans = countPerm(v, n, div);
	cout << ans;
	return 0; 
}
