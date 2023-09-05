#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct dir
{
    string nama;
    vector<dir*> link;
};

struct dir *alamat(string isi)
{
    struct dir *buatbaru = new dir;
    buatbaru->nama = isi;
    return buatbaru;
}

vector<string> mecah(string pecah)
{
    string temp = "";
    vector<string> alur;
    for (int i = 0; i < (int)pecah.size(); i++)
    {
        if (pecah[i] == '/')
        {
            alur.push_back(temp);
            temp = "";
        }
        else
        {
            temp += pecah[i];
        }
    }
    return alur;
}

void masukan(struct dir *asal, vector<string> masuk)
{
    struct dir *temp = asal;
    for (int k = 0; k < masuk.size(); k++)
    {
        bool cek = 0;
        for (int j = 0; j < temp->link.size(); j++)
        {
            if (temp->link[j]->nama == masuk[k])
            {
                temp = temp->link[j];
                cek = 1;
                break;
            }
        }
        if (cek == 0)
        {
            dir *baru = alamat(masuk[k]);
            temp->link.push_back(baru);
            temp = baru;
        }
    }
    // cout << "berhasil" << endl;
}

void keluarkan(dir *asal, vector<string> keluar)
{
    struct dir *temp = asal;
    for (int i = 0; i < keluar.size(); i++)
    {
        bool check = 0;
        for (int j = 0; j < temp->link.size(); j++)
        {
            if (temp->link[j]->nama == keluar[i])
            {
                temp = temp->link[j];
                check = 1;
                break;
            }
        }
        if (check == 0)
        {
            cout << "ls: " << keluar[i] << ": " << "No such file or directory" << endl;
            return;
        }
    }
    for (int i = 0; i < temp->link.size(); i++)
    {

        cout << temp->link[i]->nama << " ";
    }
    cout << endl;
    // cout << "berhasil 2" << endl;
}

int main()
{
    struct dir *asal = alamat("");
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s, inp = "";
        getline(cin, s);
        int i;
        for (i = 0; i < (int)s.size(); i++)
        {
            if (s[i] == ' ')
                break;
            else
                inp += s[i];
        }
        if (inp == "mkdir")
        {
            string inp2 = "";
            for (i++; i < (int)s.size(); i++)
            {
                if (s[i] == ' ')
                    break;
                else
                    inp2 += s[i];
            }
            if (inp2 == "-p")
                masukan(asal, mecah(s.substr(i + 1)));
            else
                cout << "command not found: " << inp << " " << inp2 << endl;
        }
        else if (inp == "ls")
            keluarkan(asal, mecah(s.substr(i + 1)));
        else
            cout << "command not found: " << inp << endl;
    }

    return 0;
}