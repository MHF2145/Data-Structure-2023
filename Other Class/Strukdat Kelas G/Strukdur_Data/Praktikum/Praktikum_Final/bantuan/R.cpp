#include <iostream>
#include <vector>

using namespace std;

string sumLists(vector<int>& list1, vector<int>& list2) {
    if (list1.empty()) {
        string sum = "";
        for (int num : list2) {
            sum += to_string(num);
        }
        return sum;
    }

    if (list2.empty()) {
        string sum = "";
        for (int num : list1) {
            sum += to_string(num);
        }
        return sum;
    }

    int carry = 0;
    int i = list1.size() - 1;
    int j = list2.size() - 1;
    string sum = "";

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? list1[i] : 0;
        int digit2 = (j >= 0) ? list2[j] : 0;

        int currentSum = digit1 + digit2 + carry;
        carry = currentSum / 10;
        int digitSum = currentSum % 10;

        sum = to_string(digitSum) + sum;

        i--;
        j--;
    }

    return sum;
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

    string result = sumLists(list1, list2);

    cout << result << endl;

    return 0;
}
