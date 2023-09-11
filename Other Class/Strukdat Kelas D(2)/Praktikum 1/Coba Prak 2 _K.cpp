#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

struct Node {
    long long val;
    Node* nullptr;
    Node* left;
    Node* right;
    Node() {
        val = -1;
        left = nullptr;
        right = nullptr;
    }
};

void insert(Node* root, long long x, long long& last_even, long long& last_odd) {
	Node* nullptr;
    if (root == nullptr || root->val == -1) {
        root->val = x;
    } else {
        if (x % 2 == 0) {
            if (last_odd != -1) {
                root->left = new Node();
                root->left->val = last_even;
                root->right = new Node();
                root->right->val = last_odd;
            }
            last_even = x;
        } else {
            last_odd = x;
        }
    }
}

long long calculate_power(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* root = new Node();
    long long last_even = -1, last_odd = -1;
    string line;

    while (getline(cin, line)) {
        long long x = stoll(line);
        insert(root, x, last_even, last_odd);
    }

    if (root->left != nullptr) {
        long long a = root->left->val, b = root->right->val;
        long long result = calculate_power(a, b);
        cout << result << "\n";
    } else {
        cout << "Tidak ada duplikat\n";
    }

    return 0;
}

