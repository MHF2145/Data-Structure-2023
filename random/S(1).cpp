#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mergeInt(int a, int b) {
    string num1 = to_string(a);
    string num2 = to_string(b);

    string mergedInt = num1 + num2;

    int res = stoi(mergedInt);

    return res;
}

int main() {
    int n, k, count = 0;
    cin >> n >> k;
    vector<int> a;
    int inpTemp;

    for (int i = 0; i < n; i++) {
        cin >> inpTemp;
        a.push_back(inpTemp);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j]) {
                continue;
            }

            int mergedNum = mergeInt(a[i], a[j]);
            if (mergedNum % k == 0) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}