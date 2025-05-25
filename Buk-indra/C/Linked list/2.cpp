#include <stdio.h>
#include <stdlib.h>

// Struktur untuk merepresentasikan node dalam linked list
struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk menambahkan elemen di awal linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Fungsi untuk menampilkan elemen-elemen dalam linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Fungsi untuk menghapus elemen dari linked list berdasarkan nilai
void deleteNode(struct Node** head, int key) {
    struct Node *current = *head, *prev = NULL;

    // Jika node pertama memiliki nilai yang sesuai
    if (current != NULL && current->data == key) {
        *head = current->next;
        free(current);
        printf("Node with value %d deleted from the linked list.\n", key);
        return;
    }

    // Mencari node dengan nilai yang sesuai
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    // Jika node tidak ditemukan
    if (current == NULL) {
        printf("Node with value %d not found in the linked list.\n", key);
        return;
    }

    // Menghapus node yang ditemukan
    prev->next = current->next;
    free(current);
    printf("Node with value %d deleted from the linked list.\n", key);
}

int main() {
    struct Node* head = NULL;

    // Menambahkan elemen ke awal linked list
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 9);

    // Menampilkan linked list
    printf("Linked List: ");
    display(head);

    // Menghapus node dengan nilai 7
    deleteNode(&head, 7);

    // Menampilkan linked list setelah penghapusan
    printf("Linked List after deletion: ");
    display(head);

    // Mengosongkan memori yang digunakan oleh linked list (tidak ditampilkan dalam contoh ini)
    return 0;
}

