Also known as CROSS JOIN.

- a join operation where each row from one table is combined with every row from another table.
- I.e., It forms a cartesian product of the two tables.
- e.g.,

1: 

Products Table:

CREATE TABLE products
(
    id INT,
    name VARCHAR(30)
);

Colors Table:

CREATE TABLE colors
(
    id INT,
    color VARCHAR(30)
);

If we perform a cartesian join between the products and colors tables, we would get a result set that includes every combination of product and color. For example:

SELECT *
FROM products
CROSS JOIN colors;