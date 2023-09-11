#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() 
{
    int t;
    cin >> t;

    map<int, int> tumpukan;

    while (t--) 
	{
        string perintah;
        int vol;

        cin >> perintah >> vol;

        if (perintah == "Taro") 
		{
            tumpukan[vol]++;
        }
        
        else if (perintah == "Ingfo") 
		{
            if (tumpukan[vol] == 0) 
			{
                cout << "No Ingfo" << endl;
            }
            
			else 
			{
                int pos = 1;
                for (auto it = tumpukan.rbegin(); it != tumpukan.rend(); it++) 
				{
                    if (it->first == vol) 
					{
                        cout << "Info manga di tumpukan ke - " << pos << endl;
                        break;
                    }
                    pos += it->second;
                }
            }
        }
        
        else 
		{
            cout << "Gajelas" << endl;
        }
    }

    return 0;
}

