#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
};

int main() {
    // Step 1: Create first node (head)
    struct DNode *head = (struct DNode*)malloc(sizeof(struct DNode));
    head->data = 16;
    head->prev = NULL;
    head->next = NULL;

    // Step 2: Create second node and link to head
    struct DNode *second = (struct DNode*)malloc(sizeof(struct DNode));
    second->data = 64;
    second->prev = head;
    second->next = NULL;
    head->next = second;

    // Step 3: Create third node to be inserted between head and second
    struct DNode *middle = (struct DNode*)malloc(sizeof(struct DNode));
    middle->data = 32;
    middle->prev = head;
    middle->next = second;
    head->next = middle;
    second->prev = middle;

    // Step 4: Traverse and print the doubly linked list (forward)
    struct DNode *current = head;
    printf("Doubly Linked List (forward): ");
    while (current != NULL) {
        printf("%d - ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Step 5: Traverse and print the doubly linked list (backward)
    current = second; // last node
    printf("Doubly Linked List (backward): ");
    while (current != NULL) {
        printf("%d - ", current->data);
        current = current->prev;
    }
    printf("NULL\n");

    return 0;
}

/*
Explanation:

1. struct DNode:
   - Defines a node with integer data, a pointer to the previous node, and a pointer to the next node.

2. First Two Nodes:
   - head: contains 16, prev is NULL, next points to middle.
   - second: contains 64, prev points to middle, next is NULL.

3. Inserting in Between:
   - A new node 'middle' with data 32 is created.
   - middle's prev points to head, next points to second.
   - head's next is updated to middle, second's prev is updated to middle.

4. Final List:
   - Forward: 16 ↔ 32 ↔ 64 ↔ NULL
   - Backward: 64 ↔ 32 ↔ 16 ↔ NULL
*/
