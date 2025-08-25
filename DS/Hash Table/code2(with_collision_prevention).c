#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];

int n;
// global variable to store the number of elements in the hash table

void initTable()
{
    for (int i=0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }
}

int hashFunction(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int index = hashFunction(key);
    if(hashTable[index] == -1)
    {
        hashTable[index] = key;
    }
    else
    {// Collision prevention using linear probing
        int originalIndex = index;
    }
}

void display()
{
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d -> %d\n", i, hashTable[i]);
    }
}

int main()
{
    initTable();
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    int value;
    for (int i = 0; i<n; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &value);
        insert(value);
    }
    display();
    return 0;
}