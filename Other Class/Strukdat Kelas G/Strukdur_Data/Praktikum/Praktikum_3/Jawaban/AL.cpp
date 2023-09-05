#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <functional>
using namespace std;


int main()
{
    int a, b, c;
    map <int, int, std::less<>> pelari;
    
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> b >> c;
        pelari[b] = c;
    }
    for (int j = 0; j < a; j++)
    {
        cin >> b >> c;
        pelari[b] += c;
    }
    int d, e = 0;
    for (auto t: pelari)
    {
        cout << t.first << " " << t.second << endl;
        if (t.second > e)
        {
            d = t.first;
            e = t.second;
        }
        
    }
    cout << "Tim " << d << " merupakan pemenangnya dengan skor: " << e;
}