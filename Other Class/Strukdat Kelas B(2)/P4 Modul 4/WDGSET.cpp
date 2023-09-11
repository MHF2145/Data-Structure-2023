#include <bits/stdc++.h>
using namespace std;

int N, rep[100005], level[100005];

int findSet(int a) {
	if (rep[a] == a) {
		return a;
	}
	else {
		rep[a] = findSet(rep[a]);
		return rep[a];
	}
}

bool check(int a, int b) {
	return findSet(a) == findSet(b);
}

void join(int a, int b) {
	a = findSet(a);
	b = findSet(b);
	if (level[a] > level[b]) {
		rep[b] = rep[a];
	}
	else {
		rep[a] = rep[b];
		if (level[a] == level[a]) {
			level[b]++;
		}
	}
}

int charToInt(string str) {
    int out = 0;
    if (str[0] == 'A') {
        out += 0;
    }
    else if (str[0] == 'B') {
        out += 3;
    }
    else if (str[0] == 'C') {
        out += 6;
    }

    out += (int)(str[1] - '0');
    return out;
}

int main() {
	cin >> N;
	
	for (int i = 1; i < 10; i++) {
		rep[i] = i;
	}
	
	int cmd, a, b;
	while (N--) {
        string src, dst, garbage;
        cin >> src >> garbage >> dst;
        join(charToInt(src), charToInt(dst));
	}

    int out = 0;
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            if (!check(i, j)) {
                out++;
            }
        }
    }

    cout << out/2 << endl;
	return 0;
}