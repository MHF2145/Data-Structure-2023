#include <iostream>
#include <map>
#include <string>
using namespace std;

struct Prajurit // truct untuk menyimpan data prajurit
{
    int usia;
    string asal;
};

int main() 
{
    int n, q;
    cin >> n;
    
    map<string, Prajurit> data;
    for (int i = 0; i < n; i++) 
	{
        string nama;
        Prajurit prajurit;
        string temp;
        cin >> temp >> nama >> temp >> prajurit.usia >> temp >> prajurit.asal;
        data[nama] = prajurit;
    }
    
    cin >> q;
    for (int i = 0; i < q; i++) 
	{
        string nama;
        cin >> nama;
        Prajurit prajurit = data[nama];
        cout << "Usia: " << prajurit.usia << endl;
        cout << "Asal: " << prajurit.asal << endl;
    }
    return 0;
}

