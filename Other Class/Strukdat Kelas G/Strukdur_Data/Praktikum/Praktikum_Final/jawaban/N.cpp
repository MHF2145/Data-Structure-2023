#include <iostream>
#include <stack>
using namespace std;

stack<int> simpanan;
void ngitung(int test);

int main()
{
    int test;
    cin >> test;
    ngitung(test);

    cout << simpanan.size() << endl;
}

void ngitung(int test)
{

    while (test--)
    {
        int inp, atas;
        cin >> inp;

        if (!inp)
        {
            if (simpanan.empty())
            {
                simpanan.push(0);
                continue;
            }

            atas = simpanan.top();

            if (simpanan.size() == 1 && atas == 1)
            {
                simpanan.push(0);
            }

            else if (simpanan.size() == 1 && atas == 0)
            {
                simpanan.pop();
            }

            else if (simpanan.size() > 1)
            {
                if (atas == 1)
                {
                    simpanan.push(0);
                }

                else if (atas == 0)
                {
                    simpanan.pop();
                }
            }
        }

        if (inp)
        {
            if (simpanan.empty())
            {
                simpanan.push(1);
                simpanan.push(0);
                continue;
            }
            atas = simpanan.top();
            if (simpanan.size() == 1 && atas == 1)
            {
                simpanan.pop();
            }

            else if (simpanan.size() > 1)
            {
                if (atas == 1)
                {
                    simpanan.pop();
                }

                else if (atas == 0)
                {
                    simpanan.pop();
                    simpanan.push(1);
                    simpanan.push(0);
                    simpanan.push(1);
                    simpanan.push(0);
                }
            }
        }
    }
}
