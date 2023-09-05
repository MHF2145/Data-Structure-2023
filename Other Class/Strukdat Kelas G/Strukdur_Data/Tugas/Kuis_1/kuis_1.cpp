#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
using namespace std;

queue<string> nama, alamat, keluhan;
queue<int> usia;

void tambah()
{
    string inpn, inpa, inpk;
    int inpu;
    cout << "masukkan nama:\n";
    getline(cin, inpn);
    nama.push(inpn);
    cout << "masukkan usia:\n";
    cin >> inpu;
    cin.ignore();
    usia.push(inpu);
    cout << "masukkan alamat:\n";
    getline(cin, inpa);
    alamat.push(inpa);
    cout << "masukkan keluhan:\n";
    getline(cin, inpk);
    keluhan.push(inpk);
}

void masuk()
{

    if (nama.empty())
    {
        cout << "Tidak ada pasien yang masuk ke dokter.\n";
    }
    else
    {
        cout << "pasien yang masuk ke dokter:\n";
        cout << "Nama: " << nama.front() << "\n";
        nama.pop();
        cout << "Usia: " << usia.front() << "\n";
        usia.pop();
        cout << "Alamat: " << alamat.front() << "\n";
        alamat.pop();
        cout << "Keluhan: " << keluhan.front() << "\n";
        keluhan.pop();
    }
}

void tampilkan()
{
    deque<string> nama_temp, alamat_temp, keluhan_temp;
    deque<int> usia_temp;
    string satu_temp, tiga_temp, empat_temp;
    int dua_temp;
    int a = 1;
    if (nama.empty())
    {
        cout << "Tidak ada antrian di puskesmas.\n";
    }
    else
    {
        cout << "Daftar pasien yang masih dalam antrian:\n";
    }

    while (!nama.empty())
    {
        satu_temp = nama.front();
        nama_temp.push_back(satu_temp);
        dua_temp = usia.front();
        usia_temp.push_back(dua_temp);
        tiga_temp = alamat.front();
        alamat_temp.push_back(tiga_temp);
        empat_temp = keluhan.front();
        keluhan_temp.push_back(empat_temp);

        cout << a << "\n";
        a++;
        cout << "Nama: " << nama.front() << "\n";
        nama.pop();
        cout << "Usia: " << usia.front() << "\n";
        usia.pop();
        cout << "Alamat: " << alamat.front() << "\n";
        alamat.pop();
        cout << "Keluhan: " << keluhan.front() << "\n";
        keluhan.pop();
    }

    while (!nama_temp.empty())
    {
        satu_temp = nama_temp.front();
        nama.push(satu_temp);
        nama_temp.pop_front();
        dua_temp = usia_temp.front();
        usia.push(dua_temp);
        usia_temp.pop_front();
        tiga_temp = alamat_temp.front();
        alamat.push(tiga_temp);
        alamat_temp.pop_front();
        empat_temp = keluhan_temp.front();
        keluhan.push(empat_temp);
        keluhan_temp.pop_front();
    }
}

int main()
{
    bool keluar = 0;
    while (!keluar)
    {

        int t;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Pilih menu:\n";
        cout << "1. Tambah pasien baru\n";
        cout << "2. Pasien masuk ke dokter\n";
        cout << "3. Lihat daftar antrian\n";
        cout << "9. Keluar\n";
        cin >> t;
        cin.ignore();
        if (t == 1)
        {
            tambah();
        }
        else if (t == 2)
        {
            masuk();
        }
        else if (t == 3)
        {
            tampilkan();
        }
        else if (t == 9)
        {
            keluar = 1;
            while (!nama.empty())
            {
                nama.pop();
                usia.pop();
                alamat.pop();
                keluhan.pop();
            }
        }
        else
        {
            cout << "input tidak ada pada menu\n";
        }
    }
    return 0;
}