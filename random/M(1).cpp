#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValidString(const string& s) {
    stack<char> stk;
    unordered_map<char, char> bracketPairs = {
        {'}', '{'},
        {']', '['},
        {')', '('}
    };

    for (char c : s) {
        if (c == '{' || c == '[' || c == '(') {
            stk.push(c);
        } else if (c == '}' || c == ']' || c == ')') {
            if (stk.empty() || bracketPairs[c] != stk.top()) {
                return false;
            }
            stk.pop();
        }
    }

    return stk.empty();
}

int main() {
    string s;
    getline(cin, s);

    if (isValidString(s)) {
        cout << "valdi" << endl;
    } else {
        cout << "unvaldi" << endl;
    }

    return 0;
}
