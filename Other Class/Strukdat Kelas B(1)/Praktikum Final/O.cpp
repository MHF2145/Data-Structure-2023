#include <bits/stdc++.h>
using namespace std;

int arr[105][105];
int n, m, a, b;

void fill(int x, int y, int num) {
    if(x >= 0 && y >= 0 && x < n && y < n && num <= 4) {
    	if(arr[x][y] == 0) arr[x][y] = num;
	    else arr[x][y] = min(arr[x][y], num);
	
	    fill(x - 1, y, num + 1);
	    fill(x, y - 1, num + 1);
	    fill(x + 1, y, num + 1);
	    fill(x, y + 1, num + 1);
	}    
}

int main() {
    cin >> n >> m;

    while(m--) {
        cin >> a >> b;
        fill(b - 1, a - 1, 1);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}