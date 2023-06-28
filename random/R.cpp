#include <iostream>
#include <vector>

using namespace std;


string addLists(vector<int>& list1, vector<int>& list2) {
    int m = list1.size();
    int n = list2.size();
    int carry = 0;
    string result = "";


    int i = m - 1, j = n - 1;
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += list1[i];
            i--;
        }
        if (j >= 0) {
            sum += list2[j];
            j--;
        }
        carry = sum / 10;
        sum = sum % 10;
        result = to_string(sum) + result;
    }

    return result;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> list1(m);
    vector<int> list2(n);


    for (int i = 0; i < m; i++) {
        cin >> list1[i];
    }


    for (int i = 0; i < n; i++) {
        cin >> list2[i];
    }

    string sum = addLists(list1, list2);

    cout << sum << endl;

    return 0;
}
