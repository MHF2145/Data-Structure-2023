#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    int M, N, sum = 0, power = 1;
    string S;
    cin >> M >> N;

    deque<int> I(M), T(N);

    for (int i = 0; i < M; i++) {
        cin >> S;
        I[i] = stoi(S);
    }

    for (int i = 0; i < N; i++) {
        cin >> S;
        T[i] = stoi(S);
    }

    while (!I.empty() || !T.empty()) {
        int list1 = 0, list2 = 0;

        if (!I.empty()) {
            list1 = I.back();
            I.pop_back();
        }

        if (!T.empty()) {
            list2 = T.back();
            T.pop_back();
        }

        sum += (list1 + list2) * power;
        power *= 10;
    }

    cout << sum << endl;

    return 0;
}
