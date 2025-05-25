#include <stdio.h>

int main() {
    int num = 10; // variabel integer
    int *ptr; // deklarasi pointer

    ptr = &num; // ptr menunjuk ke alamat memori dari variabel num

    printf("Nilai dari variabel num: %d\n", num);
    printf("Alamat memori dari variabel num: %p\n", &num);
    printf("Nilai yang ditunjuk oleh pointer ptr: %d\n", *ptr); // dereferensi pointer untuk mendapatkan nilai
    printf("Alamat memori yang ditunjuk oleh pointer ptr: %p\n", ptr);

    return 0;
}

