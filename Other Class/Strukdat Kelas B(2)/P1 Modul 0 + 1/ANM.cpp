#include <iostream>
#include <queue>

using namespace std;
int main() {
    deque<int> dq;
    int x, y, n;
    int id;
    cin >> x >> y >> n;

    for (int i = 0; i < x; i++) {
        cin >> id;
        dq.push_back(id);
    }

    for (int i = 0; i < n; i++) {
        if (dq.empty()) {
            cout << "Kasian Ersya\n";
            return 0;
        }
        dq.pop_front();
        if (dq.empty()) {
            cout << "Kasian Ersya\n";
            return 0;
        }
        for (int i = 0; i < y; i++) {
            int temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);
        }
    }

    if (dq.empty()) {
        cout << "Kasian Ersya\n";
    }
    else {
        cout << dq.front() << endl;
    }
    return 0;
}