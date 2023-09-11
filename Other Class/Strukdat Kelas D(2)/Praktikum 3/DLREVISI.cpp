#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    unordered_map<string, int> freq; //Map untuk cek ada angka kembar atau gak
    string x;

    for (int i = 0; i < n; i++) 
	{
        string num;
        cin >> num;
        freq[num]++;
        if (freq[num] == 2) //ada angka yang sama
		{
            x = num; // angka kembar yang akan direversed
        }
    }

    string rev_x = ""; //deklarasi string kosong
    
    for (int i = x.length()-1; i >= 0; i--) //reversed angka dengan cara rewrite dari belakang
	{
        rev_x += x[i];
    }

    string sum = ""; //deklarasi string kosong+
    int carry = 0;
    for (int i = 0; i < x.length(); i++) //penjumlahan string
	{
        int digit_x = x[i] - '0';
        int digit_rev_x = rev_x[i] - '0';
        int digit_sum = digit_x + digit_rev_x + carry;
        carry = digit_sum / 10;
        digit_sum %= 10;
        sum += to_string(digit_sum);
    }
    
    if (carry > 0) 
	{
        sum += to_string(carry);
    }

    string result = "";
    for (int i = sum.length()-1; i >= 0; i--) 
	{
        result += sum[i];
    }

    cout << result << endl;

    return 0;
}

