#include <stdio.h>
int faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * faktorial(n - 1);
    }
}
int main() {
    int angka;
    printf("Masukkan angka untuk menghitung faktorial: ");
    scanf("%d", &angka);
    if (angka < 0) {
        printf("Masukkan angka non-negatif.\n");
    } else {
        printf("Faktorial dari %d = %d\n", angka, faktorial(angka));
    }
    return 0;
}

