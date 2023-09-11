#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <algorithm>
using namespace std;

bool tidakrekomen(const vector<vector<int>>& graph, int cek) { //cek kalo misalnya promotor i ngepromosiin yang lain ato kgk
    for (const auto& giterate : graph) { //iterasi elemen di vektor
        if (!giterate.empty() && find(giterate.begin(), giterate.end(), cek) == giterate.end()) {
            return true; //kalo dia ga ngepromosiin yang lain, maka dia return true
        }
    }
    return false; //sebaliknya
}

int main() {
    int n, p1, p2;
    cin >> n; //3

    vector<vector<int>> graph(n + 1); //vector 2d dengan iterasi mulai dari 1
    cin >> p1 >> p2;
    while (p1 != -1 && p2 != -1) {
        graph[p1].push_back(p2); //masukin ke dalem vector di index p1
        cin >> p1 >> p2;
    }

    bool cek = false; //buat mastiin kalo nanti udah direkomen ato belom, mulainya dari false dlu karena belom ada yang direkomen
    
    for (int i = 1; i <= n; i++) {
        //kalo misalnya dia false, berarti promotor itu direkomen
        if (!tidakrekomen(graph, i)) { 
            cout << "pilih ini aja chris " << i << endl;
            cek = true;
            break;
        }
    }

    //tapi kalo misalnya dia true, berarti promotor itu ga direkomen
    if (!cek) {
        cout << "ga ada yang direkomen" << endl;
    }

    //nah untuk kasus testcase 2, promotor yang diambil 5 karena dia kepilihnya 2 kali pas iterasi kebanding promotor 2
    return 0;
}
