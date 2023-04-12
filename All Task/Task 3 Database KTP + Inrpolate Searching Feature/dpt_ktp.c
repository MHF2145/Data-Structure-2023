#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fungsi.h"

void dpt_ktp(){
	system("cls");
	char response = 'n';
	do
    {
	    KTP isi_= dpt_ktp();
        system("cls");
        printf("Rincian data KTP yang Anda masukkan:\n");
        DisplayData(isi_);
		if(!ceknik(isi_))
		{
			InsertData(isi_);
			printf("Data berhasil ditambahkan!\n");
		}
		else
        {
            printf("Data tidak berhasil ditambahkan, NIK tidak boleh sama\n");
		}
	    printf("\n\nApakah Anda ingin memasukkan data KTP lagi (y/n) ? ");
	    scanf("\n%c", &response);
		system("cls");
	} while(response == 'y');
	printf("Anda telah keluar dari menu Input Data, kembali ke menu utama...\n\n");
}

