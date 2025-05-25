#include <stdio.h>
#include <stdlib.h>

// Struktur Node untuk merepresentasikan node dalam linked list
struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk menambahkan node baru di akhir linked list
void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menampilkan isi linked list
void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Inisialisasi linked list kosong
    
    // Menambahkan beberapa node ke linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    
    // Menampilkan isi linked list
    printLinkedList(head);
    
    // Membebaskan memori yang digunakan oleh linked list
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}

