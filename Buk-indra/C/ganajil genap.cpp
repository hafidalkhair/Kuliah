#include <stdio.h>
#include <string.h>

int main() {
    char pilihan[100];

    printf("Menu Pilihan Makanan dan Minuman:\n");
    printf("1. Nasi Goreng dan Teh Manis\n");
    printf("2. Nasi Kuning dan Coca Cola\n");
    printf("3. Sate Matang dan Jus Jeruk\n");
    printf("Silakan pilih menu (1/2/3): ");
    
    // Menggunakan fgets untuk membaca input sebagai string
    fgets(pilihan, sizeof(pilihan), stdin);
    
    // Menghapus karakter newline ('\n') dari input
    pilihan[strcspn(pilihan, "\n")] = '\0';

    if (strcmp(pilihan, "1") == 0) {
        printf("Anda memesan: Nasi Goreng dan Teh Manis\n");
    } else if (strcmp(pilihan, "2") == 0) {
        printf("Anda memesan: Nasi Kuning dan Coca Cola\n");
    } else if (strcmp(pilihan, "3") == 0) {
        printf("Anda memesan: Sate Matang dan Jus Jeruk\n");
    } else {
        printf("Pilihan tidak valid\n");
    }
}
