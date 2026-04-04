# Hash Indexing

## Definition

Hash indexing uses a hash function to compute the location of a record or bucket.

## Working Principle

```text
Search Key -> Hash Function -> Bucket Address -> Record
```

## Advantages

- Very fast equality search
- Simple access path for exact matches

## Limitations

- Not suitable for range queries
- Bucket overflow may occur

## Static and Dynamic Hashing

### Static Hashing

- Number of buckets fixed
- Overflow chains may form

### Dynamic Hashing

- Number of buckets can grow
- Better for changing file sizes

## Exam Notes

- Write that hashing is ideal for exact search, not for range search.
- Compare hashing with B+ tree if asked:
  - B+ tree for range queries
  - Hashing for equality queries
