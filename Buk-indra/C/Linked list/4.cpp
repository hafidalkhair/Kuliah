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

// Fungsi untuk menghitung jumlah elemen dalam linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;

    // Menghitung jumlah node dalam linked list
    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
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

    // Menghitung jumlah elemen dalam linked list
    int nodeCount = countNodes(head);
    printf("Jumlah Node dalam linked list: %d\n", nodeCount);

    return 0;
}

