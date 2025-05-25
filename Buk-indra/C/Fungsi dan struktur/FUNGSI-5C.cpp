#include <stdio.h>
#include <math.h>
#include <conio.h>

float absolut(float x) {
    if (x < 0)
        x = -x;
    return x;
}

float akar(float x) {
    float epsilon = 0.00001;
    float guess = 1.0;

    if (x < 0) {
        printf("Argumen Negative!\n");
        return -1.0;
    }

    while (absolut(guess * guess - x) >= epsilon)
        guess = (x / guess + guess) / 2.0;

    return guess;
}

int main() {
    printf("Akar (4.0)     = %f\n", akar(4.0));
    printf("Akar (625.0)   = %f\n", akar(625.0));
    printf("Akar (-39.5)   = %f\n", akar(-39.5));
    getch();
}

