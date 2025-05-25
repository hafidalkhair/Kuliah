#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Alokasi memori gagal\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Simpul sebelumnya tidak boleh NULL\n");
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(1);
    struct Node* secondNode = createNode(3);
    head->next = secondNode;

    // Menyisipkan simpul baru di antara simpul pertama dan kedua
    insertAfter(head, 2);

    // Menampilkan linked list
    printf("Linked List: ");
    printLinkedList(head);

    // Membebaskan memori yang dialokasikan untuk simpul-simpul
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

