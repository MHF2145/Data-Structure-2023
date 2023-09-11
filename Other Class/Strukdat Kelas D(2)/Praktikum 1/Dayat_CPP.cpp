#include <bits/stdc++.h>
using namespace std;

struct Bus {
    int id, rating, capacity;
    bool operator < (const Bus &other) const {
        if (rating == other.rating)
            return capacity < other.capacity;
        return rating < other.rating;
    }
};

int main() {
    int n;
    cin >> n;
    priority_queue<Bus> buses;
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "REGIS") {
            int id, rating, capacity;
            cin >> id >> rating >> capacity;
            buses.push({id, rating, capacity});
        } else if (cmd == "SEWA") {
            int m = 0;
            cin >> m;
            bool found = false;
            while (!buses.empty()) {
                Bus bus = buses.top();
                if (bus.capacity >= m) {
                    cout << bus.id << " telah berhasil disewa\n";
                    found = true;
                    break;
                } else {
                    buses.pop();
                }
            }
            if (!found) {
                cout << "Maaf tidak ada bus yang dapat memenuhi keinginan anda\n";
            }
        }
    }
    if (buses.empty()) {
        cout << "Tidak ada bus yang tersisa\n";
    } else {
        cout << "Ada " << buses.size() << " bus yang tersisa yaitu ";
        while (!buses.empty()) {
            Bus bus = buses.top();
            buses.pop();
            cout << bus.id << " ";
        }
    }
    return 0;
}

