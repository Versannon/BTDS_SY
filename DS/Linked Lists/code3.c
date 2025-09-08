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

void traverse()