# DBMS Unit Two Question Paper

## Instructions
- Answer all questions.
- Each question carries 5 marks.

### Questions:

1. **Normalization**: Define normalization and explain the different normal forms with examples.

   **Answer**: Normalization is the process of organizing a database to reduce redundancy and improve data integrity. The various normal forms are:
   - **First Normal Form (1NF)**: Ensures that each column contains atomic values and there are no repeating groups.
   - **Second Normal Form (2NF)**: Achieved when it is in 1NF and all non-key attributes are fully functional dependent on the primary key.
   - **Third Normal Form (3NF)**: In 2NF and no transitive dependencies exist.

2. **Transactions**: What is a database transaction? Describe its properties.

   **Answer**: A database transaction is a sequence of operations performed as a single logical unit of work. The properties of transactions can be remembered using the acronym ACID:
   - **Atomicity**: Ensures that all operations in a transaction are completed successfully or none at all.
   - **Consistency**: Ensures that a transaction takes the database from one valid state to another.
   - **Isolation**: Ensures that transactions are executed independently of each other.
   - **Durability**: Guarantees that once a transaction has been committed, it will remain so even in the event of a system failure.

3. **Indexing**: Explain the purpose of indexing in databases and discuss different types of indexes.

   **Answer**: Indexing is a data structure technique used to quickly locate and access the data in a database table. Different types of indexes include:
   - **Single-column Indexes**: Index based on a single column.
   - **Composite Indexes**: Index based on multiple columns.
   - **Unique Indexes**: Ensures that all values in a column are unique.

4. **Query Optimization**: What are some techniques for optimizing SQL queries?

   **Answer**: Techniques for optimizing SQL queries include:
   - **Using Proper Indexing**: Helps speed up data retrieval.
   - **Avoiding SELECT ***: Instead, specify only the columns needed.
   - **Using Joins Wisely**: Understand how joins can impact query performance.
   - **Limiting Results**: Use `LIMIT` to retrieve only necessary records.

5. **Normalization**: Discuss the implications of database normalization on data retrieval performance.

   **Answer**: Normalization can lead to more complex queries and possibly slower retrieval times due to the need for joins. However, it greatly improves data integrity.

6. **Transactions**: Describe how the ACID properties of transactions support reliable database operations.

   **Answer**: The ACID properties ensure that transactions are processed reliably, maintain data integrity, and can withstand system failures.

7. **Indexing**: Discuss the potential downsides of using indexes in a database.

   **Answer**: While indexes improve query performance, they can increase the time required for data modification operations (INSERT, UPDATE, DELETE) and can consume additional disk space.

8. **Query Optimization**: Explain how query execution plans can help in optimizing SQL queries.

   **Answer**: Query execution plans provide insight into how a query is executed by the database engine, helping identify inefficient operations or potential areas for optimization.

9. **Normalization**: How does denormalization differ from normalization, and when is it used?

   **Answer**: Denormalization is the process of combining tables to reduce the complexity of queries. It is used when performance improvements are necessary, especially in read-heavy systems.

10. **Transactions**: What are the differences between optimistic and pessimistic concurrency control in databases?

   **Answer**: Optimistic concurrency control assumes that conflicts are rare and allows transactions to proceed without acquiring locks, while pessimistic concurrency control assumes conflicts may occur and locks resources until the transaction is complete.