# Database Management Systems

This folder is a cleaned and study-oriented rebuild of the original `DBMS` workspace for **BTDS-211-PCC Database Management Systems**.

## Course Focus

- Unit 1: Database system applications, DBMS architecture, data abstraction, ER model
- Unit 2: Relational model, relational algebra, relational calculus, logical design, views, constraints
- Unit 3: SQL, DDL, DML, queries, joins, triggers, constraints
- Unit 4: Transactions, ACID properties, concurrency control, serializability, recovery
- Unit 5: File organization, storage concepts, indexing, B+ trees, hash indexing

## Folder Structure

```text
DBMS/
├── README.md
├── Archive/
├── Unit-1_Database_System_Applications/
├── Unit-2_Relational_Model/
├── Unit-3_SQL/
├── Unit-4_Transactions/
├── Unit-5_File_Organization/
└── Practical_Codes/
```

## How To Use These Notes

- Start each unit from `Notes.md` or the main note file.
- Use the topic-wise files for quick revision before exams.
- Practice SQL from the `Practical_Codes` folder in MySQL or MySQL Workbench.
- Refer to `Archive/` whenever you want the untouched original classroom material, question banks, or Sakila sample database files.

## How To Run SQL Examples

1. Open MySQL Workbench or MySQL CLI.
2. Run [`create_tables.sql`](/d:/My_Repos/BTDS_SY/2ns_Sem_Compile/DBMS/Practical_Codes/create_tables.sql).
3. Run [`insert_sample_data.sql`](/d:/My_Repos/BTDS_SY/2ns_Sem_Compile/DBMS/Practical_Codes/insert_sample_data.sql).
4. Run the remaining scripts topic-wise:
   - [`relational_queries.sql`](/d:/My_Repos/BTDS_SY/2ns_Sem_Compile/DBMS/Practical_Codes/relational_queries.sql)
   - [`joins_examples.sql`](/d:/My_Repos/BTDS_SY/2ns_Sem_Compile/DBMS/Practical_Codes/joins_examples.sql)
   - [`triggers_examples.sql`](/d:/My_Repos/BTDS_SY/2ns_Sem_Compile/DBMS/Practical_Codes/triggers_examples.sql)
   - [`normalization_examples.sql`](/d:/My_Repos/BTDS_SY/2ns_Sem_Compile/DBMS/Practical_Codes/normalization_examples.sql)
   - [`indexing_examples.sql`](/d:/My_Repos/BTDS_SY/2ns_Sem_Compile/DBMS/Practical_Codes/indexing_examples.sql)

## Source Preservation

All original DBMS files and folders have been moved to [`Archive`](/d:/My_Repos/BTDS_SY/2ns_Sem_Compile/DBMS/Archive) so nothing is lost.

## Exam Strategy

- Revise definitions and diagrams first.
- Memorize differences and comparison tables.
- Practice 5-mark answers from the topic-wise Markdown files.
- Execute the SQL scripts and understand the output of each query.
