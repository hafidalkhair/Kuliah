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

int main() {
    struct Node* head = NULL;
    
    // Menambahkan elemen ke awal linked list
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 9);
    
    // Menampilkan linked list
    printf("Linked List: ");
    display(head);
        
    return 0;
}

