#include <stdio.h>
#define MAX 100

// Queue structure
typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

// Initialize queue
void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

// Check if queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Check if queue is full
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Enqueue operation
void enqueue(Queue* q, int val) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->arr[++(q->rear)] = val;
}

// Dequeue operation
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return val;
}

// Peek operation
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[q->front];
}

// Display queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    int choice, val;
    initQueue(&q);
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                val = dequeue(&q);
                if (val != -1)
                    printf("Dequeued: %d\n", val);
                break;
            case 3:
                val = peek(&q);
                if (val != -1)
                    printf("Front element: %d\n", val);
                break;
            case 4:
                display(&q);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
