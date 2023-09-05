#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    stack<int> st;
    cin >> t;

    while (t--)
    {
        int opr;
        cin >> opr;
        if (opr == 1)
        {
            if (st.empty())
            {
                st.push(1);
                st.push(0);
                continue;
            }
            int top = st.top();
            if (st.size() == 1 && top == 1)
            {
                st.pop();
            }
            else if (st.size() > 1)
            {
                if (top == 1)
                {
                    st.pop();
                }
                else if (top == 0)
                {
                    st.pop();
                    st.push(1);
                    st.push(0);
                    st.push(1);
                    st.push(0);
                }
            }
        }
        if (opr == 0)
        {
            if (st.empty())
            {
                st.push(0);
                continue;
            }
            int top = st.top();
            if (st.size() == 1 && top == 1)
            {
                st.push(0);
            }
            else if (st.size() == 1 && top == 0)
            {
                st.pop();
            }
            else if (st.size() > 1)
            {
                if (top == 1)
                {
                    st.push(0);
                }
                else if (top == 0)
                {
                    st.pop();
                }
            }
        }
    }
    cout << st.size() << endl;
    while (!st.empty())
    {
        {
            st.pop();
        }
    }

    return 0;
}
