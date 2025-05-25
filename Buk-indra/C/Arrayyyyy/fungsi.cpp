#include <stdio.h>
#include <math.h>

float lingkaran(float);

int main(){
    float a, luas;
	int PI = 3.14; 

    printf("Masukkan Jari-jari Lingkaran: ");
    scanf("%f", &a);
	
    luas = lingkaran(a); // Memanggil fungsi lingkaran dan menyimpan hasilnya dalam variabel kecil
    printf("Luas Lingkaran: %.2f\n", luas);
	
    return 0;
}

float lingkaran(float r){
    const float PI = 3.14;
    float luas;
    luas = PI * pow(r, 2);
    return luas;
}

