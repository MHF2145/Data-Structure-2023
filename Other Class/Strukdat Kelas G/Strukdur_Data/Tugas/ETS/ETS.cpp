#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Barang
{
    string jenis_barang, tanggal_masuk;
    int jumlah_barang;
};

struct Total
{
    string jns_barang;
    int ttl_barang;
};

typedef struct Barang barang;
typedef struct Total total;
vector<barang> urutan_barang;
vector<total> total_barang;

void barang_masuk()
{
    barang temp;
    total temp2;
    string a, c;
    int b, find;
    bool cek = false;
    cout << "Masukkan jenis barang:"
         << "\n";
    getline(cin, a);
    temp.jenis_barang = a;
    temp2.jns_barang = a;
    cout << "Masukkan jumlah barang:"
         << "\n";
    cin >> b;
    cin.ignore();
    temp.jumlah_barang = b;
    temp2.ttl_barang = b;
    cout << "Masukkan tanggal masuk barang:"
         << "\n";
    getline(cin, c);
    temp.tanggal_masuk = c;
    for (int i = 0; i < (int)urutan_barang.size(); i++)
    {
        if (total_barang[i].jns_barang == a)
        {
            total_barang[i].ttl_barang += b;
            cek = true;
            break;
        }
    }
    if (!cek)
    {
        total_barang.push_back(temp2);
    }

    urutan_barang.push_back(temp);

    printf("\n");
}

void barang_keluar()
{
    int temp, jml_barang;
    int cek = 0;
    string nama_barang;
    queue<barang> output;
    cout << "Jenis barang yang ingin dikeluarkan: "
         << "\n";
    getline(cin, nama_barang);
    cout << "Jumlah barang yang ingin dikeluarkan: "
         << "\n";
    cin >> jml_barang;
    cin.ignore();

    for (int j = 0; j < (int)total_barang.size(); j++)
    {
        if (nama_barang == total_barang[j].jns_barang && jml_barang <= total_barang[j].ttl_barang)
        {
            total_barang[j].ttl_barang -= jml_barang;
            cout << "Dari Gudang Barang diambil jenis barang yaitu " << nama_barang << " sebanyak: " << jml_barang << "\n";
            cout << "Jumlah jenis barang " << nama_barang << " yang tersisa dalam Gudang Barang sebanyak: " << total_barang[j].ttl_barang << "\n";
            cout << "\n";
            cek = 1;
            break;
        }
        if (nama_barang == total_barang[j].jns_barang && jml_barang > total_barang[j].ttl_barang)
        {

            cout << "Jumlah barang yang anda ingin keluarkan terlalu banyak dibandingkan jumlah barang yang ada pada gudang" << endl;
            cout << "Sisa barang yang anda cari adalah " << total_barang[j].ttl_barang << ", silahkan menambah jenis barang terlebih dahulu dengan mengetik menu 1 atau keluarkan jumlah barang yang kurang dari/sama dengan jumlah barang yang tersedia" << endl;
            cout << "\n";
            return;
        }
    }
    if (cek == 0)
    {
        cout << "Jenis barang yang anda cari tidak terdapat di dalam Gudang Barang" << endl;
        return;
    }

    /* Pada Line 106-135 mencoba untuk mengeluarkan barang beserta tanggal dimasukkannya barang */
    cout << "Dengan rincian sebagai berikut:"
         << "\n";
    int urutan = 1, b = jml_barang;
    queue<int> a;
    cout << "Barang dari jenis " << nama_barang << endl;
    for (int i = 0; i < (int)urutan_barang.size(); i++)
    {
        if (nama_barang == urutan_barang[i].jenis_barang && urutan_barang[i].jumlah_barang - b >= 0 && b > 0)
        {
            urutan_barang[i].jumlah_barang -= b;
            a.push(b);
            b -= jml_barang;
            output.push(urutan_barang[i]);
        }
        else if (nama_barang == urutan_barang[i].jenis_barang && urutan_barang[i].jumlah_barang - b < 0 && urutan_barang[i].jumlah_barang > 0)
        {
            b -= urutan_barang[i].jumlah_barang;
            a.push(urutan_barang[i].jumlah_barang);
            urutan_barang[i].jumlah_barang -= jml_barang;
            output.push(urutan_barang[i]);
        }
    }

    for (int i = 0; i <= (int)output.size(); i++)
    {
        cout << urutan << ". Sejumlah " << a.front() << " dari tanggal masuk barang yaitu " << output.front().tanggal_masuk << endl;
        urutan++;
        a.pop();
        output.pop();
    }
    printf("\n");
}

void barang_tampilkan()
{
    int cek = 0;
    for (int i = 0; i < (int)total_barang.size(); i++)
    {
        if (total_barang[i].ttl_barang > 0)
        {
            cout << "Untuk jenis barang: " << total_barang[i].jns_barang << " terdapat stock barang sejumlah: " << total_barang[i].ttl_barang << "\n";
        }
        else
        {
            cek++;
            continue;
        }
    }
    if (cek == total_barang.size())
    {
        cout << "Belum ada jenis barang yang dimasukkan kedalam Gudang Barang, silahkan memasukkan terlebih dahulu dengan memasukkan input menu 1" << endl;
    }
    printf("\n");
}

int main()
{
    short p;
    string a, c;
    int b;
    barang temp;

    while (1)
    {
        cout << "Selamat Datang di Gudang Barang"
             << "\n";
        cout << "Menu:"
             << "\n";
        cout << "1. Memasukkan barang"
             << "\n";
        cout << "2. Mengeluarkan barang"
             << "\n";
        cout << "3. Lihat stock barang"
             << "\n";
        cout << "9. Keluar"
             << "\n";
        cout << "Input menu yang ingin anda pilih"
             << "\n";

        cin >> p;
        cin.ignore();

        if (p == 1)
        {
            // cout << "menu 1" << endl;
            system("cls");
            barang_masuk();
        }

        else if (p == 2)
        {
            // cout << "menu 2" << endl;
            system("cls");
            barang_keluar();
        }

        else if (p == 3)
        {
            // cout << "menu 3" << endl;
            system("cls");
            barang_tampilkan();
        }

        else if (p == 9)
        {
            system("cls");
            urutan_barang.clear();
            total_barang.clear();
            break;
        }
        else
        {
            system("cls");
            cout << "Menu yang anda pilih tidak terdapat pada pilihan menu, silahkan pilih menu yang tersedia ^_^" << endl;
            cout << "\n";
        }
    }
}