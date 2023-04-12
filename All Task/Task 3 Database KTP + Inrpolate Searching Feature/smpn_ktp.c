#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fungsi.h"

void smpn_ktp()
{
	FILE *fp = fopen("File_ktp.dat", "ab+");
	if(fp == NULL){
	    printf("Maaf, file yang Anda buka tidak dapat ditemukan.\n");
	    fclose(fp);
	}
	else
	{
		int i = 1;
		fseek(fp, 0, SEEK_SET);
		for(i = 1; i <= size; i++)
        {
			fwrite(&isi[i], sizeof(KTP), 1, fp);
		}
    }
}
