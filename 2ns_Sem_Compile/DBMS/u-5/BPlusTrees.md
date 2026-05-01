# B+ Trees - Comprehensive Guide

## Definition

A **B+ tree** is a self-balancing tree data structure optimized for database and file systems. It ensures balanced height and efficient disk I/O operations by storing keys in internal nodes and data pointers in leaf nodes.

## Why B+ Trees?

### Problem with Binary Search Trees (BST)

```
Unbalanced BST (Worst Case):
1
 \
  2
   \
    3
     \
      4
       \
        5
        
Height: 5 (equals number of nodes)
Search: O(n) - becomes linear search!
Disk I/O: 5 block reads per search
```

### B+ Tree Solution

```
B+ Tree (Balanced):
        [15]
       /    \
    [5,10] [20,25]
    /  |  \   /  |  \
   1-5 6-10 11-15 16-20 21-25
   
Height: log(n) (logarithmic)
Search: O(log n) - very fast
Disk I/O: ~3 block reads (very efficient)
Always balanced regardless of insertion order
```

## B+ Tree Properties

### Definition and Characteristics

**Order m**: Maximum number of children per node

**Constraints**:
1. **Root**: 
   - If leaf: 1 to m-1 keys
   - If internal: 2 to m children

2. **Internal Nodes**:
   - At least ⌈m/2⌉ children
   - At most m children
   - Keys: one less than children

3. **Leaf Nodes**:
   - At least ⌈m/2⌉ keys (except root)
   - At most m-1 keys
   - Linked to siblings (for range queries)
   - Contains actual data pointers

4. **Balanced**: All leaf nodes at same depth

### Visual Example: B+ Tree (Order 5)

```
Max keys per internal node: 4
Max keys per leaf node: 4
Min keys (non-root): 2

                    [30]
                   /    \
            [10,20]      [40,50]
           /  |  \      /   |   \
        [5] [15] [25] [35] [45] [55]
        (Leaf nodes with data pointers)
        
Each leaf linked: [5]←→[15]←→[25]←→[35]←→[45]←→[55]
```

## B+ Tree Operations

### 1. Search

**Procedure**:
```
1. Start at root
2. Compare search key with node keys
3. Follow appropriate pointer
4. Repeat until leaf node
5. Search leaf node (or linear search if not found)
```

**Example - Search 25**:
```
                    [30]         ← Compare 25 with 30
                   /    \         ← 25 < 30, go left
            [10,20]      [40,50]
           /  |  \      /   |   \  ← Compare 25 with 10,20
        [5] [15] [25] [35] [45] [55] ← 25 ≥ 20, go right
                  ↑
              Found in leaf [25]

Complexity: O(log n) - very efficient
```

### 2. Insertion

**Steps**:
1. Find appropriate leaf node
2. Insert key in sorted order
3. If leaf overflows (> m-1 keys):
   - Split leaf into two nodes
   - Move middle key to parent
   - If parent overflows, split parent recursively

**Example - Insert 27 in order-5 tree**:

```
Before Insert:
        [30]
       /    \
    [10,20] [40,50]
    /  |  \  /   |   \
  [5][15][25][35][45][55]

Step 1: Find leaf [25], insert 27
        [25, 27] - OK (≤ 4 keys)

Result:
        [30]
       /    \
    [10,20] [40,50]
    /  |  \  /   |   \
  [5][15][25,27][35][45][55]
```

### 3. Deletion

**Steps**:
1. Find and remove key from leaf
2. If leaf has too few keys (< ⌈m/2⌉):
   - Try borrow from sibling
   - If can't borrow, merge with sibling
   - Adjust parent recursively

**Example - Delete 25**:

```
Before:
    [23, 25, 27]
    
Delete 25:
    [23, 27]
    
Check: ≥ 2 keys required
If sufficient, done
If not, borrow from sibling or merge
```

## B+ Tree vs B Tree

