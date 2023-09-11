#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Mergedcase(vector<int>& arr, int k) 
{
    int count = 0;
    
    for (int i = 0; i < arr.size(); i++) 
	{
        string str1 = to_string(arr[i]);
        
        for (int j = 0; j < arr.size(); j++) 
		{
            if (i != j) 
			{
                string str2 = to_string(arr[j]);
                string mergedStr = str1 + str2;
                
                int mergedNum = stoi(mergedStr);
                if (mergedNum % k == 0) 
				{
                    count++;
                }
            }
        }
    }
    
    return count;
}

int main() 
{
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
	{
        cin >> arr[i];
    }
    
    int result = Mergedcase(arr, k);
    cout << result << endl;
    
    return 0;
}

