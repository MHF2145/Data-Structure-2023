#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int k) {
    map<int, int> m[69];
	int len[n + 1] = {0};
    int power[69] = {0};
    power[0] = 1;
	int ans = 0;
    
    for(int i = 1; i <= 10; i++) power[i] = (power[i - 1] * 10) % k;
 
    for(int i = 0; i < n; i++) {
        int x = arr[i];
        while (x > 0) {
            len[i]++;
            x /= 10;
        }
        m[len[i]][arr[i] % k]++;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= 10; j++) {
            int temp1 = (arr[i] * power[j]) % k;
            int temp2 = (k - temp1) % k;
            ans += m[j][temp2];
 
            if(len[i] == j && (temp1 + arr[i] % k) % k == 0) ans--;
        }
    }
 
    return ans;
}

int main() {
    int n, k, a;
    cin >> n >> k;
    
	int arr[n + 1];
	for(int i = 0; i < n; i++) cin >> arr[i];
    
    cout << solve(arr, n, k) << endl;
    
    return 0;
}