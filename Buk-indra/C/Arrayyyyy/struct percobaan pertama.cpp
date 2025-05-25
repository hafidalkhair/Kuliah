#include <stdio.h>

struct Nim {
	long long int nim;
};

struct Mahasiswa {
	char nama[10];
	struct Nim nim;
	char kelas[50];
};

void cetak(struct Mahasiswa mhs) {
	printf("Nama   : %s\n", mhs.nama);
	printf("NIM    : %.lld\n", mhs.nim.nim); // Gunakan %lld untuk mencetak long long int
	printf("Kelas  : %s\n", mhs.kelas);
	printf("\n");
}

int main() {
	struct Nim nim1 = {2023903430060}; 
	struct Mahasiswa mahasiswa1 = {"Hafid", nim1, "TRKJ 1C"}; 
	cetak(mahasiswa1);

	struct Nim nim2 = {2023903430030}; 
	struct Mahasiswa mahasiswa2 = {"Arya", nim2, "TRKJ 1C"}; 
	cetak(mahasiswa2);
	
	return 0;
}

