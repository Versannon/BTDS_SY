SELECT
    item_name,
    quantity,
    MOD(quantity, 2) AS remainder_value
FROM sales_data;
