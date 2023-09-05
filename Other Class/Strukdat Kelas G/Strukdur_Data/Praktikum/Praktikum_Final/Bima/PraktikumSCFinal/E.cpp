#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
#define pb(x) push_back(x)
using namespace std; 

int n, t;
vector<int> head, ranks; 

typedef struct{
    int bgn, ends, dangerLvl;
} Edge;

void init(){
	head.resize(n + 5); 
	ranks.resize(n + 5, 0); 
	for (int i = 1; i <= n; i++){
		head[i] = i; 
	}
}

int search(int temp){
	if (head[temp] != temp){
		head[temp] = search(head[temp]); 
	}
	return head[temp];
}

void helper(int x, int y){
	int Fx = search(x), Fy = search(y); 
	if (ranks[Fx] < ranks[Fy]){
		head[Fx] = Fy;
	}
    else if (ranks[Fx] > ranks[Fy]){
    	head[Fy] = Fx;
	}
    else{
        head[Fy] = Fx;
        ranks[Fx]++;
    }
}

int solve(vector<Edge> &edges){
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b){ 
		return a.dangerLvl < b.dangerLvl; 
	});

    init();
    int danger = 0;

    for (int i = 0; i < edges.size(); i++){
	    int start = search(edges[i].bgn);
	    int finish = search(edges[i].ends);
		
	    if (start != finish){
	        helper(start, finish);
	        danger = max(danger, edges[i].dangerLvl);
	    }
	}

    return danger;
}

int main(){
	cin >> n >> t; 
	
	vector<Edge> edges;
	
	while (t--){
		int x, y, dLevel;
		cin >> x >> y >> dLevel;  
		edges.push_back({x, y, dLevel});
	}
	
	int ans = solve(edges); 
	cout << ans << endl;
}
