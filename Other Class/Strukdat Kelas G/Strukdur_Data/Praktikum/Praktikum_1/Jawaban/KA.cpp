#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <iomanip>
using namespace std;

int main(){
    int n, p, w, temp = 0;
    float ans;
    vector<int> arr;

    cin >> n >> p >> w;
    
    int m = n;
    
    while(n--){
        int inp;
        cin >> inp;
        arr.push_back(inp);
    }
    
    for(int i = 0; i < m; i++){
        temp += arr[i];
    }
    // cout << temp << endl;
    ans = ((float)temp - (p*w))/60;

    cout << fixed << setprecision(2) << ans << endl;
    // sort(arr.rbegin(), arr.rend());
    return 0;
}