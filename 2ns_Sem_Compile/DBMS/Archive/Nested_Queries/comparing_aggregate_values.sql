SELECT
    customer_id,
    customer_name
FROM customers
WHERE customer_id IN (
    SELECT customer_id
    FROM orders
    WHERE order_total > (
        SELECT AVG(order_total)
        FROM orders
    )
);