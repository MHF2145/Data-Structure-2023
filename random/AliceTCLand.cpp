#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> arr;
    int t, n;
    cin >> t >> n;
    while (t--)
    {
        string a;
        cin >> a;
        arr.push_back(a);
    }
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr.size(); j++)
        {   
            if(i == j)continue;
            string temp = "";
            temp += arr[i];
            temp += arr[j];
            // cout << temp << endl;
            if(stol(temp) % n == 0)
            {
                count++;
            }
        }
    }
    cout << count;
}