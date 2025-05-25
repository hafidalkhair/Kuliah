#include <stdio.h>
#include <conio.h>

void cetak_pesan(void);

int main()
{
	int i;
	for(i= 1; i<=5; i++){
		printf("Pesan ke-%d :", i);
		cetak_pesan();
	}	
	getch();
}
void cetak_pesan()
{
	printf("Ini dulu!Baru itu!\n");
}
