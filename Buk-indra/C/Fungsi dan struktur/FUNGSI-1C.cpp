#include <stdio.h>

void cetak_pesan(void);

int main()
{
	int i;
	
		for ( i = 1; i<=5; i++) {
			printf("Pesan ke-%d : ", i);
			cetak_pesan();
		}
}

void cetak_pesan()
{
	printf("ini dulu! baru itu!\n\n");
}
