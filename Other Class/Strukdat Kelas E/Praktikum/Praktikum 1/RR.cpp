/*
n, menyatakan banyaknya roti yang tersedia dan siswa yang sedang mengantre.

Kemudian 2 baris n-buah angka, yang terdiri dari angka 1 atau 0 (angka 1 menyatakan roti coklat, dan
angka 0 menyatakan roti kacang).

Baris pertama merupakan tumpukan roti dari yang paling bawah sampai yang paling atas. -> stack

Baris kedua merupakan antrian siswa dari yang paling depan sampai yang paling belakang (angka 1 atau 
0 pada siswa menyatakan pilihan roti siswa tersebut) -> queue

Intinya, kalo misalnya dah sama dua2nya di pop (stack sama queuenya)
kalo si queue beda sama si stack, maka queue akan disorting ulang sampe sama kek stacknya

CASE 1 :
setelah diputer2 dapet yang sama dan ngeluarin output "yeay semua dapet"

CASE 2 :
udah diputer2 tapi tetep aja gadapet dan ngeluarin output "yah x orang ga dapet" (x merupakan jumlah orang yang gadapet)
*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int n, cek = 0, depan;
    
    cin >> n;
    
    stack<int> tumpukan;
    queue<int> antrian;
    
    for(int i = 0; i < n; i++){
    	int roti;
    	cin >> roti;
    	tumpukan.push(roti);
	}
	
	for(int i = 0; i < n; i++){
		int siswa;
		cin >> siswa;
		antrian.push(siswa);
	}
	
	while(!antrian.empty() && !tumpukan.empty()){
		//kalo sama dua2nya di pop
		if(antrian.front() == tumpukan.top()){
			tumpukan.pop();
			antrian.pop();
			cek = 0;
		} else { //kalo beda diurutin lagi -> algo disini frontnya dihold dky gitu baru nanti dipush jadi pindah ke belakang gitu
			depan = antrian.front();
			antrian.pop();
			antrian.push(depan);
			cek++; //buat nambahin iterasinya
		}
		if(cek > n){
			break;
		}
	}
	
	if(antrian.empty()){
		cout << "Yeay semua dapet" << endl;
	} else {
		cout << "Yah " << antrian.size() << " orang ga dapet" << endl;
	}
	
    return 0;
}


