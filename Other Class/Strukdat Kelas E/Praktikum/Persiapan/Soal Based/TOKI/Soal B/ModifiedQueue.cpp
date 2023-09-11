/*Nyolong dari jeje*/

#include<iostream>
#include<deque>

using namespace std;

int main(){
	int n;
	bool ascending = true;
	deque<int> dq;
	cin >> n;
	while(n--){
		if(ascending == true){
		string cmd;
		cin >> cmd;
		if(cmd == "add"){
			int x,y;
			cin >> x >> y;
			while(y--){
				dq.push_back(x);
			}
			cout << dq.size() << endl;
		}
		
		else if(cmd == "del"){
			int y;
			cin >> y;
			cout << dq.front() << endl;
			while(y--){
				dq.pop_front();
			}
			}
		else if(cmd == "rev"){
			ascending = !ascending;
		}
	}
		
		else if(ascending == false){
		string cmd;
		cin >> cmd;
		if(cmd == "add"){
			int x,y;
			cin >> x >> y;
			while(y--){
				dq.push_front(x);
			}
			cout << dq.size() << endl;
		}
		
		else if(cmd == "del"){
			int y;
			cin >> y;
			cout << dq.back() << endl;
			while(y--){
				dq.pop_back();
			}
			}
		else if(cmd == "rev"){
			ascending = !ascending;
		}
	}
}
}