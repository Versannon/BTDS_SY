SELECT
    item_name,
    unit_price,
    quantity,
    unit_price * quantity AS total_amount
FROM sales_data;
