#include <stdio.h>

struct Point {
    int x;
    int y;
};

struct Point tambahPoint(struct Point p1, struct Point p2) {
    struct Point hasil;
    hasil.x = p1.x + p2.x;
    hasil.y = p1.y + p2.y;
    return hasil;
}

int main() {
    struct Point titik1 = {1, 2};
    struct Point titik2 = {3, 4};
    struct Point hasil = tambahPoint(titik1, titik2); // Memanggil fungsi dan mengembalikan struktur
    printf("Hasil Penambahan: x = %d, y = %d\n", hasil.x, hasil.y);
    return 0;
}

