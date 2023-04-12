#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    do{
    deque<int> sampah,dq;
    cin>>a;
    if(a==0)
    {
        break;
    }else if(a>0)
    {
    for(int i=1;i<=a;i++)dq.push_back(i);
    while(dq.size()!= 1)
    {
        sampah.push_back(dq.front());
        dq.pop_front();
        dq.push_back(dq.front());
        dq.pop_front();
    }
    cout<<"Discarded cards: ";
    while(sampah.size()>=1)
    {
        cout<<sampah.front();
        sampah.pop_front();
        if(!sampah.empty())cout<<", ";
    }    
        cout<<endl;
        cout<<"Remaining card: "<<dq.front()<<endl;
    }else
    {
        cout<<"Mana ada kartu minus!";
        break;
    }
    }while(a>0);
    return 0;
}