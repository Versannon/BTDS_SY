# Relational Calculus

## Definition

Relational calculus is a **non-procedural query language** based on predicate logic.

## Main Types

### Tuple Relational Calculus (TRC)

In TRC, variables represent tuples.

General form:

```text
{ t | P(t) }
```

Example:

```text
{ t | t IN Employees AND t.DepartmentID = 3 }
```

SQL equivalent:

```sql
SELECT *
FROM Employees
WHERE DepartmentID = 3;
```

### Domain Relational Calculus (DRC)

In DRC, variables represent attribute values.

General form:

```text
{ <x, y> | P(x, y) }
```

Example:

```text
{ <name> | EXISTS dept (Employees(name, dept) AND dept = 3) }
```

## Difference Between TRC and DRC

| Point | TRC | DRC |
|---|---|---|
| Variable type | Tuple variables | Domain variables |
| Focus | Whole row | Attribute values |
| Query form | `{ t | condition }` | `{ <x, y> | condition }` |

## Safe and Unsafe Expressions

- Safe expressions produce finite, meaningful results.
- Unsafe expressions may produce infinite or unrelated results.

## Exam Notes

- TRC and DRC are both declarative.
- Write the syntax format before giving examples.
- A comparison table is useful for 5-mark questions.
