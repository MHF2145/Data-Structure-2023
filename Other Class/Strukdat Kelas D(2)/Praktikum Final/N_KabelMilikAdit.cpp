#include <bits/stdc++.h> 
using namespace std;

void PenggerakKabel(int N) 
{
    stack<int> Stack;
    
    for (int i = 0; i < N; i++) 
	{
        int order;
        cin >> order;

        if (order == 1) 
		{
            if (Stack.empty()) 
			{
                Stack.push(1);
                Stack.push(0);
            } 
			
			else if (Stack.top() == 1 && Stack.size() == 1) 
			{
                Stack.pop();
            } 
			
			else if (Stack.top() == 1 && Stack.size() > 1) 
			{
                Stack.pop();
            } 
			
			else if (Stack.top() == 0 && Stack.size() > 1) 
			{
                Stack.pop();
                Stack.push(1);
                Stack.push(0);
                Stack.push(1);
                Stack.push(0);
            }
        } 
		
		else 
		{
            if (Stack.empty()) 
			{
                Stack.push(0);
            } 
			
			else if (Stack.size() == 1 && Stack.top() == 1) 
			{
                Stack.push(0);
            } 
			
			else if (Stack.size() == 1 && Stack.top() == 0) 
			{
                Stack.pop();
            } 
			
			else if (Stack.size() > 1 && Stack.top() == 1) 
			{
                Stack.push(0);
            } 
			
			else 
			{
                Stack.pop();
            }
        }
    }

    cout << Stack.size();
}

int main() 
{
    int N;
    cin >> N;
    
    PenggerakKabel(N);

    return 0;
}
