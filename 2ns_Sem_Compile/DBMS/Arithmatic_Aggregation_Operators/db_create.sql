DROP TABLE IF EXISTS sales_data;

CREATE TABLE sales_data (
    sale_id INT PRIMARY KEY,
    item_name VARCHAR(50) NOT NULL,
    category VARCHAR(30) NOT NULL,
    unit_price DECIMAL(10,2) NOT NULL,
    quantity INT NOT NULL,
    discount_amount DECIMAL(10,2) NOT NULL
);

INSERT INTO sales_data (sale_id, item_name, category, unit_price, quantity, discount_amount) VALUES
(1, 'Notebook', 'Stationery', 50.00, 12, 5.00),
(2, 'Pen', 'Stationery', 10.00, 25, 1.00),
(3, 'Bag', 'Accessories', 800.00, 4, 50.00),
(4, 'Bottle', 'Utility', 250.00, 9, 20.00),
(5, 'Lamp', 'Electronics', 1200.00, 3, 100.00);
