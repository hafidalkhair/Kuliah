#include <stdio.h>
#include <stdlib.h>

// Definisi struktur Node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    // Alokasi simpul pertama
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Error: Unable to allocate memory for head node.\n");
        exit(-1);
    }

    // Alokasi simpul kedua
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    if (second == NULL) {
        printf("Error: Unable to allocate memory for second node.\n");
        exit(-1);
    }

    // Alokasi simpul ketiga
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    if (third == NULL) {
        printf("Error: Unable to allocate memory for third node.\n");
        exit(-1);
    }

    // Menyimpan data dalam simpul-simpul
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // Menampilkan data dari linked list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Membebaskan memori simpul-simpul
    free(head);
    free(second);
    free(third);

    return 0;
}
