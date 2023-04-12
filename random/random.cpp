#include <iostream>
#include <string>
using namespace std;


int main()
{
    cout << "Jadi gini"<< endl;
    const int MAX = 5;
    string arrayBuku[MAX] = {"Qiqi", "Suka", "yang", "besar", "banget"};
    for (int i = 0; i < MAX; i++)
    {
        cout << arrayBuku[i] << endl;;
    }
}