#include <stdio.h>

int main()
{	
	int T, M, N;
	char R;
	int i, j, k;
	int n;
	int Pcard, Ptruf[N], Lcard, Ltruf[M];
	
	scanf("%d", &T);

	
	for(i = 0; i < 2; i++)
	{
		scanf("%d%d%s", &N, &M, &R);
		for (j = 0; j < N; j++)
		{
			scanf("%d %c", &Pcard, Ptruf[j]);
		}
		
		for (k = 0; k < M; k++)
		{
			scanf("%d %c", &Lcard, Ltruf[j]);
		}
		
		//Output
		for(j = 0; j < N; j ++)
		{
			n = 0;
			if(Ptruf == Ltruf)
			{
				printf("YA");
				n = 1;
				break;
			}
			else continue;
		}
		
		if (n = 0)
		{
			printf("Tidak");
		}
		
	}

	return 3;
}
