#include <stdio.h>
#include <stdlib.h>

struct link{
    int data;
    struct link *next;
};

struct link *structku; // Mengubah definisi structku

int main(){
    int i=0;
    structku = (struct link*)malloc(sizeof(struct link));
    structku->data=2;

    // Struct kedua
    structku->next=(struct link*)malloc(sizeof(struct link));
    structku->next->data=4;

    // Struct ketiga
    structku->next->next=(struct link*)malloc(sizeof(struct link));
    structku->next->next->data=6;
    structku->next->next->next=NULL; // Akhir data linked list

    // Tampilkan isi struct
    struct link *penunjuk = structku; // Inisialisasi penunjuk
    while(penunjuk!=NULL){
        i++;
        printf("Struct ke-%d : %d\n", i, penunjuk->data);
        penunjuk=penunjuk->next;
    }

    // Membebaskan memori
    free(structku->next->next); // Bebaskan memori untuk struct ketiga
    free(structku->next); // Bebaskan memori untuk struct kedua
    free(structku); // Bebaskan memori untuk struct pertama

    return 0;
}
