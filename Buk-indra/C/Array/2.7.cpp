#include <stdio.h>

int hitungLuas(int panjang, int lebar) {
    int luas = panjang * lebar;
    return luas;
}

int main() {
    int panjang = 5;
    int lebar = 3;
    int hasilLuas = hitungLuas(panjang, lebar);
    printf("Luas persegi panjang: %d\n", hasilLuas);
    return 0;
}

