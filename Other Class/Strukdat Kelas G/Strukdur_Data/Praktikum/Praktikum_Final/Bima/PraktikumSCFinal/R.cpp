#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;


int main(){
	fastio;
	int a, b; 
	cin >> a >> b; 
	char ans1[1005] = "", ans2[1005]= ""; 
	int ar1[a], ar2[b]; 
	for (int i = 0; i < a; i++){
		char numb[100]; 
		cin >> numb;
		strcat(ans1, numb); 
	}
	
	for (int i = 0; i < b; i++){
		char numb[100];
		cin >> numb;
		strcat(ans2, numb); 
	}

	int numb1 = atoi(ans1); 
	int numb2 = atoi(ans2); 
//	cout << ans1  << " " << ans2; 
//	cout << numb1  << " " << numb2; 
	cout << numb1 + numb2; 
	return 0;
	
}
