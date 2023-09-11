#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    stack<int> st;
    cin >> n;
    
    while (n--) {
        cin >> a;
        
        if(st.empty()) {
            if (a == 1) {
                st.push(1);
                st.push(0);
            } 
			else st.push(0);
        } 
		else if(st.size() == 1) {
            if(st.top() == 1 && a == 1) st.pop();
            else if(st.top() == 1 && a == 0) st.push(0);
            else if(st.top() == 0 && a == 0) st.pop();
        } 
		else {
            if(st.top() == 1 && a == 1) st.pop();
            else if(st.top() == 1 && a == 0) st.push(0);
            else if(st.top() == 0 && a == 1) {
                st.pop();
                st.push(1);
                st.push(0);
                st.push(1);
                st.push(0);
            } 
			else st.pop();
        }
    }
    cout << st.size() << endl;
    
    return 0;
}
