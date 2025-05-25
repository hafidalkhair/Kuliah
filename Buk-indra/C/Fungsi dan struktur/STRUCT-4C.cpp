#include <stdio.h>
#include <string.h>

struct entry {
    char kata[10];
    char definisi[50];
};

int sama_str(char str1[], char str2[]) {
    return strcmp(str1, str2) == 0;
}

int lihat(struct entry kamus[], char cari[], int jumlah) {
    int i;

    for (i = 0; i < jumlah; ++i) {
        if (sama_str(cari, kamus[i].kata)) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct entry kamus[100] = {
        {"komodo", "Kayaknya di sulawesi ada tuh"},
        {"unta", "Lahirnya di mesir tapi gak bisa bahasa arab"},
        {"Kangguru", "Suka melompat di australia"},
        {"kingkong", "Lawannya superman kali"},
        {"harimau", "Belang-belang dan ada di kalimantan"},
        {"kobra", "Ular dari india"},
        {"kancil", "Suka nyolong timun"},
        {"iguana", "Mahal harganya loh"},
        {"nyamuk", "Nakal suka sedot sana sini"},
        {"tikus", "Suka ngegoda cewek cakep"},
        {"buaya", "Wah ini sih intrinya pakaya"}
    };

    int banyaknya = 11;
    char kata[10];
    int angka_masukan;

    printf("Masukkan kata: ");
    scanf("%s", kata);
    angka_masukan = lihat(kamus, kata, banyaknya);
    if (angka_masukan != -1) {
        printf("%s\n", kamus[angka_masukan].definisi);
    } else {
        printf("Maaf, kata itu tidak ada dalam kamus.\n");
    }

    return 0;
}

