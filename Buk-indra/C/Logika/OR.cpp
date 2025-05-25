#include <stdio.h>

int main() {
    int kondisi1 = 1;
    int kondisi2 = 0;

    if (kondisi1 || kondisi2) {
        printf("Salah satu atau kedua kondisi benar (OR).\n");
    } else {
        printf("Kedua kondisi salah (OR).\n");
    }

    return 0;
}

