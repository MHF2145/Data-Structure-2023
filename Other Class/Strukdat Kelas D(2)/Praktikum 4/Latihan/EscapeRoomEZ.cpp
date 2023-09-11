#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool escapeRoom(int N, vector<vector<int>>& keys) {
    vector<bool> visited(N, false); // Array untuk melacak status kunjungan ruangan
    vector<bool> unlocked(N, false); // Array untuk melacak status ruangan yang terbuka
    vector<vector<int>> roomKeys(N); // Array untuk menyimpan kunci-kunci yang ada di setiap ruangan
    
    for (int i = 0; i < keys.size(); i++) {
        int room = keys[i][0]; // Nomor ruangan
        int numKeys = keys[i][1]; // Banyaknya kunci di ruangan
        
        // Menambahkan kunci-kunci ke array roomKeys
        for (int j = 0; j < numKeys; j++) {
            roomKeys[room].push_back(keys[i][j + 2]);
        }
    }
    
    queue<int> q;
    q.push(0); // Memulai dari ruangan 0
    visited[0] = true;
    unlocked[0] = true;
    
    // Melakukan BFS untuk mengeksplorasi ruangan dan mengambil kunci
    while (!q.empty()) {
        int room = q.front();
        q.pop();
        
        // Mengecek kunci-kunci yang ada di ruangan saat ini
        for (int i = 0; i < roomKeys[room].size(); i++) {
            int key = roomKeys[room][i];
            
            if (!visited[key]) {
                visited[key] = true;
                unlocked[key] = true;
                q.push(key);
            }
        }
    }
    
    // Mengecek apakah semua ruangan telah terbuka
    for (int i = 0; i < N; i++) {
        if (!unlocked[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> keys(N);
    
    // Membaca input kunci-kunci setiap ruangan
    for (int i = 0; i < N; i++) {
        int room, numKeys;
        cin >> room >> numKeys;
        
        keys[i].push_back(room);
        keys[i].push_back(numKeys);
        
        for (int j = 0; j < numKeys; j++) {
            int key;
            cin >> key;
            keys[i].push_back(key);
        }
    }
    
    if (escapeRoom(N, keys)) {
        cout << "berhasil" << endl;
    } else {
        cout << "gagal" << endl;
    }
    
    return 0;
}
w
