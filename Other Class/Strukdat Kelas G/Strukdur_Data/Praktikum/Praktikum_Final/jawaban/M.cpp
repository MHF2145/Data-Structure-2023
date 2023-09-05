#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

bool check(const string &inp)
{
    stack<char> test;

    for (char c : inp)
    {
        if (c == '{' || c == '[' || c == '(')
        {
            test.push(c);
        }
        else if (c == '}' || c == ']' || c == ')')
        {
            if (test.empty())
            {
                return false;
            }

            char atas = test.top();
            test.pop();

            if ((c == '}' && atas != '{') || (c == ']' && atas != '[') || (c == ')' && atas != '('))
            {
                return false;
            }
        }
    }

    return test.empty();
}

int main()
{
    string inp;
    getline(cin, inp);

    if (check(inp))
    {
        cout << "valdi" << endl;
    }
    else
    {
        cout << "unvaldi" << endl;
    }
    return 0;
}