#include<bits/stdc++.h>
using namespace std;
 
int main(){

	int testCase;
	// Baca input banyaknya test case
	cin>>testCase;
	// Lakukan perulangan sebanyak testcase
	while(testCase--)
	{
	    int n;
		// baca input berupa banyaknya tanda '('atau ')' yang akan di scan selanjutnya
	    cin>>n;
	    string s;
		// baca input berupa char '(' atau ')'
	    cin>>s;
		// 
	    stack<char> st;
	    for(int i = 0; i < n; i++){
			// cek apakah stack kosong, jika kosong lakukan maka push
	        if(st.empty()){
	            st.push(s[i]);
	        }
			// cek jika stack tidak kosong
	        else{
				// jika elemen teratas atau pertama pada stack adalah '(' maka lakukan push
	            if(s[i]=='(')
	            {
	                st.push(s[i]);
	            }
				// jika elemen teratas atau pertama pada stack adalah ')' maka lakukan pengecekan selanjutnya
	            else if(s[i]==')')
	            {
					// jika elemen teratas atau pertama pada stack adalah '(' maka lakukan pop
	                if(st.top()=='(')
	                    st.pop();
					// jika elemen teratas atau pertama pada stack bukan '(' maka lakukan push	
	                else
	                    st.push(s[i]);
	            }
	        }
	    }
		// print jumlah minimal operasi yang dilakukan dengan cara mencetak size dari stack kemudian dibagi dengan 2
	    cout<<st.size()/2<<endl;
	}
 return 0;
}