| Aspect | B+ Tree | B Tree |
|--------|---------|--------|
| **Key Location** | In leaf nodes only | In any node |
| **Search** | Always reaches leaf | May stop at internal |
| **Range Query** | Efficient (leaf linked) | Less efficient |
| **Space** | More leaf nodes | Fewer nodes overall |
| **Insertion/Deletion** | Clean (only in leaves) | Complex (anywhere) |
| **Database Use** | Universal standard | Rare |

## Real-World Example: Database Index

**Scenario**: Student database with 100,000 records

```
Without B+ Tree (Full Scan):
  Query: SELECT * WHERE StudentID = 52345
  └─ Read all 100,000 records sequentially
  └─ Time: ~500ms (very slow)

With B+ Tree Index (Order 100):
  
  Index Structure (Height ~3):
            [50000]
           /       \
    [25000]      [75000]
    /  |  \      /  |  \
  [leaf nodes with links]
  
  Search 52345:
  ├─ Start at root: 52345 > 50000 → go right
  ├─ Node [75000]: 52345 < 75000 → go left
  ├─ Reach leaf: find 52345
  └─ Read actual student record
  
  Time: ~3-4 disk I/O operations
  Total: ~20-30ms (16x faster!)
```

## B+ Tree Properties for Exam

### Advantages

1. **Balanced**: Guaranteed O(log n) search
2. **Range Queries**: Efficient with leaf linking
3. **I/O Efficient**: Designed for disk blocks
4. **Insertions/Deletions**: Efficient and clean
5. **Sequential Access**: Very fast with linked leaves

### Limitations

1. **Overhead**: More overhead than BST
2. **Complex**: Insertion/deletion is complex
3. **Space**: May use more space than BST

## Search Performance Comparison

```
Data: 1,000,000 records
Block Size: 4KB
Record Size: 100 bytes
Records per block: 40

Binary Search Tree (Worst): ~20 steps → 20 disk I/O → 100ms
Binary Search Tree (Best): ~3-4 steps → 3 disk I/O → 15ms
B-Tree (Order 128): ~4 steps → 4 disk I/O → 20ms
B+ Tree (Order 128): ~4 steps → 4 disk I/O → 20ms
Sequential Scan: 25,000 reads → 125 seconds

B+ Tree is ~1000x faster than sequential scan!
```

## B+ Tree Implementation in Databases

### MySQL InnoDB

```
Uses B+ Tree for all indexes:
- Primary Key Index: Clustered B+ Tree
- Secondary Indexes: Non-clustered B+ Trees
- Full-text Indexes: Modified B+ Trees
```

### SQL Server

```
Uses B+ Tree for indexes:
- Clustered Index: B+ Tree with data at leaf
- Non-clustered Index: B+ Tree with row locators
```

### PostgreSQL

```
Uses various structures:
- Default: B-Tree (similar to B+)
- Hash Index: Hash table
- GiST/GIN: Specialized structures
```

## Practical Indexing Example

```sql
-- Create B+ Tree index
CREATE INDEX idx_student_id ON STUDENT(StudentID);

-- MySQL uses B+ Tree internally
-- Query benefits from index

EXPLAIN SELECT * FROM STUDENT WHERE StudentID = 52345;
-- Results:
-- ├─ Type: const (single row)
-- ├─ Key: idx_student_id
-- └─ Rows: 1 (exact match)

-- Without index would be:
-- ├─ Type: ALL (full scan)
-- └─ Rows: 100000 (all rows scanned)
```

## Exam Notes

1. **Definition**: Self-balancing tree with keys in leaves only
2. **Properties**: Order, degree, balance guarantees
3. **Operations**: Search, insert, delete with examples
4. **Advantages**: Balanced, I/O efficient, range queries
5. **Comparison**: Explain vs BST and B-Tree
6. **Performance**: Show with numbers how fast it is
7. **Database Implementation**: How DBMSs use B+ Trees
8. **Leaf Linking**: Explain why leaves are linked
9. **Time Complexity**: O(log n) for all operations
10. **Visual Examples**: Draw tree structures showing operations
