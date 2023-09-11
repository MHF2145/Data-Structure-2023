#include <queue>
#include <stack>
#include <iostream>

using namespace std;
int main() {
    int n, inp;
    cin >> n;

    stack<int> st;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        cin >> inp;
        st.push(inp);
    }

    for (int i = 0; i < n; i++) {
        cin >> inp;
        q.push(inp);
    }

    int gadapet = 0;
    while (!st.empty()) {
        if (q.front() == st.top()) {
            q.pop();
            st.pop();
            gadapet = 0;
        }
        else {
            int temp = q.front();
            q.pop();
            q.push(temp);
            gadapet++;
        }

        if (gadapet == q.size()) {
            break;
        }
    }

    if (gadapet == 0) {
        cout << "Yeay semua dapet" << endl;
    }
    else {
        cout << "Yah " << gadapet << " orang ga dapet" << endl;
    }
    return 0;
}