#include <stdio.h>

int main() {
    int angka;

    do {
        printf("Masukkan angka antara 1 dan 10: ");
        scanf("%d", &angka);
    } while (angka < 1 || angka > 10);

    printf("Anda memasukkan angka yang valid: %d\n", angka);

    return 0;
}

