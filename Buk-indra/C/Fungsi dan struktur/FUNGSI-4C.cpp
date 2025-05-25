#include <stdio.h>
#include <conio.h>

int fpb(int u, int v);

int main() {
	int hasil;
	
		hasil = fpb(150, 35);
		printf("FPB dari 150 dan 35 adalah %d\n", hasil);
		
		hasil = fpb(1026, 405);
		printf("FPB dari 1026 dan 405 adalah %d\n", hasil);
		
		printf("FPB dari 83 dan 240 adalah %d\n", fpb(83,240));
}

int fpb(int u, int v)
{
	int tampung;
		while (v != 0) {
			tampung = u % v;
			u = v;
			v = tampung;
		}
	return(u);
}
