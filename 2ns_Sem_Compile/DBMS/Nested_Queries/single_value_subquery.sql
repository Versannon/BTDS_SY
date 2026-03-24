SELECT
    order_id,
    customer_id,
    order_total
FROM orders
WHERE order_total = (
    SELECT MAX(order_total)
    FROM orders
);
