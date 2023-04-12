#include <stdio.h>

int faktorial(int x){
    int hasil = 1;
    while (x != -1) {
        if (x==0){
            hasil *=1;
            break;
        }
        else hasil *= x--;
    }
    return hasil;
}

int main(){
    int x;
    scanf("%d",&x);
    int hasilfaktorial = faktorial(x);
    printf("%d",hasilfaktorial);
return 0;
}