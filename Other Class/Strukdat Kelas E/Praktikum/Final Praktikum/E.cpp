#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct jalanan
{
    int a,b,c;
    jalanan(int desaa, int desab, int bahaya){
        a = desaa;
        b = desab;
        c = bahaya;
    }
};

int find(vector<int>& par, int x) {
    if (par[x] != x) {
        return find(par, par[x]);
    }
    return x;
}

bool bandingjalanan(const jalanan& jalana, const jalanan& jalanb){
    return jalana.c < jalanb.c;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<jalanan> jalan;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        jalan.push_back(jalanan(a, b, c));
    }

    sort(jalan.begin(), jalan.end(), bandingjalanan);

    vector<int> par(n + 1);
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }

    int maxDanger = 0;
    int edgeidx = 0;
    for (int i = 0; i < jalan.size(); i++) {
    const jalanan& road = jalan[i];
    int a = road.a;
    int b = road.b;
    int c = road.c;

    if (find(par, a) != find(par, b)) {
        maxDanger = max(maxDanger, c);
        par[find(par, a)] = find(par, b);
        edgeidx++;
    }

    if (edgeidx == n - 1) {
        break;
    }
}

    cout << maxDanger << endl;

    return 0;
}