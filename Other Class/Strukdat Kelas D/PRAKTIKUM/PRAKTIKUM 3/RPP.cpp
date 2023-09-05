#include<bits/stdc++.h>
using namespace std;

struct Soldier {
    string name;
    int age;
    string origin;
};

int main() {
    int n;
    cin >> n;

    Soldier soldiers[10000];
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> soldiers[i].name;
        cin >> temp;
        cin >> soldiers[i].age;
        cin >> temp;
        cin >> soldiers[i].origin;
    }

    int q;
    cin >> q;

    map<string, Soldier> soldierMap;
    for (int i = 0; i < n; i++) {
        soldierMap[soldiers[i].name] = soldiers[i];
    }

    string name;
    for (int i = 0; i < q; i++) {
        cin >> name;
        Soldier soldier = soldierMap[name];
        cout << "Usia: " << soldier.age << endl;
        cout << "Asal: " << soldier.origin << endl;
    }

    return 0;
}
