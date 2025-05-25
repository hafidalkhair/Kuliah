#include <stdio.h>
#include <stdlib.h>

// Struktur simpul
struct Node {
    int data;
    struct Node* next;
};
// Fungsi untuk membuat simpul baru
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
// Fungsi untuk menampilkan linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    // Membuat tiga simpul
    struct Node* firstNode = createNode(1);
    struct Node* secondNode = createNode(2);
    struct Node* thirdNode = createNode(3);
    // Menghubungkan simpul-simpulnya untuk membentuk linked list
    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    // Menampilkan linked list
    printf("Linked List: ");
    printLinkedList(firstNode);
    // Membebaskan memori yang dialokasikan untuk simpul-simpul
    free(firstNode);
    free(secondNode);
    free(thirdNode);
    return 0;
}
