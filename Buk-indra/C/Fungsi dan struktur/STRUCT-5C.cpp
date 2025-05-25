#include <stdio.h>

struct waktu {
    int jam;
    int menit;
    int detik;
};

struct waktu time_update(struct waktu now) {
    struct waktu new_time = now;
    ++new_time.detik;

    if (new_time.detik == 60) {
        new_time.detik = 0;
        ++new_time.menit;
        if (new_time.menit == 60) {
            new_time.menit = 0;
            ++new_time.jam;
            if (new_time.jam == 24) {
                new_time.jam = 0;
            }
        }
    }
    return new_time;
}

int main() {
    struct waktu tes[5] = {
        {11, 59, 59}, {12, 0, 0}, {1, 29, 59}, {23, 59, 59}, {19, 12, 57}
    };

    int i;

    for (i = 0; i < 5; ++i) {
        printf("Waktu adalah %.2d:%.2d:%.2d", tes[i].jam, tes[i].menit, tes[i].detik);
        tes[i] = time_update(tes[i]); 
        printf("...satu detik berikutnya %.2d:%.2d:%.2d\n\n", tes[i].jam, tes[i].menit, tes[i].detik);
    }

    return 0;
}
