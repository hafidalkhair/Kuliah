#include <stdio.h>
#include <conio.h>

int main(){
	int y,x =2002; 
	int *px;
	
	px = &x;
	y = *px;
	
	printf("Alamat x 	= %p\n",&x);
	printf("Isi Px   	= %p\n",px);
	printf("Isi X	 	= %d\n", x);
	printf("Nilai *px	= %d\n", *px);
	printf("Nilai Y		= %d\n", y);
	
	getch();
}
