#include <stdio.h>

int main() {
    int nilai;

    printf("Masukkan nilai ujian: ");
    scanf("%d", &nilai);

    if (nilai >= 60) {
        printf("Anda lulus ujian.\n");
    } else {
        printf("Anda tidak lulus ujian.\n");
    }

    return 0;
}

