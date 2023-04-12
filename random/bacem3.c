#include <stdio.h>
#include <string.h>

typedef struct KTP{
	char 					Nama [100],
					        TTL [100],
					        JK [100],
					        GolDar [5],
					        Alamat [100],
					        Agama [100],
					        SPerkawinan [100],
					        Pekerjaan [100],
					        status [20];
	unsigned long long		NIK ;
}dataktp_t; 

dataktp_t Entri[200] = {"","","","","","","","", "kosong"};
void bubblesort (dataktp_t Entri[], int count);
int EntriData(int count);
void LihatEntri();
int CariData(int count, dataktp_t Entri []);


int EntriKTP (int count)
{
    int i = 0;
    char inputlagi, kosong;

    while(1)
	{
        if (strcmp(Entri[i].status,"Terisi") != 0)
		{
        printf ("\nEntri Data %d\n", i+1);
        printf ("NIK                    :       ");
        scanf("%llu", &Entri[i].NIK); 
		getchar();
        
        printf ("Nama                   :       ");
        gets (Entri[i].Nama);
        
        printf ("Tempat & Tanggal Lahir :  		");
        gets (Entri[i].TTL);
        
        printf ("Jenis Kelamin          :       ");
        gets (Entri[i].JK);
        
        printf ("Golongan Darah         :       ");
        gets (Entri[i].GolDar);
        
        printf ("Alamat                 :       ");
        gets (Entri[i].Alamat);
        
        printf ("Agama                  :       ");
        gets (Entri[i].Agama);
        
        printf ("Status Perkawinan      :       ");
        gets (Entri[i].SPerkawinan);
        
        printf ("Pekerjaan              :       ");
        gets (Entri[i].Pekerjaan);
		
        strcpy(Entri[i].status, "Terisi");
        i++;
        count++;
        bubblesort (Entri, count);
		
		printf("Data anda berhasil di input\n ");
        printf ("Apakah Anda Ingin Input Entri Lagi (y/n)?\n");
        scanf("%c%c", &inputlagi, &kosong);
        if (inputlagi == 'y') continue;
        else if (inputlagi == 'n') break;
        }
        i++;
    } 
    return count;
    
}

void LihatEntri (){
    
    int i = 0;

    while(1){
        if(strcmp(Entri[i].status, "Terisi") == 0)
		{
            printf("NIK                     : %llu\n", Entri[i].NIK);
            printf("Nama                    : %s\n", Entri[i].Nama);
            printf("Tempat & Tanggal Lahir  : %s\n", Entri[i].TTL);
            printf("Jenis Kelamin           : %s\n", Entri[i].JK);
            printf("Golongan Darah          : %s\n", Entri[i].GolDar);
            printf("Alamat                  : %s\n", Entri[i].Alamat);
            printf("Agama                   : %s\n", Entri[i].Agama);
            printf("Status Perkawinan       : %s\n", Entri[i].SPerkawinan);
            printf("Pekerjaan               : %s\n\n", Entri[i].Pekerjaan);     
        }else break;
        i++;
    } 

}

int CariData (int count, dataktp_t Entri[200]){
	
	unsigned long long data;
    int low = 0,
        high = count - 1,
        mid = -1,    
        index = -1;

    printf("\n\nMasukkan nilai NIK yang ingin dicari\n");
    scanf("%llu", &data);

    while(low <= high)
    {
        mid = low + (((double)(high - low) / (Entri[high].NIK - Entri[low].NIK)) * (data - Entri[low].NIK));

        if(Entri[mid].NIK == data)
        {
            index = mid;
            break;
        } 
        else
        {
            if (Entri[mid].NIK < data) low = mid + 1;
            else high = mid - 1;
        }               
    }

    switch (index)
    {
    case -1 :
        printf ("\n\nData yang Anda cari tidak ditemukan.\n\n");
        break;
    
    default:
            printf("\n\nData Ditemukan.\n\n");
            printf("NIK                     : %llu\n", Entri[mid].NIK);   
            printf("Nama                    : %s\n", Entri[mid].Nama);
            printf("Tempat & Tanggal Lahir  : %s\n", Entri[mid].TTL);
            printf("Jenis Kelamin           : %s\n", Entri[mid].JK);
            printf("Golongan Darah          : %s\n", Entri[mid].GolDar);
            printf("Alamat                  : %s\n", Entri[mid].Alamat);
            printf("Agama                   : %s\n", Entri[mid].Agama);
            printf("Status Perkawinan       : %s\n", Entri[mid].SPerkawinan);
            printf("Pekerjaan               : %s\n\n", Entri[mid].Pekerjaan);
        break;
    }
}


void bubblesort(dataktp_t list[100], int count){
    int i, j;
    dataktp_t temp;
    
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < (count - 1-i); j++)
        {
            if (list[j].NIK > list[j + 1].NIK)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            } 
        }
    }

}

int main (){

    int pilihanmenu;
    int count = 0;
    int i = 0;
    char buang;
    
    
    FILE *Fktp;

    Fktp = fopen ("ktpp.bin", "rb");
    fread(&Entri, sizeof(dataktp_t), 200, Fktp);
    fclose(Fktp);
    
    while(1)
    {
        if (strcmp (Entri[i].status,"Terisi") == 0)
        {
            count++;
        }
        else break;
        i++;
    }

    while(1){
        printf("\nMenu Utama \n 1. Entri Data\n 2. Lihat Data\n 3. Cari Data\n 4. Exit\n");
        printf("Pilih Menu : ");
        scanf("%d%c", &pilihanmenu, &buang);

        if (pilihanmenu == 1) count = EntriKTP(count);
        else if (pilihanmenu == 2) LihatEntri();
        else if (pilihanmenu == 3) CariData(count, Entri);
        else if (pilihanmenu == 4) break;
        else printf ("Mohon Pilih Pilihan yang ada");
     }



	Fktp = fopen ("ktpp.bin", "wb");
    fwrite (&Entri, sizeof (dataktp_t), 200, Fktp);
    fclose (Fktp); 
    
    return 0;

}