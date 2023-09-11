#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int N, M;
    cin >> N >> M; 

    deque<int> DQ; 
    priority_queue<pair<int, int>, vector<pair<int, int > >, greater<pair<int, int> > > PQ; //Template Priority queue

    for (int i = 0; i < N; i++) 
	{
        int x;
        cin >> x;
        DQ.push_back(x);
        PQ.push({x, i});

        if (i >= (M-1)) 
		{
            while (!PQ.empty() && PQ.top().second <= (i - M)) 
			{
                PQ.pop();
            }
            cout << PQ.top().first << endl;
            DQ.pop_front();
        }
    }

    return 0;
}
