#include <iostream>
#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    do
    {
        int y;
        queue<int> card;   //bikin queu card
        scanf("%d", &x);    //input jumlah card
        if(x == 0)            //kalau 0 lgsg berhenti
        {
            break;
        }

        else if(x > 0)
        {
            for(int i = 1; i <= x; i++)   //card dimasukkan kedalam queu sampai memenuhi jumlah
            {
                card.push(i);
            }

            printf("Discarded cards:");

            while(card.size() > 1)       //selama queu card masih lebih dari 1
            {
                printf(" %d", card.front());   //diprint yang paling depan 
                card.pop();                    //lalu dibuang
                y = card.front();              //inisiasi untuk membuat card slenajutnya menjadi front
                card.pop();
                if(!card.empty())              //mengecek queu tadi jika empty maka cetak ","
                {
                    printf(",");
                }
                card.push(y);                  //lalu mengepush antrian selanjutnya ke depan
            }
            printf("\nRemaining card: %d\n", card.front());    //lalu disini mengeperint sisa card
            card.pop();
        }

        else
        {
            printf("Mana ada card minus!"); break;
        }

    }
    while(x > 0);
    return 0;
}

int main()
{
    std::cout << "Hello World" << std::endl;
}