#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fungsi.h"

void lihat_ktp(){
	FILE *fp = fopen("File_ktp.dat", "ab+");
	KTP detail;
	if(fp == NULL){
	    printf("Maaf, file yang Anda buka tidak dapat ditemukan.\n");
	    fclose(fp);
	} else {
		while(!feof(fp)){
			if(fread(&detail, sizeof(KTP), 1, fp) && !ceknik(detail)){
				isi[++size] = detail;
			}
		}
		fclose(fp);
    }
}
