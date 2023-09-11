#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    int global_id = 1;
    stack<int> st1, st2, st3;
    int N, arg;
    string cmd;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cmd >> arg;
        if (cmd == "KOTOR") {
            for (int i = 0; i < arg; i++) {
                st1.push(global_id++);
            }
        }
        else if (cmd == "CUCI") {
            for (int i = 0; i < arg; i++) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        else {
            for (int i = 0; i < arg; i++) {
                st3.push(st2.top());
                st2.pop();
            }
        }
    }

    vector<int> temp;
    cout << "tumpukan 1:";
    while (!st1.empty()) {
        temp.push_back(st1.top());
        st1.pop();
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        cout << " " << temp[i];
    }
    cout << endl;
    temp.clear();

    cout << "tumpukan 2:";
    while (!st2.empty()) {
        temp.push_back(st2.top());
        st2.pop();
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        cout << " " << temp[i];
    }
    cout << endl;
    temp.clear();

    cout << "tumpukan 3:";
    while (!st3.empty()) {
        temp.push_back(st3.top());
        st3.pop();
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        cout << " " << temp[i];
    }
    cout << endl;
    temp.clear();

    
}