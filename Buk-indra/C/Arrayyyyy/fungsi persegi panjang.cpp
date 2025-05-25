#include <stdio.h>

float luaspersegipanjang(float panjang, float lebar){
	return panjang* lebar ;
}
int main(){
	float panjang,lebar;
	
	printf("Masukkan Panjang Persegi panjang :");
	scanf("%f",&panjang);
	
	printf("Masukkan lebar Persegi panjang :");
	scanf("%f",&lebar);
	
	float luas = luaspersegipanjang(panjang,lebar);
	
	printf("Luas persegi panjang dengan panjang %.2f dan lebar %.2f adalah : %.2f\n",panjang,lebar,luas);
	return 0;
}
