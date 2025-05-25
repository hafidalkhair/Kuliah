#include <stdio.h>
#include <conio.h>

struct tanggal {
    int tgl;
    int bln;
    int thn;
};

void cetak_tgl(struct tanggal now) {
    static char *bulan[] = {
        "Kode bulan salah",
        "Januari","Februari","Maret","April","Mei","Juni",
        "Juli","Agustus","September","Oktober","November","Desember"
    };

    printf("\nTanggal sekarang adalah: ");
    printf("%d %s %d\n", now.tgl, bulan[now.bln], now.thn);
}

int main() {
    struct tanggal skr;

    printf("Masukkan tanggal hari ini (tgl/bulan/tahun): ");
    scanf("%d/%d/%d", &skr.tgl, &skr.bln, &skr.thn);

    cetak_tgl(skr);

    getch();
    return 0;
}
