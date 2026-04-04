# B+ Trees

## Definition

A **B+ tree** is a balanced multi-level index structure widely used in DBMS for efficient searching and range queries.

## Key Features

- Balanced tree
- All search keys appear in leaf nodes
- Internal nodes store only index values and pointers
- Leaf nodes are linked for sequential access

## Why B+ Trees Are Preferred

- Fewer disk accesses
- Efficient equality search
- Very efficient range queries
- Maintains sorted order

## Structure

```text
Root
  |
Internal Nodes
  |
Leaf Nodes -> linked -> linked -> linked
```

## Operations

- Search
- Insert
- Delete

## Exam Notes

- Mention that leaf nodes are linked.
- B+ trees are better than simple binary search trees for disk-based storage.
- Good for both exact match and range search.
