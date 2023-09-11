/*
Detect suatu suatu Binary dari integer, kalo Binary itu 0nya/1nya bersebelahan nanti dikurangin, misal :

Binary dari 20 adalah (10100) -> 0 paling belakang ada 2 yang bersebelahan
Kurangin 0nya
Binary sekarang adalah : (101) -> kalo diubah jadi integer dia itu 5
print 5
*/

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(){
	int t;
    long long n;
	deque<int> dq;
	vector<long long> simpen; //pake vector buat simpen hasil
	
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> n;
		dq.clear(); //agar bisa lanjut ke test case selanjutnya
		
		//algoritma mengubah angka menjadi binary
		while(n > 0){
			int sisa = n % 2;
			n /= 2;
			
			//memasukkan binary number ke dalam deque dan pop yang samaan
			if(dq.empty() || dq.front() != sisa){
				dq.push_front(sisa);
			} else {
				dq.pop_front();
			}
		}
	
		//algoritma mengubah kembali binary menjadi angka
		long long decimal = 0;
	    long long base = 1;
	    while (!dq.empty()) { 
	    	//perhitungan biner (1 * 2^0 + 1 * 2^1 + 1 * 2^2 + 0 * 2^3 + 1 * 2^4 + 1 * 2^5 = 45)
	        decimal += dq.back() * base;
	        base *= 2;
	        dq.pop_back();
	    }
	    
	    simpen.push_back(decimal);
	}
	
	for(int i = 0; i < static_cast<int>(simpen.size());i++){
    	cout << simpen[i] <<endl;
	}		
}
