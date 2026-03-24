SELECT
    item_name,
    (unit_price * quantity) / quantity AS price_per_unit
FROM sales_data;
