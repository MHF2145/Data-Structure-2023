#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> watchlist;

    int x, y, n;
    cin >> x >> y >> n;
    for (int i = 0; i < x; i++) {
        int z;
        cin >> z;
        watchlist.push_back(z);
    }

    if (x <= n) {
        cout << "Kasian Ersya\n";
        return 0;
    }

    for (int i = 0; i < n; i++){
        watchlist.pop_front();
        int m = y;
        if (!watchlist.empty() && y >= watchlist.size()) m %= watchlist.size();
        for (int j = 0; j < m; j++){
            watchlist.push_back(watchlist.front());
            watchlist.pop_front();
        }
    }

    cout << watchlist.front() << endl;

    return 0;
}