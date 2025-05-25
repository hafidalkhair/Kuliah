#include <stdio.h>

int main() {
    int nilai ;
    
   	rintf("Masukkan Nilai : ");
    scanf("%d", &nilai);

    if (nilai >= 90) {
        printf("Nilai: A\n");
    } else if (nilai >= 80) {
        printf("Nilai: B\n");
    } else if (nilai >= 70) {
        printf("Nilai: C\n");
    } else if (nilai >= 60) {
        printf("Nilai: D\n");
    } else {
        printf("Nilai: E\n");
    }

    return 0;
}

