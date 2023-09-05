#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//untuk mengetahui jumlah mahasiswa yang diinputkan
int person = 0;
//untuk menyimpan nrp dan mengikuti kelas yang mana
typedef struct
{
    char nim[15];
    int kls1, kls2, kls3, kls4, kls5, kls6;
} mahasiswa;
//untuk melakukan scan dari input berupa file
void inputfile(FILE *f, mahasiswa data[])
{
    int anak = 0;
    while (fscanf(f, "%s %d %d %d %d %d %d", data[person].nim, &data[person].kls1, &data[person].kls2, &data[person].kls3, &data[person].kls4, &data[person].kls5, &data[person].kls6) != EOF)
    {
        person++;
    }
}

int main()
{
    //deklarasi hal yang akan digunakan
    mahasiswa data[105];
    FILE *f;
    f = fopen("input12.txt", "r");
    inputfile(f, data);
    //pengecekan apakah dapat membaca file dengan benar dan lengkap
    // for (int i = 0; i < person; i++)
    // {
    //     printf("%d\n", i);
    //     printf("%s %d %d %d %d %d %d\n", data[i].nim, data[i].kls1, data[i].kls2, data[i].kls3, data[i].kls4, data[i].kls5, data[i].kls6);
    // }

    // printf("Class CS**A : \n");
    // for(int count = 0; count < person; count++){
    //     if(data[count].kls1 == 1){
    //         printf("    %s\n", data[count].nim);
    //     }
    // }

    //output berupa setiap kelas dengan nrp berapa saja yang mengikuti kelas tersebut
    printf("This is the information about six courses\n");
    
    printf("Class CS20A : \n");
    for(int count = 0; count < person; count++){
        if(data[count].kls1 == 1){
            printf("    %s\n", data[count].nim);
        }
    }

    
    printf("Class CS21A : \n");
    for(int count = 0; count < person; count++){
        if(data[count].kls2 == 1){
            printf("    %s\n", data[count].nim);
        }
    }

    
    printf("Class CS29A : \n");
    for(int count = 0; count < person; count++){
        if(data[count].kls3 == 1){
            printf("    %s\n", data[count].nim);
        }
    }

    
    printf("Class CS30A : \n");
    for(int count = 0; count < person; count++){
        if(data[count].kls4 == 1){
            printf("    %s\n", data[count].nim);
        }
    }

    
    printf("Class CS35A : \n");
    for(int count = 0; count < person; count++){
        if(data[count].kls5 == 1){
            printf("    %s\n", data[count].nim);
        }
    }

    
    printf("Class CS36A : \n");
    for(int count = 0; count < person; count++){
        if(data[count].kls6 == 1){
            printf("    %s\n", data[count].nim);
        }
    }
    //berhasil dieksekusi dan code selesai
    return 0;
}