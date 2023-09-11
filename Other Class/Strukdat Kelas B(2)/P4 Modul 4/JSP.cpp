#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> arr;

bool block(int x, int y) {
    if (x == n-1 && y == m-1) {
        return true;
    }

    if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == '#') {
        return false;
    }

    arr[x][y] = '#';
    if (block(x, y+1)) {
        return true;
    }
    if (block(x+1, y)) {
        return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        arr.push_back(str);
    }

    bool block1 = block(0, 1);
    bool block2 = block(1, 0);

    cout << block1 + block2 << endl;
    return 0;
}