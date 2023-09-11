#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    deque<int> q;

    int n, temp;
    cin >> n;

    for (int i = n; i > 0; i--) {
        string command;
        cin >> command;

        if (command == "push_front") {
            cin >> temp;
            q.push_front(temp);
        } else if (command == "push_back") {
            cin >> temp;
            q.push_back(temp);
        } else if (command == "pop_front") {
            q.pop_front();
        } else if (command == "pop_back") {
            q.pop_back();
        }
    }

    for (int i = 0; i < q.size(); i++) {
        cout << q[i] << "\n";
    }

    return 0;
}
