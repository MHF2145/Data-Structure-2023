#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, w;
    int mfish;
    cin >> n;
    mfish = n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> w;
        vec[i] = w;
    }

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        pq.push(vec[i]);
        if (vec[i] == mfish) {
            while (!pq.empty() && pq.top() == mfish) {
                cout << pq.top() << " ";
                pq.pop();
                mfish--;
            }
        }

        cout << endl;
    }
}