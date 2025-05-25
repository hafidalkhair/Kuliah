#include <stdio.h>

int main()
{
    int A;
    
    printf("masukkan bilangan:");
    scanf("%d", &A);

    if (A < 2) {
        printf("%d nasi goreng dan teh manis",A);
        else if (A > 2) 
        printf("%d nasi kuning dan coca cola",A); 
        else if (A == 2 ) 
        printf("%d sate matang dan jus jeruk",A); 
   }
}
