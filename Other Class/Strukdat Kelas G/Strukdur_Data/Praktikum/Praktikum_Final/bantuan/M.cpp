#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValidString(const string& S) {
    stack<char> st;

    for (char c : S) {
        if (c == '{' || c == '[' || c == '(') {
            st.push(c);
        } else if (c == '}' || c == ']' || c == ')') {
            if (st.empty()) {
                return false;
            }

            char top = st.top();
            st.pop();

            if ((c == '}' && top != '{') || (c == ']' && top != '[') || (c == ')' && top != '(')) {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    string S;

    getline(cin, S);

    if (isValidString(S)) {
        cout << "valdi" << endl;
    } else {
        cout << "unvaldi" << endl;
    }

    return 0;
}
