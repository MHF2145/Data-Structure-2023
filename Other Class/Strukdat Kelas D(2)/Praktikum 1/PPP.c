#include <stdio.h>

int main()
{
	int N, M, i, j, k;
	int pasukan[N];
	int min, penentu;
	
	scanf("%d %d", &N, &M);
	for(i = 0; i < N; i++)
	{
		scanf("%d", &pasukan[i]);
	}
	
	for(j = 0; j < (N - M + 1); j++)
	{
		penentu = 0;
		min = pasukan[penentu];
		for(k = 0; k < M; k ++)
		{
			if(pasukan[k] < min)
			{
				min = pasukan[i];
			}
			penentu++;
		}
		printf("%d", min);
	}
	printf("%d", min);
	return 0;
}
