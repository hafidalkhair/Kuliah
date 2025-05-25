#include <stdio.h>

int main() {
    int choice;

    while (1) {
        printf("Menu Makanan\n");
        printf("1. Tampilkan Menu\n");
        printf("Gak Menerima Bon. /0 kembali \n");

        printf("Pilih opsi (1/2/3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            printf("Menu Makanan:\n");
            printf("1. Nasi Goreng\n");
            printf("2. Teh Manis\n");
            break;
            
            case 2:
            printf("Menu Makanan:\n");
            printf("1. Nasi Kuning\n");
            printf("2. Coca Cola\n");
            break;
            
            case 3:
            printf("Menu Makanan:\n");
            printf("1. Sate Matang\n");
            printf("2. Jus Jeruk\n");
            break;
            
            case 0:
                printf("Terimakasih telah datang ke Resto.\n");
                return 0; // Keluar dari program
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    }

}

