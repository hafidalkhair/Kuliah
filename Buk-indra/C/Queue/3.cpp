#include <stdio.h>

#define MAX_SIZE 5

// Struktur untuk merepresentasikan queue
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Fungsi untuk menambahkan elemen ke dalam queue
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue penuh. Enqueue tidak dapat dilakukan.\n");
        return;
    }

    queue->rear++;
    queue->items[queue->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Fungsi untuk menghapus elemen dari queue
void dequeue(struct Queue* queue) {
    if (queue->front > queue->rear) {
        printf("Queue kosong. Dequeue tidak dapat dilakukan.\n");
        return;
    }

    int removedItem = queue->items[queue->front];
    queue->front++;
    printf("Dequeued: %d\n", removedItem);
}

// Fungsi utama
int main() {
    struct Queue queue = { .front = 0, .rear = -1 };

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    dequeue(&queue);
    dequeue(&queue);

    enqueue(&queue, 40);
    enqueue(&queue, 50);

    return 0;
}

