#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

bool cekCond(string str){
	stack<char> st;
	int n = str.length(); 
	for (int i = 0; i < n; i++) {
		if (st.size() == 0) {
			st.push(str[i]);
			continue; 
		}
		if ((st.top() == '(' && str[i] == ')') || (st.top() == '{' && str[i] == '}') || (st.top() == '[' && str[i] == ']')) {
			st.pop();
			continue;
		}
		st.push(str[i]);
	}
	if (st.size() == 0) {
		return true;
	}
	return false;
}

int main() {
	string str;
	cin >> str; 
	if (cekCond(str)){
		cout << "valdi";
		return 0;
	}
	cout << "unvaldi";
	return 0;
}

