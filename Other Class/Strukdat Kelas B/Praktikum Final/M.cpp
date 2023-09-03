#include<bits/stdc++.h>
using namespace std;
 
int main() {
	stack<char> st;
    string str;
    cin >> str;
    
    for (int i = 0; i < str.length(); i++) {
        if (st.empty()) st.push(str[i]);
        else if ((st.top() == '(' && str[i] == ')') || (st.top() == '{' && str[i] == '}') || (st.top() == '[' && str[i] == ']')) st.pop();
        else st.push(str[i]);
    }
    if (st.empty()) cout << "valdi" << endl;
    else cout << "unvaldi" << endl;
    
	return 0;
}