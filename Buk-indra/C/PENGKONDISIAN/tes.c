#include <stdio.h>

void main()
{
    int score = 50;
    int hp = 100;

    // membuat pointer dengan isi alamat memori dari hp
    int *ptr_hp = &hp;

    // print isi variabel dan alama memori
    printf("Nama Variabel \t Alamat \t Konten\n");
    printf("score \t\t %x \t %d \n", &score, score);
    printf("hp \t\t %x \t %d \n", &hp, hp);
    printf("ptr_hp \t %x \t %x \n", &ptr_hp, ptr_hp);
    printf("*ptr_hp \t %x \t %d \n", &ptr_hp, *ptr_hp);

    // mengubah data pada alamat memori dengan pointer
    *ptr_hp = 95;

    printf("hp \t\t %x \t %d \n", &hp, hp);
    printf("*ptr_hp \t %x \t %d \n", &ptr_hp, *ptr_hp);
}