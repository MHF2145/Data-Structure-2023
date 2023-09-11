/*
k tumpukan dengan jumlah kado yang berbeda beda tiap tumpuknya

Syarat :
- Memiliki jumlah kado terbanyak diantara tumpukan lain
- Jika ada tumpukan dengan jumlah kado yang sama, pilih yang manapun
- Kobo tidak membuka semua kado pada tumpukan yang ia pilih, melainkan menyisakan kado
sebanyak akar dari jumlah kado pada tumpukan tersebut. (bulatkan hasil akar kebawah jika
memiliki desimal)

Kobo berencana membuka sebanyak n tumpukan kado. Hitunglah berapa jumlah kado yang tidak Kobo
buka.

Input Format
k, menyatakan jumlah tumpukan kado yang ada.
n, menyatakan jumlah tumpukan kado yang akan dibuka.
Kemudian baris k-buah angka, yang berisi p sebagai jumlah kado pada tiap tumpukan.

Output Format
Sebuah integer yang merepresentasikan jumlah kado yang tidak Kobo buka.
*/

#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, k, sum = 0;
    cin >> n >> k;

    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; //36 9 100 4
    }

    // Sort array terlebih dahulu
    sort(arr, arr+n); //4 9 36 100

    stack<int> s; //pakai stack biar lebih gampang ambil angka tergedenya

    // Masukin array yang dah ke sort tadi ke dalem stack
    for (int i = 0; i < n; i++) {
        s.push(arr[i]); //100 36 9 4
    }
    
    while(k--){ //ambil berapa kado yang dibuka sesuai sama yang diminta user
    	
    	//algoritma buat ambil stack tertinggi dan di akarkan lalu dipush kembali ke dalam stack yang diulangi sejumlah k kali
    	int tertinggi = s.top(); //tertinggi = 100
    	s.push(sqrt(tertinggi)); //pushed 10 -> 10 100 36 9 4
        
    	for(int i = 0; i < n;i++){
    		arr[i] = s.top(); 
    		s.pop();
		}
		
		sort(arr, arr+n); //4 9 10 36
		
		for(int i = 0; i < n; i++){
			s.push(arr[i]); //dalam stack -> 36 10 9 4
		}
		
		s.pop(); //dalam stack -> 10 9 4 dan 36 mulai diproses kayak tadi lagi
	}
	
	//penambahan isi dari stack
	while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    
    cout << sum << endl;

    return 0;
}
