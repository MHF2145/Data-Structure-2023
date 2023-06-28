#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    string str;
    cin >> str;
    int strLen = str.length();
    bool isValdi = false;

    for (int i = 0; i < strLen; i++) {
        if (s.empty() && (str[i] == '(' || str[i] == '{' || str[i] == '[')) {
            s.push(str[i]);
        }
        else if (s.empty() && (str[i] == ')' || str[i] == '}' || str[i] == ']')) {
            s.push(str[i]);
            isValdi = false;
            break;
        }
        else if (
            s.top() == '(' && str[i] == ')' ||
            s.top() == '[' && str[i] == ']' ||
            s.top() == '{' && str[i] == '}'
        ) {
            s.pop();
            isValdi = true;
        }
        else
            s.push(str[i]);
    }

    if (s.empty() || isValdi == true)
        cout << "valdi" << endl;
    else if (isValdi = false)
        cout << "unvaldi" << endl;
    else
        cout << "unvaldi" << endl;

    return 0;
}