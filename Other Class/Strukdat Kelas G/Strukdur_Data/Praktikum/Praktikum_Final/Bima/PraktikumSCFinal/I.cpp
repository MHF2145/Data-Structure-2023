#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
#define pb(x) push_back(x)
using namespace std; 

vector<vector<int> > itung;

int Cyclebfs(int start){
    int n = itung.size();
    vector<bool> visited(n, false);
    vector<int> steps(n, 0);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (q.size() != 0){
        int temp = q.front();
        q.pop();
        
        for (int i = 0; i < itung[temp].size(); i++){
		   	int j = itung[temp][i]; 
		   	if (j == start){
		   		return steps[temp] + 1;
			}
			if (visited[j] == false){
				visited[j] = true;
            	steps[j] = steps[temp] + 1;
            	q.push(j);
			}
            
        }
    }

    return -1;
}

void addGraph(int x, int y){
    itung[x].pb(y);
}

int main(){
	fastio; 
	int n; 
	cin >> n; 
	itung.resize(n); 
	
	while (1){
		int x, y; 
		cin >> x >> y; 
		if (x == -1 && y == -1){
			break; 
		}
		addGraph(x, y); 
	}
	
	for(int i = 0; i < n; i++){
		int ans = Cyclebfs(i); 
		if (ans == -1){
			cout << "gak bisa pulang mamah" << endl;
			continue; 
		}
		cout << ans << endl; 
	}
	
	
	
	return 0; 
}
