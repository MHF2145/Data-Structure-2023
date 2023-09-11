#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> apcb;

    for (int i = 0; i < N; i++)
    {
        int M;
        cin >> M;

        if (M == 1) {
            if (apcb.empty()) {
                apcb.push(1);
                apcb.push(0);
            } else if(!apcb.empty()){
                if (apcb.top() == 1 && apcb.size() >= 1) {
                    apcb.pop();
                } else if (!apcb.empty() && apcb.top() == 0 && apcb.size() == 1) {
                    continue;
                } else if (!apcb.empty() && apcb.top() == 0 && apcb.size() > 1) {
                    apcb.pop();
                    apcb.push(1);
                    apcb.push(0);
                    apcb.push(1);
                    apcb.push(0);
            }
        }} else if (M == 0) {
            if (apcb.empty()) {
                apcb.push(0);
            } else if (!apcb.empty() && apcb.top() == 1 && apcb.size() >= 1) {
                apcb.push(0);
            } else if (!apcb.empty() && apcb.top() == 0 && apcb.size() >= 1) {
                apcb.pop();
            }
        }
    }

    cout << apcb.size() << endl;

    return 0;
}
