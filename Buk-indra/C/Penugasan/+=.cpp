#include <stdio.h>

int main() {
    int angka1, angka2;

    printf("Masukkan angka pertama: ");
    scanf("%d", &angka1);

    printf("Masukkan angka kedua: ");
    scanf("%d", &angka2);

    angka1 += angka2; // Operator penugasan penambahan, ekuivalen dengan angka1 = angka1 + angka2

    printf("Hasil penugasan penambahan: %d\n", angka1);

    return 0;
}

