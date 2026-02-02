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
    {
        printf("Collision occurred for key %d at index %d\n", key, index);
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

/*
----------------------- EXPLANATION OF THE CODE -----------------------

1. HEADER FILE
   - #include <stdio.h>
     -> Includes standard input-output library in C.
     -> Required for printf() and scanf() functions.

2. MACRO DEFINITION
   - #define SIZE 10
     -> Defines SIZE as 10 (the hash table capacity).
     -> Means the hash table has 10 slots: indices 0–9.

3. GLOBAL VARIABLES
   - int hashTable[SIZE];
     -> Declares the hash table as an integer array of size 10.
     -> Stores the keys at calculated indices.
   - int n;
     -> Stores the number of elements user wants to insert.

4. FUNCTION: initTable()
   - Initializes the hash table.
   - Loop runs from 0 to SIZE-1.
   - Each slot is filled with -1 to indicate "empty".

5. FUNCTION: hashFunction(int key)
   - Input: key (integer value to insert).
   - Returns: key % SIZE
     -> Ensures the index is always within 0–9.
     -> Example: key = 25 → index = 25 % 10 = 5.

6. FUNCTION: insert(int key)
   - Finds index using hashFunction.
   - Checks if that index in the hashTable is empty (-1).
     -> If empty: places the key there.
     -> If not empty: prints a message "Collision occurred".
   - Note: No collision resolution implemented yet (just reports it).

7. FUNCTION: display()
   - Prints the full hash table.
   - Shows each index and the value stored.
   - If no value was inserted, it remains -1.

8. MAIN FUNCTION
   - Calls initTable() to initialize the table.
   - Asks user for number of elements to insert (stored in n).
   - For each element:
     -> Reads value from user.
     -> Calls insert(value).
   - Finally calls display() to print the hash table.

----------------------- SAMPLE OUTPUT -----------------------
Enter number of elements to insert: 4
Enter element 1: 15
Enter element 2: 25
Enter element 3: 12
Enter element 4: 22

Collision occurred for key 25 at index 5
Collision occurred for key 22 at index 2

Hash Table:
0 -> -1
1 -> -1
2 -> 12
3 -> -1
4 -> -1
5 -> 15
6 -> -1
7 -> -1
8 -> -1
9 -> -1

(Explanation: 15 → index 5, 25 → index 5 (collision), 12 → index 2, 22 → index 2 (collision)).

-----------------------------------------------------------------
This program demonstrates:
- How to initialize a hash table.
- How to compute an index with a hash function.
- How to insert values into the hash table.
- How collisions can occur when two keys map to the same index.
-----------------------------------------------------------------
*/
