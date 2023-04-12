#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fungsi.h"

void lihatkan_ktp(KTP isi_KTP)
{
    printf("Nama\t\t\t:%lld\n", isi_KTP.nama);

    printf("NIK\t\t\t: %s\n", isi_KTP.NIK);

    printf("Tempat / Tgl Lahir\t: %s %d %d %d\n", isi_KTP.tempat_lahir, isi_KTP.ultah.tanggal, isi_KTP.ultah.bulan, isi_KTP.ultah.tahun);

    switch(isi_KTP.kelamin)
    {
        case 1:
            printf("Jenis Kelamin\t\t: Laki-laki\n");
            break;
        case 2:
            printf("Jenis Kelamin\t\t: Perempuan\n");
            break;
    }

    switch(isi_KTP.goldar)
    {
        case 1:
            printf("Golongan Darah\t\t: A\n");
            break;
        case 2:
            printf("Golongan Darah\t\t: B\n");
            break;
        case 3:
            printf("Golongan Darah\t\t: AB\n");
            break;
        case 4:
            printf("Golongan Darah\t\t: O\n");
            break;
    }

    printf("Alamat\t\t\t: %s\n", isi_KTP.alamat);

    switch (isi_KTP.agama)
    {
        case 1:
            printf("Agama\t\t\t: Islam\n");
            break;
        case 2:
            printf("Agama\t\t\t: Kristen\n");
            break;
        case 3:
            printf("Agama\t\t\t: Katolik\n");
            break;
        case 4:
            printf("Agama\t\t\t: Hindu\n");
            break;
        case 5:
            printf("Agama\t\t\t: Buddha\n");
            break;
        case 6:
            printf("Agama\t\t\t: Konghuchu\n");
            break;
    }

    switch (isi_KTP.status)
    {
        case 1:
            printf("Status\t\t\t: Belum Menikah\n");
            break;
        case 2:
            printf("Status\t\t\t: Sudah Menikah\n");
            break;
        case 3:
            printf("Status\t\t\t: Bercerai\n\n");
            break;
        case 4:
            printf("Status\t\t\t: Duda/Janda\n");
            break;
    }

    printf("Pekerjaan\t\t: %s\n", isi_KTP.pekerjaan);

    switch (isi_KTP.kewarganegaraan)
    {
        case 1:
            printf("Kewargaegaraan\t\t: Warga Negara Indonesia\n");
            break;
        case 2:
            printf("Kewargaegaraan\t\t: Warga Negara Asing\n");
            break;
    }

    switch (isi_KTP.tipe_ktp)
    {
        case 1:
            printf("Tipe\t\t\t: Perlu Perpanjangan\n");
            break;
        case 2:
            printf("Tipe\t\t\t: Berlaku Seumur Hidup\n");
            break;
    }
    printf("___________________________________________________________________________________\n\n");

}
