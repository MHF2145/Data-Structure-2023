#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> arr;
	int x, y, n;
	int i;
	cin >> x>> y>> n;
	
	while(x--)
	{
		int anime;
		cin>> anime;
		arr.push_back(anime);
	}
	
	while(n--)
	{
		arr.pop_front();
		arr.empty();
		if(arr.empty())
		{
			cout << "Kasian Ersya" << endl;
			return 0;	
		} 
		
		for(i = 0; i < y; i++)
		{
			int temp = arr.front();
			arr.pop_front();
			arr.push_back(temp);
		}
	}
	
	if(arr.empty()) 
	{
		cout << "Kasian Ersya" << endl;
	}
	else
	{
		cout << arr.front() << endl;
	}
}

