create database assign;
use assign;
DROP TABLE IF EXISTS order_items;
DROP TABLE IF EXISTS orders;
DROP TABLE IF EXISTS customers;
DROP TABLE IF EXISTS products;

CREATE TABLE customers (
    customer_id INT PRIMARY KEY,
    customer_name VARCHAR(50) NOT NULL,
    city VARCHAR(50) NOT NULL
);

CREATE TABLE products (
    product_id INT PRIMARY KEY,
    product_name VARCHAR(50) NOT NULL,
    category VARCHAR(50) NOT NULL,
    price DECIMAL(10,2) NOT NULL
);

CREATE TABLE orders (
    order_id INT PRIMARY KEY,
    customer_id INT NOT NULL,
    order_total DECIMAL(10,2) NOT NULL,
    FOREIGN KEY (customer_id) REFERENCES customers(customer_id)
);

CREATE TABLE order_items (
    order_item_id INT PRIMARY KEY,
    order_id INT NOT NULL,
    product_id INT NOT NULL,
    quantity INT NOT NULL,
    FOREIGN KEY (order_id) REFERENCES orders(order_id),
    FOREIGN KEY (product_id) REFERENCES products(product_id)
);

INSERT INTO customers (customer_id, customer_name, city) VALUES
(1, 'Aarav', 'Mumbai'),
(2, 'Diya', 'Pune'),
(3, 'Kabir', 'Delhi'),
(4, 'Meera', 'Bengaluru'),
(5, 'Rohan', 'Chennai');

INSERT INTO products (product_id, product_name, category, price) VALUES
(101, 'Laptop', 'Electronics', 60000.00),
(102, 'Mouse', 'Electronics', 1200.00),
(103, 'Chair', 'Furniture', 4500.00),
(104, 'Desk', 'Furniture', 8500.00);

INSERT INTO orders (order_id, customer_id, order_total) VALUES
(1001, 1, 61200.00),
(1002, 2, 5700.00),
(1003, 3, 68500.00),
(1004, 4, 9700.00);

INSERT INTO order_items (order_item_id, order_id, product_id, quantity) VALUES
(1, 1001, 101, 1),
(2, 1001, 102, 1),
(3, 1002, 103, 1),
(4, 1002, 102, 1),
(5, 1003, 101, 1),
(6, 1003, 104, 1),
(7, 1004, 103, 2),
(8, 1004, 102, 1);
