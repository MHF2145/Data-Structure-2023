#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
	int dd, mm, yy;
}date;

int dcmp(date d1, date d2)
{
	if(d1.dd == d2.dd && d1.mm == d2.mm && d1.yy == d2.yy) return 0;
	else if((d1.yy > d2.yy) ||
			(d1.yy == d2.yy && d1.mm > d2.mm) ||
			(d1.yy == d2.yy && d1.mm == d2.mm && d1.dd > d2.dd)) return 1;
	else return -1;
}

int main()
{
	date d1, d2;
	scanf("%d %d %d", &d1.dd, &d1.mm, &d1.yy);
	scanf("%d %d %d", &d2.dd, &d2.mm, &d2.yy);
	
	printf("%d\n", dcmp(d1, d2));
	
	return 0;
}