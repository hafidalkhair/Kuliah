#include <stdio.h>

struct Mahasiswa {
    char nama[50];
    int usia;
    float nilai;
};

void cetakData(struct Mahasiswa mhs) {
    printf("Nama: %s\n", mhs.nama);
    printf("Usia: %d tahun\n", mhs.usia);
    printf("Nilai: %.2f\n", mhs.nilai);
}

int main() {
    struct Mahasiswa mahasiswa1 = {"Alice", 20, 85.5};
    cetakData(mahasiswa1); // Memanggil fungsi dengan struktur sebagai parameter
    return 0;
}

