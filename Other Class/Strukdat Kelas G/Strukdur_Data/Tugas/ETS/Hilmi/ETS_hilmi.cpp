/*
Programmer  : Hilmi Fawwaz Sa'ad
NRP         : 5025221103
Tugas       : Gudang Barang
ETS STRUKDAT*/

#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#define i int
#define c char
#define s string
using namespace std;

typedef struct{
    s nm_brg;
    i jm_brg;
    s tgl_msk;
}gdg;

/*struct gdg
{
    s nm_brg[50];
    i jm_brg;
    s tgl_msk[50];
};*/

//gdg ss;
gdg gdgSu;
deque <gdg> gdgQ;

void tb_brg(){
    cout << "***********************************" << endl;
    cout << "Nama Barang   : ";
    getline(cin, gdgSu.nm_brg);
    cout << "Jumlah Barang : ";
    cin >> gdgSu.jm_brg;
    cin.ignore();
    cout << "Tanggal Masuk : ";
    getline(cin, gdgSu.tgl_msk);
    gdgQ.push_front(gdgSu);
    cout << "Barang Telah Ditambahkan" << endl << endl;
}

void amb_brg(){
    cout << "***********************************" << endl;
}

void ck_brg(){
    //gdgSu gdgSu3;
    cout << "***********************************" << endl;
    if(gdgQ.empty())
    {
        cout << "Maaf, Saat Ini Data Barang Kosong";
    }
    else
    {
        gdg gdgSu = gdgQ.front();
        i o = 1;
        while (!gdgQ.empty())
        {
            cout << "Antrian       : " << o << endl;
            cout << "Nama Barang   : " << gdgSu.nm_brg << endl;
            cout << "Jumlah Barang : " << gdgSu.jm_brg << endl;
            cout << "Tanggal Masuk : " << gdgSu.tgl_msk << endl;
            cout << endl;
            gdgQ.pop_front();
            o++;
        }
    }
}

void hps_klr(){
    cout << "***********************************" << endl;
    while(true){
        if(gdgQ.empty()){
            cout << "Terima Kasih :)" << endl;
            break;
        }
        else
        {
            gdgQ.pop_front();
        }
    }
}

int main(){
    utama:
    cout << "SELAMAT DATANG DI GUDANG BARANG" << endl;
    cout << "=====================================" << endl;
    cout << "Menu :" << endl;
    cout << "1. Memasukkan Barang" << endl;
    cout << "2. Mengeluarkan Barang" << endl;
    cout << "3. Cek Barang" << endl;
    cout << "9. Hapus dan Keluar" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Pilihlah Salah Satu Menu di Atas" << endl;
    cout << "Menu Nomor : ";

    while(true){
        c mn;
        cin >> mn;
        cin.ignore();

        if(mn == '1'){
            tb_brg();
            goto utama;
        }
        else if(mn == '2'){
            return 0;
        }
        else if(mn == '3'){
            ck_brg();
            goto utama;
        }
        else if(mn == '9'){
            hps_klr();
            goto utama;
        }
        else
        {
            cout << "***********************************" << endl;
            cout << "Menu Tidak Tersedia" << endl;
            cout << "Pilih Ulang Menu" << endl;
            goto utama;
        }
    }
}