#include <stdio.h>
#include <conio.h>

float minimum(float x, float y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}
int main() {
    float a, b;
    
    printf("Masukkan nilai a: ");
    scanf("%g", &a);
    printf("Masukkan nilai b: ");
    scanf("%g", &b);

    printf("\nBilangan terkecil antara %g dan %g adalah ",a,b);
    printf("%g\n\n", minimum(a,b));
	
	getch();
}



