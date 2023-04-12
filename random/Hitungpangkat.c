#include <stdio.h>

int hitung_pangkat(int x,int angka){
    int y;
    y = 0;
    while(angka!=0){
        angka /= x;
        y++;
    }
    return y-1;
}

int main(){
    int angka,x;
    scanf("%d %d",&angka, &x);
    printf("Jadi %d adalah %d pangkat %d",angka,x,hitung_pangkat(x,angka));
    return 0;
}