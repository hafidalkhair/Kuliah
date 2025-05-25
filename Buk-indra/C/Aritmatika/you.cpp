#include <stdio.h>

int main() {
    int pilihan;

    printf("Masukkan pilihan (1-3): ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            printf("Anda memilih pilihan 1.\n");
            break;
        case 2:
            printf("Anda memilih pilihan 2.\n");
            break;
        case 3:
            printf("Anda memilih pilihan 3.\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
    }

    return 0;
}

