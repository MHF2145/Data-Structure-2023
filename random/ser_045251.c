#include <stdio.h>
#include <string.h>

struct biodata
{
	char nik[100];
	char nama[100];
	char ttl[100];
	char jeniskelamin[100];
	char alamat[100];
	char rtrw[100];
	char desa[100];
	char kecamatan[100];
	char agama[100];
	char status[100];
	char pekerjaan[100];
	char kewarganegaraan[100];
};

int nikcompare(const void* a, const void* b) 
{ 
    struct biodata* biodata_a = (struct biodata*)a;
    struct biodata* biodata_b = (struct biodata*)b;
    return strcmp(biodata_a->nik, biodata_b->nik); 
} 

int cari_nik(struct biodata arr[], int n, char key[]) 
{
    int kecil = 0, besar = n - 1; 
    while (strcmp(key, arr[kecil].nik) >= 0 && strcmp(key, arr[besar].nik) <= 0) 
    { 
        int pos = kecil + (((double)(besar - kecil) / (strcmp(arr[besar].nik, arr[kecil].nik))) * (strcmp(key, arr[kecil].nik)));
        if (strcmp(arr[pos].nik, key) == 0) 
            return pos; 
        if (strcmp(arr[pos].nik, key) < 0) 
            kecil = pos + 1; 
        else
            besar = pos - 1; 
    } 
    return -1;
}

int main()
{
	int pilihan1, pilihan2, i, n, jml_data = 0;
	char key[100];
	struct biodata data;
	FILE * file;

	file = fopen("KTPhasildata.bin", "rb");

	if (file != NULL)
	{
		fseek(file, 0, SEEK_END);
		jml_data = ftell(file) / sizeof(struct biodata);
		fseek(file, 0, SEEK_SET);
	}

	do {
		printf("Pilih Menu:\n");
		printf("1. Tambahkan data\n");
		printf("2. Lihat data\n");
		printf("3. Cari data\n");
		printf("4. Exit\n");
		printf("Pilihan: ");
		scanf("%d", &pilihan1);

		if (pilihan1 == 1)
		{
			do {
				system("cls");
				file = fopen("KTPhasildata.bin", "ab");

				printf("\nMasukkan data baru:\n");
				printf("\nNIK			: ");
				scanf(" %[^\n]", data.nik);
				printf("Nama			: ");
				scanf(" %[^\n]", data.nama);
				printf("Tempat/Tanggal Lahir	: ");
				scanf(" %[^\n]", data.ttl);
				printf("Jenis Kelamin		: ");
				scanf(" %[^\n]", data.jeniskelamin);
				printf("Alamat			: ");
				scanf(" %[^\n]", data.alamat);
				printf("RT/RW			: ");
				scanf(" %[^\n]", data.rtrw);
				printf("Kel/Desa		: ");
				scanf(" %[^\n]", data.desa);
				printf("Kecamatan		: ");
				scanf(" %[^\n]", data.kecamatan);
				printf("Agama			: ");
				scanf(" %[^\n]", data.agama);
				printf("Status Perkawinan	: ");
				scanf(" %[^\n]", data.status);
				printf("Pekerjaan		: ");
				scanf(" %[^\n]", data.pekerjaan);
				printf("Kewarganegaraan		: ");
				scanf(" %[^\n]", data.kewarganegaraan);
				fwrite(&data, sizeof(struct biodata), 1, file);
				jml_data++;
				fclose(file);

				system("cls");
				printf("Data berhasil ditambahkan.\n");
				printf("\nPilih Menu:\n");
				printf("1. Tambahkan data lain\n");
				printf("2. Kembali\n");
				printf("Pilihan: ");
				scanf("%d", &pilihan2);
			}

			while (pilihan2 == 1);
			if (pilihan2 == 2)
			{
				system("cls");
				fclose(file);
			}
			else
			{
				system("cls");
				printf("Pilihan tidak valid.\\n");
				fclose(file);
			}
		}
		else if (pilihan1 == 2)
        {
            system("cls");
            file = fopen("KTPhasildata.bin", "rb");
            
            printf("Data yang tersimpan:\n");
            
            struct biodata arr[jml_data];

            for (i = 0; i < jml_data; i++)
            {
                fread(&arr[i], sizeof(struct biodata), 1, file);
            }

            qsort(arr, jml_data, sizeof(struct biodata), nikcompare);
		
			for (i = 0; i < jml_data; i++)
			{
				fread(&data, sizeof(struct biodata), 1, file);
				printf("\nData ke-%d:\n", i + 1);
				printf("\n=======================================================\n");
				printf("                   KARTU TANDA PENDUDUK                \n");
				printf("=======================================================\n");
				printf("NIK              	: %s\n", arr[i].nik);
				printf("Nama             	: %s\n", arr[i].nama);
				printf("Tempat/Tanggal Lahir	: %s\n", arr[i].ttl);
				printf("Alamat           	: %s\n", arr[i].alamat);
				printf("RT/RW            	: %s\n", arr[i].rtrw);
				printf("Kelurahan/Desa   	: %s\n", arr[i].desa);
				printf("Kecamatan        	: %s\n", arr[i].kecamatan);
				printf("Agama            	: %s\n", arr[i].agama);
				printf("Status Perkawinan	: %s\n", arr[i].status);
				printf("Pekerjaan        	: %s\n", arr[i].pekerjaan);
				printf("Kewarganegaraan  	: %s\n", arr[i].kewarganegaraan);
				printf("-------------------------------------------------------\n");
			}
			fclose(file);
		}
		else if (pilihan1 == 3)
        {
            system("cls");
            file = fopen("KTPhasildata.bin", "rb");

            printf("Masukkan NIK yang ingin dicari: ");
            scanf("%s", key);

            struct biodata arr[jml_data];

            for (i = 0; i < jml_data; i++)
            {
                fread(&arr[i], sizeof(struct biodata), 1, file);
            }

            qsort(arr, jml_data, sizeof(struct biodata), nikcompare);

            int result = cari_nik(arr, jml_data, key);

            if (result == -1)
            {
                printf("Data tidak ditemukan.\n");
            }
            else
            {
                printf("Data ditemukan pada indeks ke-%d:\n", result);
                printf("\n=======================================================\n");
				printf("                   KARTU TANDA PENDUDUK                \n");
				printf("=======================================================\n");
				printf("NIK              	: %s\n", arr[result].nik);
				printf("Nama             	: %s\n", arr[result].nama);
                printf("Tempat/Tanggal Lahir	: %s\n", arr[result].ttl);
				printf("Alamat           	: %s\n", arr[result].alamat);
				printf("RT/RW            	: %s\n", arr[result].rtrw);
				printf("Kelurahan/Desa   	: %s\n", arr[result].desa);
				printf("Kecamatan        	: %s\n", arr[result].kecamatan);
				printf("Agama            	: %s\n", arr[result].agama);
				printf("Status Perkawinan	: %s\n", arr[result].status);
				printf("Pekerjaan        	: %s\n", arr[result].pekerjaan);
				printf("Kewarganegaraan  	: %s\n", arr[result].kewarganegaraan);
				printf("-------------------------------------------------------\n");
            }

            fclose(file);
        }
		else if (pilihan1 == 4)
		{
			system("cls");
			printf("Program selesai.\n");
		}
		else
		{
			system("cls");
			printf("Pilihan tidak valid.\n");
		}
	} while (pilihan1 != 4);

	return 0;
}
