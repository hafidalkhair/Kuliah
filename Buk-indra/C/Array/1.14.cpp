#include <stdio.h>

struct Rekening {
    char pemilik[50];
    double saldo;
};

void deposit(struct Rekening *rek, double jumlah) {
    rek->saldo += jumlah;
}

int main() {
    struct Rekening akun1 = {"Alice", 1000.0};
    deposit(&akun1, 500.0); // Memanggil fungsi dengan pointer ke struktur
    printf("Saldo Akun: %f\n", akun1.saldo);
    return 0;
}

