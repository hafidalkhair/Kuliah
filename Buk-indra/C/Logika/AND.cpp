#include <stdio.h>

int main() {
    int kondisi1 = 1;
    int kondisi2 = 1;

    if (kondisi1 && kondisi2) {
        printf("Kedua kondisi benar (AND).\n");
    } else {
        printf("Salah satu atau kedua kondisi salah (AND).\n");
    }
    return 0;
}

