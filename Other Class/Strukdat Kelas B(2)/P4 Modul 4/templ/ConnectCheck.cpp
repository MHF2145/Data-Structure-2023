#include <bits/stdc++.h>
using namespace std;

int N, N, rep[100005], level[100005];

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

int main() {
	cin >> N >> N;
	
	for (int i = 0; i < N; i++) {
		rep[i] = i;
	}
	
	int cmd, a, b;
	while (N--) {
		cin >> cmd >> a >> b;
		if (cmd == 1) {
			join(a, b);
		}
		else {
			cout << (check(a, b) ? "Y" : "T") << endl;
		}
	}
	return 0;
}