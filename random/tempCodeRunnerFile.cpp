#include <iostream>
using namespace std;

int main()
{
    int t = 10;
    while (t--)
    {
        int s = 0;
        long long count = 0;
        int a;
        string str;
        cin >> a >> str;
        for (int i = 0; i < a; i++)
        {
            if (str[i] == 'S')
            {
                s++;
                count += 2;
            }
            else if (str[i - 1] == 'S')
            {
                count--;
            }
        }
        if (s % 2 == 0 && s != 0)
            count++;
        cout << count << endl;
    }
}
