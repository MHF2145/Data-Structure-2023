#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    cin.ignore();

    map<string, string> namaemail;
    map<string, vector<pair<string, string>>> pesanemail;

    for (int i = 0; i < N; i++) {
        string alamat, nama;
        cin >> alamat >> nama;
        namaemail[alamat] = nama;
    }

    for (int i = 0; i < Q; i++) {
        string pengirim, penerima, pesan;
        cin >> pengirim >> penerima;
        getline(cin, pesan);
        if (namaemail.count(pengirim) > 0 && namaemail.count(penerima) > 0) {
            pesanemail[penerima].push_back(make_pair(pengirim, pesan));
        }
    }

    for (auto it = pesanemail.begin(); it != pesanemail.end(); it++) {
        cout << "===========\n";
        cout << "Mail: " << namaemail[it->first] << endl;
        map<string, vector<string>> pesanpengirim;
        for (auto vecIt = it->second.begin(); vecIt != it->second.end(); vecIt++) {
            string pengirim = vecIt->first;
            string pesan = vecIt->second;
            pesanpengirim[pengirim].push_back(pesan);
        }
        for (auto pengirimIt = pesanpengirim.begin(); pengirimIt != pesanpengirim.end(); pengirimIt++) {
            cout << "From: " << namaemail[pengirimIt->first] << endl;
            for (auto pesanIt = pengirimIt->second.begin(); pesanIt != pengirimIt->second.end(); pesanIt++) {
                cout << ">> " << *pesanIt << endl;
            }
        }
    }
    return 0;
}