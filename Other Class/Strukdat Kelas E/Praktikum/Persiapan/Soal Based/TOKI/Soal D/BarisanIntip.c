/*U guess it right, dari jeje*/

#include <stdio.h>
#include <stdlib.h>

int front = -1;
int stack[100005];

void push(int p){
	front++;
	stack[front] = p;
}

int main(){
	int jml;
	int barisan[100005];
	long int result=0;
	int tinggi;
	scanf("%d", &jml);
	for(int i=jml-1; i>=0; i--){
		scanf("%d", &tinggi);
		barisan[i] = tinggi;
	}	
	
	for(int i=0; i<jml; i++){	
	result++;
		if(front == -1){
			push(barisan[i]);
		}
		
		else if(stack[front] >= barisan[i]){
			result += front+1;	
			push(barisan[i]);
		}
		
		else if(stack[front] < barisan[i]){
			while(front!= -1 && stack[front] < barisan[i]){
				front--;
				}
			result += front+1;
			push(barisan[i]);
			}
		}
		
		printf("%ld\n", result);
		return 0;
	
	}