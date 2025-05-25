#include <stdio.h>

int main() {
    // Deklarasi dan inisialisasi array tiga dimensi
    const int panjang = 3;
    const int lebar = 3;
    const int tinggi = 3;
    int kubus[panjang][lebar][tinggi];

    // Mengisi array dengan data volume kubus
    for (int i = 0; i < panjang; i++) {
        for (int j = 0; j < lebar; j++) {
            for (int k = 0; k < tinggi; k++) {
                kubus[i][j][k] = (i + 1) * (j + 1) * (k + 1); // Volume kubus
            }
        }
    }

    // Menghitung volume total
    int totalVolume = 0;
    for (int i = 0; i < panjang; i++) {
        for (int j = 0; j < lebar; j++) {
            for (int k = 0; k < tinggi; k++) {
                totalVolume += kubus[i][j][k];
            }
        }
    }

    // Menampilkan hasil
    printf("Data Volume Kubus:\n");
    for (int i = 0; i < panjang; i++) {
        for (int j = 0; j < lebar; j++) {
            for (int k = 0; k < tinggi; k++) {
                printf("Kubus[%d][%d][%d] = %d\n", i, j, k, kubus[i][j][k]);
            }
        }
    }
    printf("Total Volume Kubus: %d\n", totalVolume);

    return 0;
}

