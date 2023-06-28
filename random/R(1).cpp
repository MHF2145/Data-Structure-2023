#include <iostream>
#include <list>
#include <math.h>

using namespace std;

int convertListToNum(list<int> ls) {
    int num = 0, i = 0;
    ls.reverse();
    for (auto &it : ls) {
        num += it * pow(10, i);
        i++;
    }
    return num;
}

int main() {
    int m, n;
    list<int> list1, list2;

    cin >> m >> n;
    while (m--) {
        int num1;
        cin >> num1;
        list1.push_back(num1);
    }
    while (n--) {
        int num2;
        cin >> num2;
        list2.push_back(num2);
    }

    int num1 = convertListToNum(list1);
    int num2 = convertListToNum(list2);

    cout << num1 + num2 << endl;
    

    return 0;
}