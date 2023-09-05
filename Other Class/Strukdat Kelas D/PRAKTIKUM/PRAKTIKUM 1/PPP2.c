#include <stdio.h>
#include <stdlib.h>

int cariMin(int *arr, int start, int end){
    int minValue = arr[start];
    for(int i = start+1; i<= end; i++){
        if(arr[i] < minValue){
            minValue = arr[i];
        }
    }
    return minValue;
}

int main(){
    int m,n;
    scanf("%d %d", &n, &m);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i<n;i++){
        scanf("%d", &arr[i]);
    }
    int *minValue = (int *)malloc((n+m-1) * sizeof(int));
    for(int i = 0; i<=n-m; i++){
        minValue[i] = cariMin(arr, i, i+m-1);
    }
    for(int i = 0; i<=n-m; i++){
        printf("%d\n", minValue[i]);
    }
    free(arr);
    free(minValue);
}