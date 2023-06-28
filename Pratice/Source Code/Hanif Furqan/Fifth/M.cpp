#include <bits/stdc++.h>

bool breketsdhbelens(std::string expr);

int main()
{
    std::string expr;
    std::cin >> expr;

    if (breketsdhbelens(expr))
        std::cout << "valdi" << std::endl;
    else
        std::cout << "unvaldi" << std::endl;

    return 0;
}

bool breketsdhbelens(std::string expr)
{
    std::stack<char> s;
    char x;

    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            s.push(expr[i]);
            continue;
        }

        if (s.empty())
            return false;

        switch (expr[i])
        {
            case ')':
                x = s.top();
                s.pop();
                if (x != '(')
                    return false;
                break;

            case '}':
                x = s.top();
                s.pop();
                if (x != '{')
                    return false;
                break;

            case ']':
                x = s.top();
                s.pop();
                if (x != '[')
                    return false;
                break;
        }
    }

    return s.empty();
}
