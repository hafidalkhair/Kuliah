#include <stdio.h>

void hitung_triangular(int n);

int main() {
    hitung_triangular(10);
    hitung_triangular(20);
    hitung_triangular(50);
    return 0;
}

void hitung_triangular(int n) {
    int i, jumlah = 0;
    for (i = 1; i <= n; ++i) {
        jumlah = jumlah + i;
    }
    printf("Jumlah triangular %d adalah %d\n", n, jumlah);
}

