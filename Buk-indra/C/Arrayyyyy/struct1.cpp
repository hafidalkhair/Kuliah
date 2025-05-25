#include <stdio.h>

struct Nim {
	long long int Nim; 
};

struct Mahasiswa {
	char nama[50];
	int umur;
	char asal[100];
	int nim;
	
};
void Cetak(struct Mahasiswa ms) {
	printf("%s\n",ms.nama);
	printf("%d\n",ms.umur);
	printf("%s\n",ms.asal);
	printf("%.lld\n",ms.nim);
	
	printf("\n");
}
main(){
	struct Nim nim1 = {2023903430060};
	struct Mahasiswa mahasiswa1 = {"HAFID",18,"TRKJ 1C",nim1};
	Cetak(mahasiswa1);
	
	struct Nim nim2 = {20239034300};
	struct Mahasiswa mahasiswa2 = {"ZEGA",18,"TRKJ 1C"};
	Cetak(mahasiswa2);
	
}
