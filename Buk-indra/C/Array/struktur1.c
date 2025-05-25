#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    char nama[50];
    int usia;
    float nilai;
};

int main() {
    struct Mahasiswa mahasiswa1;
    //... kode untuk mengisi nilai variabel mahasiswa1 dari input pengguna atau file
    
    struct Mahasiswa mahasiswa2 = mahasiswa1; // Inisialisasi struktur kedua dengan variabel struktur pertama
    //... kode untuk mengakses dan menggunakan variabel mahasiswa2
    
    return 0;
}

