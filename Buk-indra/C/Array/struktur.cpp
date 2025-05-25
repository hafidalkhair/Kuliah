#include <stdio.h>
#include <string.h>

	struct Buku {
    char judul[100];
    char pengarang[100];
    int tahunTerbit;
    float harga;
};

int main(){

	struct Buku buku1;

	strcpy(buku1.judul, "Pemrograman dalam Bahasa C");
	strcpy(buku1.pengarang, "John Doe");
	buku1.tahunTerbit = 2022;
	buku1.harga = 49.99;

	printf("Judul: %s\n", buku1.judul);
	printf("Pengarang: %s\n", buku1.pengarang);
	printf("Tahun Terbit: %d\n", buku1.tahunTerbit);
	printf("Harga: %.2f\n", buku1.harga);
	
	return 0; 
	
}

