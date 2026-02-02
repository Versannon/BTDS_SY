#include <stdio.h>

#define SIZE 10
int hashTable[SIZE];

// Initialize hash table
void initTable() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;   // -1 means empty
}

// Simple hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert key (no collision handling)
void insert(int key) {
    int index = hashFunction(key);
    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        printf("Collision! Cannot insert %d at index %d\n", key, index);
    }
}

// Search for a key
int search(int key) {
    int index = hashFunction(key);
    if (hashTable[index] == key)
        return index;
    return -1;
}

    // Example: Search for a key by user input
    /*
    int key;
    printf("Enter key to search: ");
    scanf("%d", &key);
    int pos = search(key);
    if (pos != -1)
        printf("Element %d found at index %d\n", key, pos);
    else
        printf("Element %d not found\n", key);
    */

// Display hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d -> %d\n", i, hashTable[i]);
}

int main() {
    initTable();

    // Insert elements (ensure no collisions manually)
    insert(15);
    insert(26);  
    insert(33);

    display();

    // Search for an element
    int key = 33;
    int pos = search(key);
    if (pos != -1)
        printf("Element %d found at index %d\n", key, pos);
    else
        printf("Element %d not found\n", key);

    return 0;
}

/*
Detailed Explanation:
---------------------
1. The program implements a simple hash table using an array of fixed size (SIZE = 10).
2. The hash table is initialized with -1 to indicate empty slots.
3. The hash function is key % SIZE, which determines the index for a given key.
4. The insert() function adds a key to the hash table if the calculated index is empty; otherwise, it reports a collision (no collision resolution is implemented).
5. The search() function checks if a key exists at its hashed index and returns the index if found, or -1 if not found.
6. The display() function prints the current state of the hash table.
7. In main(), the table is initialized, a few elements are inserted, the table is displayed, and a search is performed for a specific key (33).
8. The program demonstrates basic hash table operations without collision handling.
