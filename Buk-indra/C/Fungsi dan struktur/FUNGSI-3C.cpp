#include <stdio.h>

int fpb(int u, int v);

int main() {
    printf("FPB dari %d dan %d adalah %d\n", 150, 35, fpb(150, 35));
    printf("FPB dari %d dan %d adalah %d\n", 1026, 405, fpb(1026, 405));
    printf("FPB dari %d dan %d adalah %d\n", 83, 240, fpb(83, 240));
    return 0;
}

int fpb(int u, int v) {
    int tampung;
    while (v != 0) {
        tampung = u % v;
        u = v;
        v = tampung;
    }
    return u;
}

