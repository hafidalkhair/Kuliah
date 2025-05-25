#include <stdio.h>
#include <conio.h>

void hitung_tringular(int n)
{
	int i, jumlah = 0;
	
	for (i=1; i<=n; ++i)
		jumlah=jumlah +i;
	printf("Jumlah tringular %d adalah %d\n",n,jumlah); 
}
int main()
{
	hitung_tringular(10);
	hitung_tringular(20);
	hitung_tringular(50);
	
	getch();	
}
