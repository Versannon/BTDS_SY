#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct node{
    int data;
    struct node* left;
    struct node* right;
};

//Function to create a new node

struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//Inorder traversal Function
void intraversal(struct node* root)
{
    if(root != NULL)
    {
        intraversal(root->left);
        printf("%d", root->data);
        intraversal(root->right);
    }
}

int main()
{
    //create a tree
    struct node* root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);

    printf("Inorder Traversal :");
    intraversal(root);
    return 0;
}