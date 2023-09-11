/*
Input Format
m, Menyatakan banyak kata yang diucapkan Cila.
n, Menyatakan perkataan Cila terbalik atau tidak (n = 0 menyatakan bahwa perkataan Cila tidak terbalik
dan n = 1 menyatakan bahwa perkataan Cila terbalik).
m kata, yang menandakan kata-kata yang diucapkan Cila.

jadi basically kalo misal 0, dia kek pushnya top dlu baru back
tapi kalo misal 1, dia pushnya back dlu baru top
*/

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(){
	int m,n;
	deque<string> dq;
	string kata, gabungan;
	
	cin >> m >> n;
	
	if(m == 0){
		cout << "Apa itu nol?" << endl;
	} 
	else {
		for(int i = 0;i < m; i++){
			cin >> kata;
			dq.push_front(kata); //masukin dlu kata2nya
		}	
			
		while(!dq.empty()){
			if(n == 0){
				//nanti pas dah mulai balik kata2nya balik ke sini lagi kek print kata2nya dari back (intinya dah muter2innya dari kata2nya)
				cout << dq.back() << " ";
				dq.pop_back(); //print kalimatnya dlu
					
				if(!dq.empty()){
					cout << dq.front() << " "; //mulai dari sini baru balik kata2nya
					dq.pop_front();
				}
			} else if(n == 1){ //gini juga tapi kebalikannya :D
				cout << dq.front() << " ";
				dq.pop_front();
					
				if(!dq.empty()){
					cout << dq.back() << " ";
					dq.pop_back();				
				}
			}	
		}
	}
	cout << endl;
} // semoga AC :pray:
