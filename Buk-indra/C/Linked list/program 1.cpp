#include <stdio.h>
#include <stdlib.h>

struct Node {	// Definisi struktur Node
    int data;
    struct Node* next;
};

int main() {
    // Membuat simpul pertama
    struct Node* head = NULL; // Menunjuk ke simpul pertama dalam linked list
    struct Node* second = NULL; // Menunjuk ke simpul kedua dalam linked list
    struct Node* third = NULL; // Menunjuk ke simpul ketiga dalam linked list

    // Mengalokasikan memori untuk simpul-simpulnya
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Menyimpan data dan mengatur pointer next
    head->data = 1; // Menyimpan data dalam simpul pertama
    head->next = second; // Mengatur pointer next simpul pertama ke simpul kedua

    second->data = 2; // Menyimpan data dalam simpul kedua
    second->next = third; // Mengatur pointer next simpul kedua ke simpul ketiga

    third->data = 3; // Menyimpan data dalam simpul ketiga
    third->next = NULL; // Mengatur pointer next simpul ketiga ke NULL, menandakan akhir dari linked list

    // Traversing dan mencetak data dari linked list
    struct Node* current = head; // Mulai dari simpul pertama
    while (current != NULL) {
        printf("%d -> ", current->data); // Cetak data dari simpul saat ini
        current = current->next; // Pindah ke simpul berikutnya
    }
    printf("NULL\n");

    // Menghapus simpul-simpul (dealokasi memori)
    free(head);
    free(second);
    free(third);

    return 0;
}
