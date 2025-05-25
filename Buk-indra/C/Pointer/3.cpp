#include <stdio.h>
#include <conio.h>

void naikkan_nilai(int *x, int *y);

main(){
	int a = 3, b = 7;
	
	printf("SEMUA		: a = %d b = %d\n",a , b);
	naikkan_nilai(&a, &b);
	printf("SEKARANG	: a = %d b = %d\n",a , b);
	getch(); 
}
void naikkan_nilai(int *x , int *y){
	*x = *x + 2 ; 
	*y = *y + 3 ; 
}
