#include <stdio.h>

int main() {
    char jawaban;

    printf("Apakah Anda ingin melanjutkan (y/n)? ");
    scanf(" %c", &jawaban);

    while (jawaban == 'y' || jawaban == '1'|| jawaban == 'Y') {
        printf("Lanjutkan permainan...\n");
        printf("Apakah Anda ingin melanjutkan (y/n)? ");
        scanf(" %c", &jawaban);
    }

    printf("Permainan selesai.\n");

    return 0;
}

