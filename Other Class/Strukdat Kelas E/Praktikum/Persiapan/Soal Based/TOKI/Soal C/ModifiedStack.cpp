/*Nyolong dari jeje juga*/

#include <iostream>
#include <stack>
#define ll long long
using namespace std;

int main(){
	stack<ll> st;
	
	ll n, offset = 0;
	cin >> n;
	
	string cmd;
	while(n--){
		cin >> cmd;
		if(cmd == "add"){
			ll x, y;
			cin >> x >> y;
			x -= offset;
			while(y--){
				st.push(x);
			}
			cout << st.size() << endl;
		}
		else if(cmd == "del"){
			ll y;
			cin >> y;
			cout << st.top() + offset << endl;
			while(y--){
				st.pop();
			}
		}
		else if(cmd == "adx"){
			ll x;
			cin >> x;
			offset += x;
		}
		else if(cmd == "dex"){
			ll x;
			cin >> x;
			offset -= x;
		}
	}
}