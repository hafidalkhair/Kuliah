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

// Fungsi untuk mencari elemen dalam linked list
int search(struct Node* head, int key) {
    struct Node* current = head;
    int position = 1;

    // Mencari elemen dengan nilai yang sesuai
    while (current != NULL) {
        if (current->data == key) {
            printf("Node with value %d found at position %d.\n", key, position);
            return 1; // Nilai ditemukan
        }
        current = current->next;
        position++;
    }

    // Jika nilai tidak ditemukan
    printf("Node with value %d not found in the linked list.\n", key);
    return 0; // Nilai tidak ditemukan
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

    // Mencari nilai 7 dalam linked list
    int key = 7;
    if (search(head, key)) {
        printf("Element %d ditemukan di linked list.\n", key);
    } else {
        printf("Element %d tidak ditemukan di linked list.\n", key);
    }

    // Mengosongkan memori yang digunakan oleh linked list (tidak ditampilkan dalam contoh ini)
    return 0;
}

