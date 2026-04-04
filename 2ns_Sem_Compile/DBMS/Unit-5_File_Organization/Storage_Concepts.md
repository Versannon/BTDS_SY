# Storage Concepts

## Definition

Storage concepts in DBMS explain how data is physically stored, accessed, and managed on secondary storage.

## Main Terms

- File
- Record
- Block
- Buffer
- Access path

## File Organization Methods

### Heap File Organization

- Records placed wherever space is available
- Fast insertion
- Slower search

### Sequential File Organization

- Records stored in sorted order
- Good for sequential processing
- Insertions may be costly

### Hashed File Organization

- Uses hash function to locate records quickly
- Good for equality search

## Exam Notes

- Differentiate heap, sequential, and hashed organization.
- Mention that physical storage is part of the internal level of abstraction.
