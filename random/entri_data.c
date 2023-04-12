#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"

void entri_data() {
	system("cls");
	FILE *fp;
    struct KTP user = {"", "", 0, 0, 0, 0, 0};

    if ((fp = fopen("data_ktp.dat", "ab+")) == NULL){
        printf("File could not be opened.\n");
        fclose(fp);
    } else {
    	while(1) {
    		
    		printf("NIK\t\t\t: ");
	        scanf(" %[^\n]s", user.NIK);
	        printf("Nama\t\t\t: ");
	        scanf(" %[^\n]s", user.nama);
	        printf("Jenis Kelamin (L/P)\t: ");
	        scanf(" %[^\n]c", &user.jk);
	        printf("Golongan Darah\t\t: ");
	        scanf(" %[^\n]s", user.darah);
	        printf("Alamat\t\t\t: ");
	        scanf(" %[^\n]s", user.alamat);
	        printf("RT\t\t\t: ");
	        scanf(" %[^\n]s", user.rt);
	        printf("RW\t\t\t: ");
	        scanf(" %[^\n]s", &user.rw);
	        printf("Desa\t\t\t: ");
	        scanf(" %[^\n]s", user.desa);
	        printf("Kecamatan\t\t: ");
	        scanf(" %[^\n]s", &user.kecamatan);
	        printf("Agama\t\t\t: ");
	        scanf(" %[^\n]s", user.agama);
		}
	}
	fclose(fp);
}
