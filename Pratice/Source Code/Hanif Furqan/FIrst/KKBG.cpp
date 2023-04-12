#include<bits/stdc++.h>
using namespace std;

int main()
{
    int card;
    do
    {
        deque<int> buang, dq; //buat deque
        cin >> card;   //input jumlah card
        if(card == 0)    //kalau 0 lgsg berhenti
        {
            break;
        }
        else if(card > 0)
        {
            for(int i = 1;i <= card; i++)
                dq.push_back(i);                            //card dimasukkan kedalam deque sampai memenuhi jumlah
            while(dq.size() != 1)                           //selama deque card masih lebih dari 1
            {
                buang.push_back(dq.front());                //ngebuang paling depan(dimasukin deque buang
                dq.pop_front();                             //keluarin depan
                dq.push_back(dq.front());                   //masukin yang depan baru ke belakang
                dq.pop_front();                             //keluarin lagi yang depan
            }
            cout<<"Discarded cards: ";
            while(buang.size() >= 1)                        //selama yang deque buang lebih dari satu
            {
                cout << buang.front();                      //print isi deque
                buang.pop_front();                          // lalu di pop biar ga ngulang
                if(!buang.empty())cout << ", ";
            }
                cout << endl;
                cout << "Remaining card: " <<dq.front()<<endl;  //lalu ngeprint dari sisa dq awal tadi
        }
        else
        {
            cout << "Mana ada kartu minus!";
            break;
        }

    }
    while(card > 0);

    return 0;
}