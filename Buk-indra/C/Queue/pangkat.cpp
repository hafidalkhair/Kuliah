#include <stdio.h>
double pangkat(double x, int n) {
    if (n == 0) {
        return 1;
    } else if (n > 0) {
        return x * pangkat(x, n - 1);
    } else {
        return 1 / (x * pangkat(x, -n - 1));
    }
}
int main() {
    double angka;
    int pangkat;
    printf("Masukkan angka: ");
    scanf("%lf", &angka);
    printf("Masukkan pangkat (bilangan bulat): ");
    scanf("%d", &pangkat);
    printf("%.2lf^%d = %.4lf\n", angka, pangkat, pangkat(angka, pangkat));
    return 0;
}

