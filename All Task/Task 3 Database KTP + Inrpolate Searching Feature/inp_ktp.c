#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fungsi.h"

KTP inp_ktp()
{
    KTP isi;

    printf("Masukkan Nomor Induk Kependudukan(NIK(16-digit):\n\n");
	scanf("\n%lld",&isi.NIK);

    printf("\nMasukkan Nama Lengkap sesuai yang tertulis di KTP:\n\n");
    scanf("\n%[^\n]%*c", isi.nama);

    printf("\nMasukkan Tempat Lahir:\n\n");
	scanf("\n%[^\n]%*c", isi.tempat_lahir);

	printf("\nMasukkan Tanggal, Bulan, Tahun Lahir:\n");
	printf("Format: Tanggal-Bulan-Tahun \n\n");
	scanf("\n%d-%d%-%d", &isi.ultah.tanggal, &isi.ultah.bulan, &isi.ultah.tahun);

	printf("\nMasukkan Jenis Kelamin Anda sesuai format dibawah:\n");
	printf("1. Laki-laki\n2. Perempuan\n\n");
	scanf("%d", &isi.kelamin);

	printf("\nMasukkan Golongan Darah Anda sesuai format dibawah:\n");
	printf("1.A\n2.B\n3.AB\n4.O\n5.-\n\n");
	scanf("%d", &isi.goldar);

	printf("\nMasukkan Alamat Anda seperti contoh dibawah:\n");
	printf("Contoh: jl Teknik Komputer no 5\n\n");
	scanf("\n%[^\n]%*c", isi.alamat);

	printf("\nMasukkan Agama anda seperti format dibawah:\n");
    printf("\t\t {1. Islam}\t{2. Kristen}\t{3. Katolik}\n");
    printf("\t\t {4. Hindu}\t{5. Buddha}\t{6. Konghuchu}\n\n");
	scanf("%d", &isi.agama);

	printf("\nMasukkan Status Pernikahan anda seperti format dibawah:\n");
    printf("\t\t {1. Belum Menikah}\t{2. Sudah Menikah}\n");
    printf("\t\t {3. Bercerai}\t\t{4. Duda/Janda}\n\n");
	scanf("%d", &isi.status);

	printf("\nMasukkan Pekerjaan Anda seperti contoh dibawah:\n");
	printf("Contoh: Pengangguran\n\n");
	scanf("\n%[^\n]%*c", isi.pekerjaan);

	printf("\nMasukkan Jenis Kelamin Anda sesuai format dibawah:\n");
	printf("1. Warga Negara Indonesia\n2. Warga Negara Asing\n\n");
	scanf("%d", &isi.kewarganegaraan);

	printf("\nMasukkan Tipe KTP Anda sesuai format dibawah:\n");
	printf("1. Perlu Perpanjangan\n2. Berlaku Seumur Hidup\n\n");
	scanf("%d", &isi.tipe_ktp);
	return isi;
}

