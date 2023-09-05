#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<char> s;
    string input;
    cin >> input;

    for (long int i = 0; i < input.size(); i++)
    {
        if (!s.empty() && input[i] == ')' && s.top() == '(')
        {
            s.pop();
        }
        else if (!s.empty() && input[i] == ']' && s.top() == '[')
        {
            s.pop();
        }
        else if (!s.empty() && input[i] == '}' && s.top() == '{')
        {
            s.pop();
        }
        else
            s.push(input[i]);
    }

    if (s.empty())
    {
        cout << "valdi";
    }
    else
        cout << "unvaldi";
}