#include <stdio.h>

struct Mahasiswa {
    char nama[50];
    int usia;
    float nilai;
    char alamat[40];
};

void cetakData(struct Mahasiswa mhs) {
    printf("Nama: %s\n", mhs.nama);
    printf("Usia: %d tahun\n", mhs.usia);
    printf("Nilai: %.2f\n", mhs.nilai);
    printf("Alamat : %s\n",mhs.alamat);
    printf("\n");
}

main() {
    struct Mahasiswa mahasiswa1 = {"Alice", 20, 85.5,"West blue"};
    cetakData(mahasiswa1); // Memanggil fungsi dengan struktur sebagai parameter

    struct Mahasiswa mahasiswa2 = {"Hafid", 18, 90.00,"East Blue"};
    cetakData(mahasiswa2);
    
    struct Mahasiswa mahasiswa3 = {"Lucie",19, 88.85,"Wano"};
    cetakData(mahasiswa3);
    return 0;
}

