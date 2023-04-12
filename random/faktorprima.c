#include <stdio.h>
#include <math.h>

void generatorPrima(int x,int y){
    int c;
    for (int i=x;i<=y;i++){
			c = 0;
			if (i==1) c=2;
			for (int j=2;j<=sqrt(i);j++){
				if (i%j==0){
				c=2;
				break;
				}
			}
			if (c==0) {
			printf ("%d\n", i);
			}	
		}
}

int main(){
    int batas_bawah,batas_atas;
    scanf("%d %d",&batas_bawah,&batas_atas);
    generatorPrima(batas_bawah,batas_atas);
    return 0;
}