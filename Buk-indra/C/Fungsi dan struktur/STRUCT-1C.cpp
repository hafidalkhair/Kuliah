#include <stdio.h>

struct tanggal {
	int tgl;
	int bulan;
	int tahun;
};

int main(){
	struct tanggal now;
	
	now.tgl = 16;
	now.bulan = 10;
	now.tahun = 2023;
	
	printf("Sekarang tanggal ");
	printf("%d/%d/%d\n", now.tgl, now.bulan, now.tahun);
	
	return(0);
}
