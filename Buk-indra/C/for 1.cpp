#include <stdio.h>

int main() {
    int i;

    for (i = 3; i <= 12; i += 3) 
        for (j = 1; j <= 3; j++) {
            printf("%d\n", i);
        }
    

    return 0;
}
