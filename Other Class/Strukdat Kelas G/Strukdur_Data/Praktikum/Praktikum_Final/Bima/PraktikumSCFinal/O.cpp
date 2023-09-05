#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
using namespace std; 

int main(){
	fastio; 
    int n, t;
    int map[200][200];
    memset(map, 0, sizeof(map)); 
    cin >> n >> t;
    while (t--){ 
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        for (int j = 1; j <= 3; j++){
            for (int i = 0; i <= j; i++){
                if (map[a - j + i][b - i] == 0){
                	map[a - j + i][b - i] = j + 1;
				}
                else{
                	map[a - j + i][b - i] = min(map[a - j + i][b - i], j + 1);
				}
                if (map[a - j + i][b + i] == 0){
                	map[a - j + i][b + i] = j + 1;
				}
                else{
                	map[a - j + i][b + i] = min(map[a - j + i][b + i], j + 1);
				}
            }

            for (int i = j; i >= 0 ; i--){
                if (map[a + j - i][b - i] == 0){
                	map[a + j - i][b - i] = j + 1;
				}                   
                else{
                	 map[a + j - i][b - i] = min(map[a + j - i][b - i], j + 1);
				}
                if (map[a + j - i][b + i] == 0){
                	map[a + j - i][b + i] = j + 1;
				}
                else{
                	map[a + j - i][b + i] = min(map[a + j - i][b + i], j + 1);
				}
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << map[j][i] << " ";
        }
        cout << endl;
    }
}
