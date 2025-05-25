#include <stdio.h>
#include <string.h>
#include <conio.h>

struct tanggal {
    int tgl;
    int bln;
    int tahun;
};

struct orang {
    char nama[30];
    struct tanggal lahir;
};

struct orang siswa;

int main() {
    strcpy(siswa.nama, "L HAFIDL ALKHAIR");
    siswa.lahir.tgl = 27;
    siswa.lahir.bln = 01;
    siswa.lahir.tahun = 2006;
    printf("Nama        : %s\n", siswa.nama);
    printf("Tanggal     : %d-%d-%d\n",
    	siswa.lahir.tgl,siswa.lahir.bln,siswa.lahir.tahun);
    	getch();
}

