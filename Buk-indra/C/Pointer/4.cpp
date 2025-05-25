#include <stdio.h>
#include <conio.h>

char *nama_bulan(int n){
	static char *bulan[]= {
	"Kode bulan salah",
	"Januari","Februari","Maret",
	"April", "Mei", "Juni", "Juli",
	"Agustus","September","Oktober",
	"November","Desember"
	};
	return((n<1 || n>12)?bulan[0]: bulan[n]);
}
int main(){
	int b1; 
	
	printf("Masukan kode bulan [1..12] : ");
	scanf("%d",&b1);
	printf("Bulan ke-%d adalah %s\n", b1, nama_bulan(b1));
	
	getch();
}
