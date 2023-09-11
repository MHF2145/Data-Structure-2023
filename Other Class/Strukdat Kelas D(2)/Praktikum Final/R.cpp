#include <iostream>
#include <vector>

using namespace std;

vector<int> addLists(const vector<int>& list1, const vector<int>& list2) 
{
    int m = list1.size();
    int n = list2.size();
    int carry = 0;
    vector<int> result(max(m, n));

    int i = m - 1;
    int j = n - 1;
    int k = result.size() - 1;

    while (i >= 0 || j >= 0) 
	{
        int sum = carry;

        if (i >= 0) 
		{
            sum += list1[i];
            i--;
        }

        if (j >= 0) 
		{
            sum += list2[j];
            j--;
        }

        result[k] = sum % 10;
        carry = sum / 10;
        k--;
    }

    if (carry > 0) 
	{
        result.insert(result.begin(), carry);
    }

    return result;
}

int main() 
{
    int m, n;
    cin >> m >> n;

    vector<int> list1(m);
    for (int i = 0; i < m; i++) 
	{
        cin >> list1[i];
    }

    vector<int> list2(n);
    for (int i = 0; i < n; i++) 
	{
        cin >> list2[i];
    }

    vector<int> result = addLists(list1, list2);

    for (int digit : result) 
	{
        cout << digit;
    }
    cout << endl;

    return 0;
}

