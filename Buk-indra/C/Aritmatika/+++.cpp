#include <stdio.h>

int main() {
    int angka1, angka2, hasil;

    printf("Masukkan angka pertama: ");
    scanf("%d", &angka1);

    printf("Masukkan angka kedua: ");
    scanf("%d", &angka2);

    hasil = angka1 + angka2;

    printf("Hasil penjumlahan: %d\n", hasil);

    return 0;
}

