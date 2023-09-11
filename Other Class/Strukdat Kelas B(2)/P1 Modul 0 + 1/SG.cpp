#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<vector<string>> goat;
    
    int N, cmd;
    cin >> N;
    while (N--) {
        cin >> cmd;
        if (cmd == 1) {
            int K;
            string name;
            cin >> K;
            vector<string> goatlist(K);
            for (int i = 0; i < K; i++) {
                cin >> name;
                goatlist[i] = name;
            }
            goat.push_back(goatlist);
        }
        else if (cmd == 2) {
            unsigned int A, B;
            cin >> A >> B;
            if (goat[A-1].size() < B) {
                cout << "Kambing Tidak Ada" << endl;
            }
            else {
                cout << goat[A-1][B-1] << endl;
                goat[A-1].erase(goat[A-1].begin() + (B-1));
            }
        }
    }
    return 0;
}