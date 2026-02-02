#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

int main() {
    // Step 1: Create first node (head)
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 16;
    head->link = NULL;

    // Step 2: Create second node and link to head
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 64;
    second->link = NULL;
    head->link = second;

    // Step 3: Create third node to be inserted between head and second
    struct Node *middle = (struct Node*)malloc(sizeof(struct Node));
    middle->data = 32;
    middle->link = second;

    // Step 4: Update head to point to the new middle node
    head->link = middle;

    // Step 5: Traverse and print the linked list
    struct Node *current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d - ", current->data);
        current = current->link;
    }
    printf("NULL\n");

    return 0;
}

/*
Explanation:

1. struct Node:
   - Defines a node with an integer data and a pointer to the next node.

2. First Two Nodes:
   - head: contains 16 and points to second.
   - second: contains 64 and points to NULL.

3. Inserting in Between:
   - A new node 'middle' with data 32 is created.
   - middle's link points to 'second'.
   - head's link is updated to point to 'middle', inserting it between head and second.

4. Final List:
   - 16 → 32 → 64 → NULL
*/
