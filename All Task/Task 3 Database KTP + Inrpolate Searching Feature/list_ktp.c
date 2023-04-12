#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fungsi.h"

void list_ktp(){
	system("cls");
	char response = 'y';
	do {
		printf("================ Data KTP ================\n");
		int ketemu = 0, i;
		for(i = 1; i <= size; i++){
			ketemu = 1;
			printf("Data ke-%d\n", i);
			lihatkan_ktp(isi[i]);
		}
		if (ketemu == 0){
			printf("Belum ada data yang dimasukkan!\n");
		}
	    printf("\nApakah Anda ingin keluar dari menu Lihat Data (y/n)? ");
	    scanf("\n%c", &response);
	    system("cls");
	} while(response == 'n');
	printf("Anda telah keluar dari menu Lihat Data, kembali ke menu utama...\n\n");
}
