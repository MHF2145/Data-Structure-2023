#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    do{
        int t;
        queue<int> kartu;
        scanf("%d", &n);
        if(n==0){break;}

        else if(n > 0){
            for(int i=1; i <= n; i++){
                kartu.push(i);
            }

            printf("Discarded cards:");
            while(kartu.size()>1){
                printf(" %d", kartu.front());
                kartu.pop();
                t = kartu.front();
                kartu.pop();
                if(!kartu.empty()){
                    printf(",");
                }
                kartu.push(t);
            }
            printf("\nRemaining card: %d\n", kartu.front());
            kartu.pop();
        }

        else{printf("Mana ada kartu minus!"); break;}

    }while(n>0);
    return 0;
}