#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, sr;
    cin >> n;
    stack<int> st;

    // S = 1; R = 0
    for (int i = 0; i < n; i++) {
        cin >> sr;

        int testCase = n;
        int stTop = st.top();
        if (st.size() == 0) {
            if (sr == 1) {
                st.push(1);
                st.push(0);
            } else if (sr == 0)
                st.push(0);
        } else if (st.size() == 1) {
            if (stTop == 1) {
                if (sr == 1) {
                    st.pop();
                } else if (sr == 0) {
                    st.push(0);
                }
            }
            else if (stTop == 0) {
                if (sr == 0) {
                    st.pop();
                }
            }
        } else if (st.size() > 1) {
            if (stTop == 1) {
                if (sr == 1) 
                    st.pop();
                else if (sr == 0)
                    st.push(0);
            } else if (stTop == 0) {
                if (sr == 1) {
                    st.pop();
                    st.push(1);
                    st.push(0);
                    st.push(1);
                    st.push(0);
                } 
                else if (sr == 0)
                    st.pop();
            }
        }
        
    }

    cout << st.size();

    return 0;
}