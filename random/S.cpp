#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countPairs(const vector<int>& nums, int k) {
    int count = 0;
    vector<string> numStrings(nums.size());

    // Convert integers to strings
    for (int i = 0; i < nums.size(); i++) {
        numStrings[i] = to_string(nums[i]);
    }

    // Check all pairs (i, j) where i ≠ j
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i != j) {
                string concat = numStrings[i] + numStrings[j];
                if (stoi(concat) % k == 0) {
                    count++;
                }
            }
        }
    }

    return count;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = countPairs(nums, k);
    cout << result << endl;

    return 0;
}
