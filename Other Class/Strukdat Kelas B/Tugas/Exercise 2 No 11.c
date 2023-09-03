#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char name[101];
	float net;
}stall;

void swap(stall *a, stall *b)
{
    stall temp = *a;
    *a = *b;
    *b = temp;
}

int partition(stall arr[], int left, int right)
{
    stall pivot = arr[right];
    int i = left;
 	int j;
    for(j = left; j < right; j++)
    {
        if(arr[j].net > pivot.net)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
        else if(arr[j].net == pivot.net && strcmp(arr[j].name, pivot.name) < 0)
        {   
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[right]);
 
    return i;
}
 
void sort(stall arr[], int left, int right)
{
    if(left < right)
    {
        int pivot = partition(arr, left, right);
 
        sort(arr, left, pivot - 1);
        sort(arr, pivot + 1, right);
    }
}


int main()
{
	stall arr[10001];
	char temp[101];
	float in, ex, sum = 0;
	int n = 0;
	
	while(1)
	{
		scanf("%s", temp);
		if(strcmp(temp, "END") == 0) break;
		
		scanf("%f %f", &in, &ex);
		arr[n].net = in - ex;
		strcpy(arr[n].name, temp);
		sum += arr[n].net;
		n++;
	}
	
	sort(arr, 0, n - 1);
	
	printf("\nList of stall name and net income :\n");
	for(int j = 0; j < n; j++) printf("%s %.2f\n", arr[j].name, arr[j].net);
	
	printf("\nNumber of stalls : %d\n", n);
	(sum >= 0) ? printf("Profit : %.2f\n", sum) : printf("Loss : %.2f\n", sum * -1);
	
	printf("\nMost profitable stall(s):\n%s %.2f\n", arr[0].name, arr[0].net);
	for(int j = 1; arr[j].net == arr[j - 1].net; j++) printf("%s %.2f\n", arr[j].name, arr[j].net);
	
	return 0;
}