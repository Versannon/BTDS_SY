# Storage Concepts - File Organization

## Definition

**Storage concepts** deal with how data is physically stored, organized, and accessed in secondary storage (hard disk, SSD) in a DBMS.

## Storage Hierarchy

```
CPU Registers (Extremely fast, limited)
        ↓
L1/L2/L3 Cache (Very fast, small)
        ↓
Main Memory (RAM) - Fast, limited size
        ↓ (slowest transfer)
Secondary Storage (Hard Disk/SSD) - Slow, large capacity
        ↓
Tertiary Storage (Tape) - Very slow, archival
```

## Key Concepts

### 1. Block (or Page)

**Definition**: Minimum unit of disk I/O. When reading/writing from disk, entire block is transferred.

**Characteristics**:
- Typical size: 4KB, 8KB, 16KB
- Fixed size per database system
- All I/O operations in multiples of blocks
- Contains one or more records

**Block Structure**:
```
┌────────────────────────────────┐
│      Disk Block (4KB)          │
├────────────────────────────────┤
│ Block Header                   │
│ ├─ Block ID                    │
│ ├─ Table/Relation ID           │
│ ├─ Free space indicator        │
│ └─ Timestamp                   │
├────────────────────────────────┤
│ Records (stored sequentially)  │
│ ├─ Record 1 (varies)           │
│ ├─ Record 2 (varies)           │
│ └─ Record 3 (partial)          │
├────────────────────────────────┤
│ Free Space                     │
├────────────────────────────────┤
│ Directory/Offset Table         │
│ (pointers to record locations) │
└────────────────────────────────┘
```

**Example**:
```
Block Size: 4096 bytes
Student Record Size: 100 bytes
Records per block: 4096 / 100 = 40 records

To store 1,000,000 student records:
Blocks needed: 1,000,000 / 40 = 25,000 blocks

To read one specific record:
1 block I/O needed (read entire block)
Time: ~5-10ms per block
```

### 2. Record

**Definition**: Collection of related fields representing single entity instance.

**Types**:
- **Fixed-length record**: All records same size
- **Variable-length record**: Records different sizes

**Fixed-Length Record Example**:
```
STUDENT Record:
┌──────────────────────────────────┐
│ StudentID: 4 bytes               │
│ StudentName: 30 bytes (padded)   │
│ Email: 40 bytes (padded)         │
│ GPA: 4 bytes                     │
│ Department: 20 bytes (padded)    │
│ Date_Joined: 4 bytes             │
└──────────────────────────────────┘
Total: 102 bytes per record

Storage efficiency: High (easy calculation)
Retrieval: Fast (can compute location)
Waste: Significant (padding)
```

### 3. File

**Definition**: Collection of records of same type stored sequentially or in organized structure.

**File Types**:

#### Heap File (Unordered)
```
┌─────────────┐
│ Record 5    │
├─────────────┤
│ Record 2    │
├─────────────┤
│ Record 8    │
├─────────────┤
│ Record 1    │
├─────────────┤
│ Record 10   │
└─────────────┘

Order: Random (insertion order)
Pros: Fast INSERT
Cons: Slow SEARCH (full scan required)
```

#### Sorted File (Ordered)
```
┌─────────────┐
│ Record 1    │ (StudentID=1)
├─────────────┤
│ Record 2    │ (StudentID=2)
├─────────────┤
│ Record 5    │ (StudentID=5)
├─────────────┤
│ Record 8    │ (StudentID=8)
├─────────────┤
│ Record 10   │ (StudentID=10)
└─────────────┘

Order: Sorted by key
Pros: Fast SEARCH (binary search), Range queries
Cons: Slow INSERT/UPDATE (must maintain order)
```

#### Indexed File (With index structure)
```
Index Structure          Main File
┌─────────────┐        ┌─────────────┐
│ Key: 1 ────┼────────→│ Record 1    │
├─────────────┤        ├─────────────┤
│ Key: 5 ────┼────────→│ Record 5    │
├─────────────┤        ├─────────────┤
│ Key: 8 ────┼────────→│ Record 8    │
├─────────────┤        ├─────────────┤
│ Key: 10────┼────────→│ Record 10   │
└─────────────┘        └─────────────┘

Pros: Fast SEARCH (via index), Fast INSERT
Cons: Index overhead, UPDATE overhead
```

### 4. Buffer (Cache)

**Definition**: Main memory area holding copies of disk blocks for fast access.

**Purpose**: Reduce disk I/O operations

