#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std; 

int main(){
	fastio;
	int count = 0, tot = 0;
	map <int, int> list; 
	while (1){
		count++; 
		int id, price; 
		cin >> id >> price;
		if(id == 0 && price == 0){
			break;
		} 
		if(id != count){
			cout << "ID harus urut" << endl; 
			return 0;
		}
		list[id] = price; 
	}
	while(1){ 
		int id, jml; 
		cin >> jml >> id; 
		if (id == 0 && jml == 0){
			cout << tot << endl; 
			return 0; 
		}
//		cout << tot << endl; 
		if (list.find((id)) != list.end()){
			tot += (jml * list[id]); 
			continue;
		}
		cout << "Maaf barang tidak tersedia" << endl; 
		
	}
	
	
	return 0; 
}
