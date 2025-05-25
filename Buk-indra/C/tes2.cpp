#include <stdio.h>

int main() {
    int pilihan;
    
    printf("Selamat datang di restoran fauzan \n");
    printf("Menu Makanan:\n");
    printf("1. Nasi Goreng dan teh manis \n");
    printf("2. nasi kuning dan coca cola \n");
    printf("3. sate matang dan jus jeruk\n");
    
    printf("Silakan pilih menu makanan (1-3): ");
    scanf("%d", &pilihan);
    
    switch(pilihan) {
        case 1:
            printf("Anda memesan Nasi Goreng dan Teh Manis Terima kasih!\n");
            break;
        case 2:
            printf("Anda memesan Nasi Kuning dan Coca Cola  Terima kasih!\n");
            break;
        case 3:
            printf("Anda memesan Sate Matang dan Jus Jeruk Terima kasih!\n");
            break;
        default:
            printf("Pilihan tidak valid. Silakan pilih menu yang benar (1-3).\n");
    
    return 0;


}
