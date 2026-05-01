# Diagrams

## Three Levels of Abstraction

```text
+----------------------------------+
| View Level (External Level)      |
| User-specific views              |
+----------------------------------+
| Logical Level (Conceptual Level) |
| Tables, attributes, relations    |
+----------------------------------+
| Physical Level (Internal Level)  |
| Files, blocks, indexes           |
+----------------------------------+
```

## Basic DBMS Structure

```text
Users
  |
  v
+-------------------+
| Query Processor   |
+-------------------+
  |
  v
+-------------------+
| Storage Manager   |
+-------------------+
  |
  v
+-------------------+
| Database          |
+-------------------+
```

## ER Symbols

```text
[Rectangle]      -> Entity
(Oval)           -> Attribute
<Diamond>        -> Relationship
[[Rectangle]]    -> Weak Entity
((Oval))         -> Multivalued Attribute
(- - Oval - -)   -> Derived Attribute
```

## Cardinality Diagram

```text
One-to-One
[PERSON] ---- [PASSPORT]

One-to-Many
[DEPARTMENT] ----< [EMPLOYEE]

Many-to-Many
[STUDENT] >----< [COURSE]
```

## Exam Notes

- These diagrams are short and easy to reproduce in written exams.
- Label every level or symbol clearly.
