#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[80], str2[80], *ptrx;

    strcpy(str1, "INI ADALAH HURUF BESAR SEMUA!!!");
    strcpy(str2, "ini adalah huruf kecil semua!!!");

    ptrx = (char *)calloc(80, sizeof(char));
    strcpy(ptrx, strlwr(str1));

    printf("Isi str1 = "); puts(str1);
    printf("Isi str2 = "); puts(str2);
    printf("Isi ptrx = "); puts(ptrx);

    ptrx = strupr(str2);
    printf("\nSetelah 'str2' diproses dengan strupr()\n");
    printf("Isi str2 = "); puts(str2);
    printf("Isi ptrx = "); puts(ptrx);

    free(ptrx); // Dealokasi memori yang dialokasikan dengan calloc

    return 0;
}