**Buffer Management**:
```
Buffer Pool (16MB)
├─ Buffer Frame 1 (4KB) ← Disk Block 100
├─ Buffer Frame 2 (4KB) ← Disk Block 243
├─ Buffer Frame 3 (4KB) ← Disk Block 15
├─ Buffer Frame 4 (4KB) ← Disk Block 1000
└─ Free frames

Disk (1TB)
├─ Block 1-100
├─ Block 101-200
├─ Block 243 ← ────────┐
└─ ... (many more)     (in buffer)
```

**Buffer Hit vs Miss**:
```
Buffer Hit:
Query reads StudentID=5
└─ StudentID=5 in buffer already
└─ Return from buffer (fast - nanoseconds)

Buffer Miss:
Query reads StudentID=105
└─ StudentID=105 not in buffer
└─ Fetch from disk (slow - milliseconds)
└─ Store in buffer frame
└─ Return to query
```

**Buffer Replacement Policies**:
- **FIFO**: First In First Out (simple but not optimal)
- **LRU**: Least Recently Used (most common)
- **LFU**: Least Frequently Used
- **Clock**: Approximate LRU (efficient)

### 5. Access Path

**Definition**: Method used to locate records in file.

**Types of Access Paths**:

#### 1. Sequential Access
```
Reading all records in order:

Record 1 → Record 2 → Record 3 → ... → Record N

Time: O(N) where N = number of records
Example: SELECT * FROM STUDENT;
```

#### 2. Direct/Random Access
```
Access specific record directly by location:

STUDENT table, Record#105
└─ Address calculation: Block#2, Offset#15
└─ Jump directly to Block 2, Offset 15

Time: O(1) average
Example: SELECT * WHERE StudentID = 105;
```

#### 3. Index Access
```
Using index structure:

Query: Find StudentID = 105
├─ Search index (binary search on sorted index)
├─ Find pointer to actual block
└─ Fetch from block

Time: O(log N) for index search
Example: SELECT * WHERE Email = 'raj@college.edu' (if indexed)
```

## Storage Organization Example

**Scenario**: STUDENT Table with 1,000,000 records

**Configuration**:
```
Block Size: 4,096 bytes
Record Size: 100 bytes
Records per block: 40
Total blocks needed: 25,000
```

**No Index (Full Scan)**:
```
Query: SELECT * WHERE GPA > 3.7

Approach:
├─ Read Block 1 (40 records)
├─ Check each record (40 comparisons)
├─ Read Block 2 (40 records)
├─ Check each record (40 comparisons)
├─ ... (repeat 25,000 times)
└─ Total: 25,000 block reads

Time: 25,000 × 5ms = 125 seconds (Very slow!)
```

**With Index on GPA**:
```
Query: SELECT * WHERE GPA > 3.7

Approach:
├─ Search GPA index (binary search)
├─ Find first GPA > 3.7 (log 1,000,000 ≈ 20 steps)
├─ Follow index pointers to blocks
├─ Read only blocks containing matching records
└─ Total: ~50 block reads (estimated)

Time: 50 × 5ms = 0.25 seconds (500x faster!)
```

## I/O Operations and Performance

**Disk I/O Time Components**:
```
Total Disk I/O Time = Seek Time + Rotational Delay + Transfer Time

Seek Time: ~5-10ms (move read head)
Rotational Delay: ~3-5ms (wait for disk rotation)
Transfer Time: ~0.5ms per 4KB block
Total per block: ~8-15ms
```

## File Organization Methods Summary

| Method | Structure | Best For | Insert | Search |
|--------|-----------|----------|--------|--------|
| **Heap** | Unordered | Small files | Fast | Slow |
| **Sequential** | Sorted | Range queries | Slow | Fast |
| **Hashed** | Hash table | Exact match | Medium | Very fast |
| **Indexed** | Index + Data | Complex queries | Medium | Fast |
| **B+ Tree** | Tree structure | General purpose | Medium | Very fast |

## Exam Notes

1. **Hierarchy**: Explain storage layers from CPU to tape
2. **Block Concept**: Size, importance for I/O
3. **Record Types**: Fixed vs variable with examples
4. **File Types**: Heap, sorted, indexed with pros/cons
5. **Buffer**: Hit vs miss, replacement policies
6. **Access Paths**: Sequential, direct, indexed with complexity
7. **Performance**: Factors affecting disk I/O
8. **Example Scenarios**: Show calculations for blocks needed, I/O times
9. **Index Impact**: Show how indexing improves performance
10. **Trade-offs**: Storage vs speed considerations