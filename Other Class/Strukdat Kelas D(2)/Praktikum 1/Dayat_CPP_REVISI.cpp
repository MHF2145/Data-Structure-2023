#include<bits/stdc++.h>
using namespace std;

struct Bis
{
	int ID, R, C;
	Bis(int i, int r, int c)
	{
		ID = i;
		R = r;
		C = c;
	}
	bool operator < (const Bis& other) const
	{
		int rating;
		if (R == other.R)
		{
			return C < other.C;
		}
		
		return R < other.R;
	}
};




int main()
{
	int N, ID, R, C, M;
	int total = 0;
	string act;
	priority_queue <Bis> BDayat;
	
	cin >> N;
	
	while(N--)
	{
		cin >> act;
		if(act == "REGIS")
		{
			cin >> ID >> R >> C;
			BDayat.push({ID, R, C});
			total += C;
		}
		
		else
		{
			cin >> M;
			if(M > total)
			{
				cout << "Maaf tidak ada bus yang dapat memenuhi keinginan anda" << endl;
			}
			
			else 
			{
				while(M > 0) //Masukin data bis ke queue utk pelanggan
				{
					
					Bis b = BDayat.top();
					M -= b.C;
					total -= b.C;
					cout << b.ID << " ";
					BDayat.pop();
				}0
				cout << "telah berhasil disewa" << endl;
			}
		}
	}
	
	if(BDayat.empty())
	{
		cout << "Tidak ada bus yang tersisa" << endl;
	}
	
	else 
	{
		cout << "Ada " << BDayat.size() << " bus yang tersisa yaitu ";
		while(!BDayat.empty())
		{
			Bis b = BDayat.top();
			cout << b.ID << " ";
			BDayat.pop();
		}
	}
	
	 return 0;
}
