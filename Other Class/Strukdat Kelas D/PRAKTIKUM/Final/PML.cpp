#include <iostream>
#include <vector>

using namespace std;

string addList(vector<int>& list1, vector<int>& list2) {
    int carry = 0;
    string hasil;

    int size = max(list1.size(), list2.size());

    for (int i = 0; i < size; i++) {
        int digit1 = (i < list1.size()) ? list1[list1.size() - i - 1] : 0;
        int digit2 = (i < list2.size()) ? list2[list2.size() - i - 1] : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        hasil.insert(0, to_string(sum % 10));
    }

    if (carry > 0) {
        hasil.insert(0, to_string(carry));
    }

    return hasil;
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<int> list1(M);
    vector<int> list2(N);

    for (int i = 0; i < M; i++) {
        cin >> list1[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> list2[i];
    }

    string hasil = addList(list1, list2);

    cout << hasil << endl;

    return 0;
}
