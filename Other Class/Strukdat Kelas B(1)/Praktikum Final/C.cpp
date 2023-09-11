#include<bits/stdc++.h>
using namespace std;

int n, t;

void solve() {
    cin >> n;

    int arr[n];
	map<int, int> m;
	int mf = 0, ans = 0;
	
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    for(int i = 0; i < n; i++) m[arr[i]]++;
    for(auto it : m) mf = max(mf, it.second);
    
    int temp = n - mf;
    if(mf >= temp) ans = temp;
    else ans = n / 2;
    
    cout << n - (2 * ans) << '\n';
}

int main() {
    cin >> t;
    while(t--) solve();
    
    return 0;
}
