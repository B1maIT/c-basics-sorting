#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* q, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return;

    new_node->data = value;
    new_node->next = NULL;

    if (q->rear != NULL) {
        q->rear->next = new_node;
    }
    q->rear = new_node;

    if (q->front == NULL) {
        q->front = new_node;
    }
}

int dequeue(Queue* q) {
    if (q->front == NULL) return -1;

    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

int front(Queue* q) {
    if (q->front == NULL) return -1;
    return q->front->data;
}

int is_empty(Queue* q) {
    return q->front == NULL;
}

void clear(Queue* q) {
    while (!is_empty(q)) {
        dequeue(q);
    }
}

int main() {
    Queue q = {NULL, NULL};

    // Przykladowe uzycie kolejki
    enqueue(&q, 10);
    enqueue(&q, 20);
    printf("Front: %d\n", front(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));

    // Sprawdzenie, czy kolejka jest pusta
    if (is_empty(&q)) {
        printf("Kolejka jest pusta.\n");
    } else {
        printf("W kolejce sa jeszcze elementy.\n");
    }

    return 0;
}

