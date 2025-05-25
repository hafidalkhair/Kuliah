#include <stdio.h>

int main() {
    int angka, total = 0;

    do {
        printf("Masukkan angka (0 untuk berhenti): ");
        scanf("%d", &angka);
        total += angka;
    } while (angka != 0);

    printf("Total angka adalah: %d\n", total);

    return 0;
}

