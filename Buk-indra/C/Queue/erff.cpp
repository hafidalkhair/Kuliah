#include <stdio.h>
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int main() {
    int n;
    printf("Masukkan jumlah bilangan dalam deret Fibonacci: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Masukkan jumlah bilangan positif.\n");
    } else {
        printf("Deret Fibonacci:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }
    return 0;
}

