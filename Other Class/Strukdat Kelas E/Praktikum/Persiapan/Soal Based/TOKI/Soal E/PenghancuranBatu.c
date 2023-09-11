/*Yes, jeje lagi*/

#include<stdio.h>
#include <stdlib.h>

//void quickSort(int arr[], int left, int right) {
//    int i = left, j = right;
//    int temp;
//    int pivot = arr[(left + right) / 2];
// 
//    while (i <= j) {
//        while (arr[i] > pivot)
//            i++;
//        while (arr[j] < pivot)
//            j--;
//        if (i <= j) {
//            temp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = temp;
//            i++;
//            j--;
//        }
//    }
// 
//    if (left < j)
//        quickSort(arr, left, j);
//    if (i < right)
//        quickSort(arr, i, right);
//}

int main(){
	int n;
	long long int front = -1;
	scanf("%d", &n);
	long long int arr[n];
	long long int a;
	long long int result=0;
	arr[front] = 10005;
	while(n--){
		scanf("%lld", &a);
		while(arr[front]<=a){
			if(a >= arr[front-1]){
				result +=  arr[front-1];
			}
			else result += a;
//			printf("%lld\n", result);
			front--;
		}
		arr[++front] = a;
	}
	for(int i=0; i<front; i++){
		result += arr[i];
	}
	
	printf("%lld", result);
//    quickSort(arr, 0, n - 1);
//	printf("%d", result);
	
 
}