#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure
typedef struct {
    Node* top;
} Stack;

// Initialize stack
void initStack(Stack* s) {
    s->top = NULL;
}

// Push operation
void push(Stack* s, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop operation
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    Node* temp = s->top;
    int val = temp->data;
    s->top = s->top->next;
    free(temp);
    return val;
}

// Peek operation
int peek(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->top->data;
}

// Display stack
void display(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    Node* temp = s->top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack s;
    int choice, val;
    initStack(&s);
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(&s, val);
                break;
            case 2:
                val = pop(&s);
                if (val != -1)
                    printf("Popped: %d\n", val);
                break;
            case 3:
                val = peek(&s);
                if (val != -1)
                    printf("Top element: %d\n", val);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
