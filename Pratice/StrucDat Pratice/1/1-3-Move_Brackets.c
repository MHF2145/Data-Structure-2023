#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main() 
{
	int t;
	
	scanf("%d", &t);
	
	while(t--) 
	{
		int n;
		char str[101];
		
		scanf("%d", &n);
		scanf("%s", str);
		
		int ans = 0, open = 0, close = 0;
		
		for(int i = 0; i < n; i++) 
		{
			if(str[i] == '(' && str[i + 1] == ')')
			{
				i++;
				continue;
			}
			if(str[i] == '(') open++;
			if(str[i] == ')')
			{
				close++;
				if(open < close)
				{
					ans++;
					close--;
				}
			}
		}
		printf("%d\n", ans);		
	}
}