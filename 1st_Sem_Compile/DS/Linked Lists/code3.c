/*
code3:
- Create a singly linked list.
- perform insertion, deletion, and traversal operations.
*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};


// Traverse and print the list
void traverse(struct Node* head) {
    struct Node* temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

// Insert at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
}

// Delete a node with given key
void deleteNode(struct Node** head, int key) {
    struct Node *temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->link;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->link;
    }
    if (temp == NULL) return;
    prev->link = temp->link;
    free(temp);
}

int main() {
    struct Node* head = NULL;
    int choice, val;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Traverse\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertEnd(&head, val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteNode(&head, val);
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}