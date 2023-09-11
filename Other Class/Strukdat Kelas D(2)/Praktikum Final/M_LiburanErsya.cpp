#include <iostream>

using namespace std;

bool areBracketsBalanced(string s) 
{
		int i=-1;
		for(auto& ch:s)
		{
			if(ch=='(' || ch=='{' || ch=='[')
				{
					s[++i]=ch;	
				}
			else
			{
				if(i>=0 && ((s[i]=='(' && ch==')') || (s[i]=='{' && ch=='}') || (s[i]=='[' && ch==']')))
				{
					i--;	
				}
				else
					return false;
			}
		}
		return i==-1;
	}

int main()
{
	string s;
    cin >> s;

	if (areBracketsBalanced(s))
		cout << "valdi";
	else
		cout << "unvaldi";
	return 0;
}

