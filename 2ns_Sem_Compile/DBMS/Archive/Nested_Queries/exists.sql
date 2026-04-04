SELECT
    customer_id,
    customer_name
FROM customers c
WHERE EXISTS (
    SELECT 1
    FROM orders o
    WHERE o.customer_id = c.customer_id
      AND EXISTS (
          SELECT 1
          FROM order_items oi
          WHERE oi.order_id = o.order_id
      )
);
