#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ultah
{
    int tanggal, bulan, tahun;
}ultah;

typedef struct KTP 		//datanya mahasiswa
{
	long long NIK[17];
	char nama[51], tempat_lahir[21], alamat[101], pekerjaan[101];;
	int kelamin,  goldar, agama, status, kewarganegaraan, tipe_ktp;
	ultah birthday;
}KTP;

KTP inp_ktp();			    //f(x) input ktp
void dpt_ktp();             //f(x) masukkan data ke file
void lihatkan_ktp(KTP);     //f(x) ambilkan data
void keluar();              //f(x) ya keluar
void msk_ktp(KTP);          //f(x) nanti buat ngecek di fungsi cek dengan nik
void lihat_ktp();           //f(x) lihat data ktp
void smpn_ktp();            //f(x) menyimpan data
void cari_ktp();            //f(x) mencari data ktp menggunakan nik
void list_ktp();			//f(x) menampilkan ktp
void Select();				//f(x) memilih di menu
void Menu();				//f(x) menu
int ceknik();               //f(x) cari info nik ada atau sudah terisi

KTP isi[300];
int size;

