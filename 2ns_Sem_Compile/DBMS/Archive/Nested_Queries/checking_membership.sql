SELECT
    product_id,
    product_name,
    category,
    price
FROM products
WHERE product_id IN (
    SELECT product_id
    FROM order_items
    WHERE order_id IN (
        SELECT order_id
        FROM orders
        WHERE customer_id IN (
            SELECT customer_id
            FROM customers
            WHERE city = 'Mumbai'
        )
    )
);

SELECT
    product_id,
    product_name,
    category,
    price
FROM products
WHERE product_id NOT IN (
    SELECT product_id
    FROM order_items
);
