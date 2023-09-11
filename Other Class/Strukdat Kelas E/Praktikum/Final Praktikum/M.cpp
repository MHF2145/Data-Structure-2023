#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isStringValid(const string& string) {
    stack<char> stek;

    for (int i = 0; i < string.length(); i++) {
        char bracket = string[i];
        if (bracket == '(' || bracket == '{' || bracket == '[') {
            stek.push(bracket);
        } else if (bracket == ')' || bracket == '}' || bracket == ']') {
            if (stek.empty()) {
                return false;
            } else if ((bracket == ')' && stek.top() == '(') ||
                       (bracket == '}' && stek.top() == '{') ||
                       (bracket == ']' && stek.top() == '[')) {
                stek.pop();
            } else {
                return false;
            }
        }
    }

    return stek.empty();
}

int main() {
    string string;
    cin >> string;

    if (isStringValid(string)) {
        cout << "valdi" << endl;
    } else {
        cout << "unvaldi" << endl;
    }

    return 0;
}
