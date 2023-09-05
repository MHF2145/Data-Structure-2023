#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include<stdio.h>
using namespace std;

struct daerah
{
       char kel[50];
       char kec[50];
       char kota[50];
};

struct data
{
       char nomor[20];
       char nama[50];
       char agama[20];
       char jenis[20];
       char status[20];
       char pekerjaan[20];
       char tempat[20];
       char tanggal[20];
       char almt[20];
       daerah alamat;
};

int main()
{
    char temp;
    int menu;
    int dugaan=0,
    i,j;
    int pilih;
    char namedit[20];
    data ktp[20];
    bool ketemu;

    menuutama:
    system("cls");
    system ("color f3");
    printf(" ---------------- Aplikasi Data KTP ---------------");
    printf(" \nMENU UTAMA :\n\n");
    printf(" 1.Menambah Data Penduduk\n\n");
    printf(" 2.Mencari Data Penduduk\n\n");
    printf(" 3.Menghapus Data Penduduk\n\n");
    printf(" 4.Menampilkan Data Penduduk\n\n");
    printf(" 5.Keluar\n\n");
    printf(" _____________________________\n\n");
    printf(" Masukan Pilihan Anda : ");
    scanf("%d", &menu);

    if(menu==1)
    {
        system("cls");
        printf("\n PENAMBAHAN DATABASE KTP\n");
        printf(" ____________________________\n\n");
        printf(" NIK                        : ");
        scanf ("%c", &temp);
        scanf("%[^\n]s", &ktp[dugaan].nomor);
        printf(" Nama Lengkap               : ");
        scanf("%c", &temp);
        scanf ("%[^\n]s", &ktp[dugaan].nama);
        printf(" Agama                      : ");
        scanf("%c", &temp);
        scanf ("%[^\n]s", &ktp[dugaan].agama);
        printf(" Jenis Kelamin              : ");
        scanf("%c", &temp);
        scanf ("%[^\n]s", &ktp[dugaan].jenis);
        printf(" Status Perkawinan          : ");
        scanf("%c", &temp);
        scanf ("%[^\n]s", &ktp[dugaan].status);
        printf(" Pekerjaan                  : ");
        scanf("%c", &temp);
        scanf ("%[^\n]s", &ktp[dugaan].pekerjaan);
        printf(" Tempat Lahir               : ");
        scanf("%c", &temp);
        scanf ("%[^\n]s", &ktp[dugaan].tempat);
        printf(" Tanggal Lahir (DD MM YYYY) : ");
        scanf("%c", &temp);
        scanf ("%[^\n]s", &ktp[dugaan].tanggal);
        printf(" Alamat                     : ");
        scanf("%c", &temp);
        scanf ("%[^\n]s", &ktp[dugaan].almt);
        printf(" Kelurahan                  : ");
        scanf("%c", &temp);
        scanf ("%[^\n]s", &ktp[dugaan].alamat.kel);
        printf(" Kecamatan                  : ");
        scanf("%c", &temp);
        scanf ("%[^\n]s", &ktp[dugaan].alamat.kec);
        printf(" Kota                       : ");
        scanf("%c", &temp);
        scanf ("%[^\n]s", &ktp[dugaan].alamat.kota);
        printf(" _________________________________________________________________\n\n");
        dugaan++;
        printf(" 1.Kembali ke Menu Utama\n\n");
        printf(" 2.Keluar dari program\n");
        printf(" _____________________________\n\n");
        printf(" Masukan Pilihan Anda : ");
        scanf("%d", &pilih);

        if(pilih==1)
        {
            goto menuutama;
        }
        else if(pilih==2)
        {
            goto keluar;
        }
    }

    if(menu==2)
    {
        system ("cls");
        int counter=0,
        urutan=0;
        printf("\n PENCARIAN DATA PENDUDUK\n");
        printf(" ____________________________\n\n");
        printf(" Masukan NIK : ");
        scanf("%s",&namedit);

        for(i=0;i<dugaan;i++)
        {
            if(strcmp(namedit,ktp[i].nomor) == 0)
            {
                counter++;
                urutan=i;
                break;
            }
        }

        if(counter>0)
        {
            printf(" Data di temukan pada registrasi ktp ke-%d\n", urutan+1);
            printf(" NIK 				: %s\n",ktp[urutan].nomor);
            printf(" Nama 				: %s\n",ktp[urutan].nama);
            printf(" Agama 				: %s\n",ktp[urutan].agama);
            printf(" Jenis Kelamin 		: %s\n",ktp[urutan].jenis);
            printf(" Status perkawinan 	: %s\n",ktp[urutan].status);
            printf(" Pekerjaan 			: %s\n",ktp[urutan].pekerjaan);
            printf(" Tempat Lahir 		: %s\n",ktp[urutan].tempat);
            printf(" Tanggal Lahir 		: %s\n",ktp[urutan].tanggal);
            printf(" Alamat 			: %s\n",ktp[urutan].almt);
            printf(" Kelurahan 			: %s\n",ktp[urutan].alamat.kel);
            printf(" Kecamatan 			: %s\n",ktp[urutan].alamat.kec);
            printf(" Kota 				: %s\n",ktp[urutan].alamat.kota);
            printf(" _____________________________________________________\n\n");
        }

        else
        //if (counter==0)
        {
            printf(" DATA YANG ANDA CARI TIDAK DI TEMUKAN !!!\n\n");
            printf(" ________________________________________\n\n");
        }

        goto menu0;

        menu0:
        printf(" 1.Kembali ke Menu Utama\n\n");
        printf(" 2.Keluar dari program\n");
        printf(" _____________________________\n\n");
        printf(" Masukan Pilihan Anda : ");
        scanf("%d", &pilih);

        if(pilih==1)
        {
            goto menuutama;
        }
        else if(pilih==2)
        {
            goto keluar;
        }
    }

    if(menu==3)
    {
        system ("cls");
        printf("\n PENGHAPUSAN DATA PADA DATABASE KTP\n");
        printf(" ____________________________________\n\n");
        printf(" dugaan : ");
        scanf("%s",&namedit);

        for(i=0;i<dugaan;i++)
        {
            if(strcmp(namedit,ktp[i].nomor)==0)
            {
                ketemu=true;
                j=i;
                break;
            }
        }
            if(ketemu)
            {
                for(i=j;i<dugaan;i++)
                    {
                        ktp[i]=ktp[i+1];

                    }
                    dugaan--;
                    printf(" DATA BERHASIL DI HAPUS\n\n");
                    goto menu;
            }
            else
            {
                printf(" DATA YANG AKAN DI HAPUS TIDAK DITEMUKAN !!!\n");
            }

        printf(" ____________________________________________\n\n");
        menu:
        printf(" 1.Kembali ke Menu Utama\n\n");
        printf(" 2.Keluar dari program\n");
        printf(" _____________________________\n\n");
        printf(" Masukan Pilihan Anda : ");
        scanf("%d", &pilih);
        if(pilih==1)
        {
            goto menuutama;
        }
        else if(pilih==2)
        {
            goto keluar;
        }
    }

    else if(menu==4)
    {
        system ("cls");
        if (dugaan==0)
        {
            printf("TIDAK ADA DATA\n\n");
        }
        else
        {
            printf("\n MENAMPILKAN DATA PENDUDUK (KTP)\n");
            printf(" _________________________________\n\n");
            for(i=0;i<dugaan;i++)
            {
                printf(" Database Data KTP ke-%d\n", i+1);
                printf(" dugaan : %s\n",ktp[i].nomor);
                printf(" Nama : %s\n",ktp[i].nama);
                printf(" Agama : %s\n",ktp[i].agama);
                printf(" Jenis Kelamin : %s\n",ktp[i].jenis);
                printf(" Status perkawinan : %s\n",ktp[i].status);
                printf(" Pekerjaan : %s\n",ktp[i].pekerjaan);
                printf(" Tempat Lahir : %s\n",ktp[i].tempat);
                printf(" Tanggal Lahir : %s\n",ktp[i].tanggal);
                printf(" Alamat : %s\n",ktp[i].almt);
                printf(" Kelurahan : %s\n",ktp[i].alamat.kel);
                printf(" Kecamatan : %s\n",ktp[i].alamat.kec);
                printf(" Kota : %s",ktp[i].alamat.kota);
                printf ("\n\n");
            }
        }

        printf(" _____________________________________________\n\n");
        printf(" 1.Kembali ke menu awal\n\n");
        printf(" 2.Keluar dari program\n");
        printf(" _____________________________\n\n");
        printf(" Masukan Pilihan Anda : ");
        scanf("%d", &pilih);
        if(pilih==1)
        {
            goto menuutama;
        }
        else if(pilih==2)
        {
            goto keluar;
        }

        keluar:
        system("cls");
        printf("\n TERIMA KASIH\n");

        return 0;
    }
}
