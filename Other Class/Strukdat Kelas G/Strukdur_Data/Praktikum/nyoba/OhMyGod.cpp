#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main()
{
    int t, count = 0;
    cin >> t;
    stack<string> data;
    while (t--)
    {
        char temp[10];
        scanf("\n%[^\n]%*c", temp);
        data.push(temp);
        if (temp[0] == 'C')
            count++;
    }

    int n;
    cin >> n;
    while (n--)
    {
        char opr[15];
        scanf("\n%[^\n]%*c", opr);
        cout << data.top() << endl;
        if (opr[0] == 'O')
        {
            if (data.top() == "Clue")
            {
                puts("I'm going crazy, right?");
            }
            data.pop();
        }

        else
        {
            if (count >= 5)
                puts("He's the one that's living in my system");
            else
                puts("Who is he?");
        }
    }
}