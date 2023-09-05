#include <iostream>
using namespace std;

long int catalan(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    long int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += catalan(i) * catalan(n - i - 1);
    }
    return result;
}

int main()
{
    int a;
    cin >> a;
    while (a--)
    {
        int b;
        cin >> b;
        cout << catalan(b) << endl;
    }
    return 0;
}