#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> bt;

    while (n--)                     //memasukkan value ke dalam vector
    {
        int t;
        cin >> t;
        bt.push_back(t);
    }

    int sum;
    cin >> sum;

    sort(bt.begin(), bt.end());     //sort the 2nd line of the input inside the vector
    deque<int> smntr;               //make deque that'll be filled with the amount value that'll be compare with input from the 3rd line
    int calc = 0;
    int status = 0;
    for (int i = 0; i < bt.size(); i++) //while i less than vector size then
    {
        if (smntr.size() == 3)  //size deque=3, calc - front value then pop the front
        {
            calc -= smntr.front();
            smntr.pop_front();
        }

        smntr.push_back(bt[i]); //then push back the i value from the vector to deque
        calc += smntr.back();   //then + the calc value with the back of deque

        if (calc == sum)        //if the calc value is the same as the sum or input of 3rd line, then break it
        {
            status = 1;
            break;
        }
    }
    //the loop still be broken after after executing those command with different result
    if (status == 1)
    {
        cout << "Monggo Lewat...";
    }
    else        //and that's where this else will be activated
    {
        cout << "Wani Piro?";
    }
    return 0;
}
