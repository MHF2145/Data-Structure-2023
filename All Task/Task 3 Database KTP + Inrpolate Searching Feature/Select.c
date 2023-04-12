#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fungsi.h"

void Select()
{

    int pilih;
	Menu();

	scanf("%d", &pilih);

	while(pilih != 10)
	{
		if(pilih == 1)
		{
			inp_ktp();
		}
		else if(pilih == 2)
		{
			list_ktp();
		}
		else if(pilih == 3)
        {
            cari_ktp();
        }
		else
		{
		    system("cls");
			printf("Pilihan anda tidak ada di Menu, tolong masukkan pilihan anda lagi: \n");
		}

		Menu();

		printf("Masukkan Pilihan anda:\n");

		scanf("%d", &pilih);

    }
    system("cls");
}

