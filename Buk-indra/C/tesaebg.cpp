#include <stdio.h>

int main() {
    int angka1 = 5, angka2 = 10;
    int *ptr1, *ptr2, temp;

    // Menggunakan pointer untuk menyimpan alamat variabel
    ptr1 = &angka1;
    ptr2 = &angka2;
 printf("Sebelum pertukaran:\n");
    printf("angka1 = %d\n", angka1);
    printf("angka2 = %d\n", angka2);
    // Menukar nilai variabel menggunakan pointer
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

    printf("Setelah pertukaran:\n");
    printf("angka1 = %d\n", angka1);
    printf("angka2 = %d\n", angka2);

    return 0;
}

